//--------------------------------------------------------------------------------------
// File: D3D12CommandListPool.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#if GTI_PROJECT
#include "Utilities/Windows/CComPtr.h"
#include <d3d12.h>
#include <dxgi1_6.h>
#else
#include <atlbase.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#endif

#include "ID3D12CommandListPool.h"

using WaitForSingleObjectFcn = decltype(&::WaitForSingleObject);

// Input / output info of command list wait information
struct CommandListWaitingInfo
{
    CommandListWaitingInfo()
        : isLongWait(false)
        , isTimeout(false)
    {
    }

    bool isLongWait; // [in] Need longer timeout for some specific operations like SASS Patching
    bool isTimeout; // [out] Finally timeout or not
};

// CommandListPool- a utility that we can use for various purposes where we need to inject our own CL.
struct D3D12CommandListPool final : public ID3D12CommandListPool
{
    // Default timeout for wait once
    const static uint32_t DEFAULT_TIMEOUT = 8000;

    // If we are waiting commands finish for over 10 minutes that's worth to raise an error.
    // Some operation like sass patching may take longer time than the DEFAULT_TIMEOUT to finish.
    const static uint32_t DEFAULT_TIMEOUT_ERROR_MILLISECONDS = 10 * 60 * 1000;

    D3D12CommandListPool(WaitForSingleObjectFcn waitForSingleObject, ID3D12Device& device, ID3D12CommandQueue& queue, UINT nodeMask, uint32_t timeoutMillisecs = DEFAULT_TIMEOUT);
    D3D12CommandListPool(WaitForSingleObjectFcn waitForSingleObject, ID3D12Device& device, IDXGISwapChain3& pSwapchain, std::vector<ID3D12CommandQueue*> queues, UINT nodeMask, uint32_t timeoutMillisecs = DEFAULT_TIMEOUT);

    void SetCurrentFrameQueue(ID3D12CommandQueue& newQueue);
    ID3D12CommandQueue& GetCurrentFrameQueue() const;

    // AllocList: allocate a list that is still "owned" by CommandListPool,
    // so the caller should not release this pointer
    // @param InitialPSO may be nullptr.
    ID3D12GraphicsCommandList* AllocList(ID3D12PipelineState* pInitialPSO);
    ID3D12GraphicsCommandList* AllocList(ID3D12PipelineState* pInitialPSO, CommandListIndex& outIndex) override;

    // Execute the list previously returned by AllocList.  The pool then reclaims
    // the list, so if the caller want to issue more commands they should request
    // another list.  It is not safe to reuse the old list, although it will
    // persist as an object until the smart pointer is destroyed.
    // Returns whether the list is successfully closed and executed.
    bool CloseAndExecute(ID3D12GraphicsCommandList* pCommandList) override;

    // Return whether this list has already completed (does not wait)
    bool IsListDone(const CommandListIndex& index) const override;

    // Wait for all pending lists in this pool to finish.
    void FinishAll() override;
    void FinishAllWithInfiniteWait(CommandListWaitingInfo* pInfo = nullptr);

    // Synchronize with the external queue
    void WaitForQueue(ID3D12CommandQueue& queue);
    void QueueWaitForPool(ID3D12CommandQueue& queue);

    struct CommandListInfo
    {
        CommandListInfo(
            com_unique_ptr<ID3D12GraphicsCommandList>&& spCommandList,
            com_unique_ptr<ID3D12CommandAllocator>&& spAllocator,
            com_unique_ptr<ID3D12Fence>&& spFence,
            HANDLE completionEvent,
            UINT64 fenceValue,
            uint64_t index);

        CommandListInfo& operator=(CommandListInfo&& rh) = default;
        CommandListInfo(CommandListInfo&& rh) = default;

        enum class FinishResult
        {
            Unfinished_WaitFailed,
            Unfinished_WaitTimedOut,
            Finished_NeverClosed,
            Finished_EarlyExit,
            Finished_ByWait,
        };
        static bool IsFinishResultFinished(FinishResult result);

        bool IsDone(WaitForSingleObjectFcn waitForSingleObject) const;
        FinishResult Finish(WaitForSingleObjectFcn waitForSingleObject, uint32_t timeoutMillisecs) const;
        bool HasFailedTracking() const;

        com_unique_ptr<ID3D12GraphicsCommandList> m_spCommandList;
        com_unique_ptr<ID3D12CommandAllocator> m_spAllocator;
        com_unique_ptr<ID3D12Fence> m_spFence;
        HANDLE m_waitEvent;
        UINT64 m_lastSubmittedValue;
        uint64_t m_index; // The global index of issued commandlists.
        enum class CloseAndExecuteState
        {
            Unclosed, // The list hasn't been closed yet
            FailedTracking, // The list was closed, but tracking facilities failed
            Closed // The list is closed and tracking facilities are available
        };
        CloseAndExecuteState m_closeAndExecuteState; // whether this list failed its last close
    };

private:
    void QueueWaitHelper(ID3D12CommandQueue& queue, bool thisWaits);

    WaitForSingleObjectFcn m_waitForSingleObject;
    ID3D12Device& m_device;
    IDXGISwapChain3* m_pOptionalSwapchain;
    std::vector<ID3D12CommandQueue*> m_queues;

    com_unique_ptr<ID3D12Fence> m_spGlobalFence;
    UINT64 m_globalFenceValue;

    std::vector<CommandListInfo> m_openCommandLists;
    std::vector<CommandListInfo> m_submittedCommandLists;
    UINT64 m_nextFenceValue;
    uint64_t m_currentCommandListIndex;
    UINT m_nodeMask;
    uint32_t m_timeoutMillisecs;
};

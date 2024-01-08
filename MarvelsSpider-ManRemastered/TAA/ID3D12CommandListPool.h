//--------------------------------------------------------------------------------------
// File: D3D12CommandListPool.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include <cstdint>
#include <vector>

#include <d3d12.h>
#include <dxgi.h>

#if GTI_PROJECT
#include <CommonGraphics/SafeCleanup.h>
#include <d3d12.h>
#include <dxgi.h>
#else
#include <memory>

//--------------------------------------------------------------------------------------
// com_unique_ptr - std::unique_ptr wrapper for IUnknown
//--------------------------------------------------------------------------------------
template <typename T_IComType>
struct release_com_type
{
    void operator()(T_IComType* pObj) const
    {
        if (pObj)
        {
            pObj->Release();
        }
    }
};

template <typename T_IComType>
using com_unique_ptr = std::unique_ptr<T_IComType, release_com_type<T_IComType>>;
#endif

// CommandListPool- a utility that we can use for various purposes where we need to inject our own CL.
struct ID3D12CommandListPool
{
    virtual ~ID3D12CommandListPool() = default;

    struct CommandListIndex
    {
        uint64_t value;

        bool operator==(const CommandListIndex& rh) const
        {
            return value == rh.value;
        }
    };

    static const CommandListIndex CommandListIndex_Invalid;

    virtual ID3D12GraphicsCommandList* AllocList(ID3D12PipelineState* pInitialPSO, CommandListIndex& outIndex) = 0;

    // Execute the list previously returned by AllocList.  The pool then reclaims
    // the list, so if the caller want to issue more commands they should request
    // another list.  It is not safe to reuse the old list, although it will
    // persist as an object until the smart pointer is destroyed.
    // Returns whether the list is successfully closed and executed.
    virtual bool CloseAndExecute(ID3D12GraphicsCommandList* pCommandList) = 0;

    // Return whether this list has already completed (does not wait)
    virtual bool IsListDone(const CommandListIndex& index) const = 0;

    // Wait for all pending lists in this pool to finish.
    virtual void FinishAll() = 0;
};
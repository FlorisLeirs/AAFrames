#pragma once
#include "function_overrides.h"

#include "D3D12ReplayTypes.h"
#include <d3d12.h>

#if (defined(NTDDI_WIN10_VB) && NTDDI_VERSION >= NTDDI_WIN10_VB)
#include "d3dx12_19041.h"
#elif (defined(NTDDI_WIN10_RS2) && NTDDI_VERSION > NTDDI_WIN10_RS2)
#include "d3dx12_16299.h"
#else
#include "d3dx12_15063.h"
#endif

#if (defined(NTDDI_WIN10_RS5) && NTDDI_VERSION >= NTDDI_WIN10_RS5)
#include "D3D12Replay_17763.h"
#include "MetaCommandDefinitions.h"
#endif

#include <atlbase.h>
#include <cstdint>
#include <future>
#include <vector>

#include "CommonReplay.h"
#include "D3D12TiledResourceCopier.h"
#include "ReadOnlyDatabase.h"

using CommandListBuildFunction = void (*)();

struct IDXGISwapChain3;

extern bool s_useAuxResetQueue;
extern bool s_useFrameEndSync;
extern bool s_d3d12NoReplacementRTAS;
extern bool s_forceVidmemSBT;
extern int s_screenshotCaptureFrameIndex;

enum class D3D12ReplayPhase
{
    MandatoryInit, // Resources are being populated with their initial data.  This is required to be reset with each frame iteration.
    OptionalInit, // Resources are being populated with their initial data
    Frame, // Frame replay
};

enum class FenceSyncType
{
    SIGNAL_LANDED, // User called Signal which later landed
    GET_COMPLETED_VALUE, // User called GetCompletedValue
    SET_EVENT_ON_COMPLETION_LANDED, // User is possibly waiting for this event which has landed
    WAIT_LANDED, // A wait corresponding to SetEventOnCompletion has landed

    COUNT
};

struct BarrierStates
{
    BarrierStates(D3D12_RESOURCE_STATES legacy)
        : isEnhanced(false)
        , legacyBarrier(legacy)
    {
    }

    BarrierStates(D3D12_BARRIER_LAYOUT enhanced)
        : isEnhanced(true)
        , layout(enhanced)
    {
    }

    bool isEnhanced;

    union
    {
        D3D12_RESOURCE_STATES legacyBarrier;
        D3D12_BARRIER_LAYOUT layout;
    };
};

namespace Serialization {
struct DATABASE_HANDLE;
};

struct D3D12Chunk
{
    uint32_t id;
    Serialization::DATABASE_HANDLE hData;
    uint32_t subchunkMask = ~0u;
};

template <typename T, size_t N>
std::vector<T> D3D12Vector(const T (&cArray)[N])
{
    return { cArray, cArray + N };
}

struct D3D12CommandListInfo;

// Begin internal functions
D3D12CommandListInfo& GetD3D12CommandListInfo(const NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& pCommandList, D3D12ReplayPhase originalPhase);
D3D12CommandListInfo& GetD3D12CommandListInfo(const NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& pCommandList);

enum D3D12CommandListBuildFlags
{
    D3D12CommandListBuildFlag_None = 0x0,
    D3D12CommandListBuildFlag_HasExecuteBundle = 0x1,
};

void D3D12Replay_INTERNAL_CommandList_Build(
    D3D12ReplayPhase thisPhase, // The phase we are now executing
    D3D12CommandListInfo& commandListInfo,
    CommandListBuildFunction fcn,
    const NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& pCommandList,
    const NVD3D12MultiBufferedArray<ID3D12CommandAllocator>& pAllocator,
    ID3D12PipelineState* pPipelineState,
    D3D12CommandListBuildFlags flags);

ID3D12CommandList* D3D12Replay_WaitForCommandList(const NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& pCommandList);

//--------------------------------------------------------------------------------------
// D3D12 knobs to be called by function override experiments
//--------------------------------------------------------------------------------------

// D3D12_Knob_SetRebuildAllCommandLists
// If enabled, this will force the rebuild of all commandlists with every frame.
// If enabled, this overrides the setting for individual commandlists.
void D3D12Replay_Knob_SetRebuildAllCommandLists(bool rebuild);

// D3D12_Knob_SetRebuildAllCommandLists
// If enabled, this will force the rebuild of a single commandlist with every frame.
void D3D12Replay_Knob_SetRebuildCommandList(const NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& pCommandList, bool rebuild);

// D3D12_Knob_SetBuildPhase
// Controls when an individual commandlist is built.  Commandlists built during the frame replay
// may be overridden to build during init/reset instead.
void D3D12Replay_Knob_SetBuildPhase(const NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& pCommandList, D3D12ReplayPhase phase);

// CPU work batches
struct D3D12MapInfo
{
    const NVD3D12MultiBufferedArray<ID3D12Resource>* pResource;
    UINT subresource;
    std::unique_ptr<D3D12_RANGE> spRange;
};

struct D3D12SyncInfo
{
    const NVD3D12MultiBufferedArray<ID3D12Fence>* pFence;
    UINT64 completedValue;
    UINT64 lastSubmittedValue;
    const char* id;
    FenceSyncType type;
};

struct D3D12BufferDifferenceInfo
{
    const NVD3D12MultiBufferedArray<ID3D12Resource>* pResource;
    Serialization::DATABASE_HANDLE databaseId;
    size_t size;
    size_t offset;
};

struct D3D12CpuWorkBatchEvent
{
    enum Type
    {
        MAP,
        UNMAP,
        SYNC,
        DIFF
    };

    D3D12CpuWorkBatchEvent(Type mapOrUnmapType, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, UINT subresource, std::unique_ptr<D3D12_RANGE>&& spRange)
        : type(mapOrUnmapType)
        , mapOrUnmap{ &pResource, subresource, std::move(spRange) }
    {
    }

    D3D12CpuWorkBatchEvent(const NVD3D12MultiBufferedArray<ID3D12Fence>& pFence, UINT64 completedValue, UINT64 lastSubmittedValue, const char* id, FenceSyncType type)
        : type(SYNC)
        , sync{ &pFence, completedValue, lastSubmittedValue, id, type }
    {
    }

    D3D12CpuWorkBatchEvent(const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, Serialization::DATABASE_HANDLE databaseId, size_t size, size_t offset)
        : type(DIFF)
        , diff{ &pResource, databaseId, size, offset }
    {
    }

    Type type;
    D3D12MapInfo mapOrUnmap;
    D3D12SyncInfo sync;
    D3D12BufferDifferenceInfo diff;
};

void D3D12BeginCpuWorkBatch(const D3D12CpuWorkBatchEvent* pEvents, size_t eventCount, std::future<void>& future);

void D3D12EndCpuWorkBatch(std::future<void>& future);

void D3D12InitMappedPointers(const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const void* pData, size_t size);

HRESULT D3D12Map(const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, UINT subresource, const D3D12_RANGE* pRange, bool isInit);

void D3D12Unmap(const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, UINT subresource, const D3D12_RANGE* pRange, bool isInit);

void D3D12ExecuteCommandLists(ID3D12CommandQueue* pQueue, UINT NumCommandLists, ID3D12CommandList** ppCommandLists);

// Return whether replay creates a spoofed backbuffer, or can use the real swapchain directly
bool D3D12Replay_NeedSpoofedBackbuffer();

// Descriptor heap registration
void D3D12RegisterDescriptorHeap(ID3D12DescriptorHeap* pHeap, uint64_t id);

// Binary representation of D3D12 descriptor handle
struct D3D12SerializedDescriptorHandle
{
    uint32_t heapID;
    uint32_t offset;
};

// Translate captured handles to current process
std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> D3D12InitCpuDescriptorHandles(ID3D12Device* pDevice, const D3D12SerializedDescriptorHandle*, int count);

// Get the current index for multibuffered device children
int D3D12GetMultibufferedIndex();

// Get the current instance count for multibuffered device children
int D3D12GetMultibufferedCount();
bool D3D12MultibufferResourcesAndHeaps();

// Record the current value and wait for the value NV_D3D12_REPLAY_MULTIBUFFER_COUNT frames ago
void D3D12AdvanceMultibufferedIndex();

// Initialize contents of update heap
void D3D12InitUploadHeap(NVD3D12MultiBufferedArray<ID3D12Heap>& heap, std::vector<D3D12Chunk> chunkIDs, NVD3D12MultiBufferedArray<ID3D12Resource>& placedResource, ID3D12CommandQueue* pQueue, ID3D12Fence* pFence, UINT64& fenceValue, ID3D12GraphicsCommandList* pCommandList, ID3D12CommandAllocator* pAllocator);
void D3D12ResetUploadHeap(NVD3D12MultiBufferedArray<ID3D12Heap>& heap, std::vector<D3D12Chunk> resetChunkIDs, NVD3D12MultiBufferedArray<ID3D12Resource>& placedResource, ID3D12CommandQueue* pQueue, ID3D12Fence* pFence, UINT64& fenceValue, ID3D12GraphicsCommandList* pCommandList, ID3D12CommandAllocator* pAllocator, bool isAsync);

// Initialize contents of default heap
void D3D12InitDefaultHeap(
    NVD3D12MultiBufferedArray<ID3D12Heap>& heap,
    std::vector<D3D12Chunk> initChunkIDs,
    std::vector<D3D12Chunk> resetChunkIDs,
    NVD3D12MultiBufferedArray<ID3D12Resource>& placedResource,
    ID3D12Resource** ppVidmemClone,
    ID3D12Device* pDevice,
    ID3D12CommandQueue* pQueue,
    ID3D12Fence* pFence,
    UINT64& fenceValue,
    ID3D12GraphicsCommandList* pInitCommandList,
    NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& resetDataCommandLists,
    ID3D12CommandAllocator* pInitAllocator);

// Synchronization helpers
void D3D12Finish(ID3D12CommandQueue* pQueue, ID3D12Fence* pFence, uint64_t& value);
void D3D12QueueWait(ID3D12CommandQueue* pSignalingQueue, ID3D12Fence* pFence, uint64_t& value);
void WaitForFenceBatched(ID3D12Fence* pFence, uint64_t value, uint64_t lastSignaledValue, const char* pFunction, FenceSyncType syncType);
void WaitForFenceNoCheck(ID3D12Fence* pFence, uint64_t value, const char* pFunction);

// MakeResident/Evict support
HRESULT D3D12MakeResident(ID3D12Device* pThis, uint32_t NumObjects, ID3D12Pageable* const* ppObjects);
HRESULT D3D12Evict(ID3D12Device* pThis, uint32_t NumObjects, ID3D12Pageable* const* ppObjects);
HRESULT D3D12EnqueueMakeResident(ID3D12Device3* pThis, uint32_t Flags, uint32_t NumObjects, ID3D12Pageable* const* ppObjects, ID3D12Fence* pFenceToSignal, uint64_t FenceValueToSignal);

// Init temp object release support
void D3D12EnqueueInitObjectForRelease(ID3D12Resource** ppObject);
void D3D12ReleaseInitObjects();

struct D3D12InitInfo
{
    D3D12DescriptorHeapStrides descriptorHeapStrides;
    D3D12DescriptorHeapSizes totalGPUVisibleDescriptors;
    ID3D12Device* pDevice;
    ID3D12CommandQueue* pQueue;
    ID3D12Fence* pFence;
    UINT64* pFenceValue;
    ID3D12CommandAllocator* pAllocator;
    ID3D12GraphicsCommandList* pCommandList;
};

// Restart the worker commandlist and optionally release pending resources
void D3D12ResetCommandList(ID3D12CommandQueue* pQueue, ID3D12Fence* pFence, UINT64& fenceValue, ID3D12CommandAllocator* pAllocator, ID3D12GraphicsCommandList* pCommandList, bool releaseResources);
void D3D12ResetCommandList(const D3D12InitInfo& initInfo, bool releaseResources);

// Release the resource streamer
void D3D12ReleaseInitStreamer();
void D3D12OnShutdown();

void SetD3D12InitInfo(ID3D12Device* pDevice, D3D12DescriptorHeapStrides& descriptorHeapStrides, D3D12DescriptorHeapSizes totalGPUVisibleDescriptors, ID3D12CommandQueue* pQueue, ID3D12Fence* pFence, UINT64* pFenceValue, ID3D12CommandAllocator* pAllocator, ID3D12GraphicsCommandList* pCommandList);
D3D12InitInfo GetD3D12InitInfo();

enum class D3D12QueueFlags
{
    NONE = 0x0,
    BLOCKED_AT_CAPTURE_END = 0x1,
};
void D3D12RegisterCommandQueue(ID3D12CommandQueue* pQueue, D3D12QueueFlags);

//-----------------------------------------------------------------------------
// OffsetCPUDescriptor
//-----------------------------------------------------------------------------
inline D3D12_CPU_DESCRIPTOR_HANDLE OffsetCPUDescriptor(UINT descriptorOffset, const D3D12MultibufferedCpuHandle& hHeapStart, UINT incrementSize)
{
    return CD3DX12_CPU_DESCRIPTOR_HANDLE(hHeapStart.GetCheckedElement(D3D12GetMultibufferedIndex()), descriptorOffset, incrementSize);
}

//-----------------------------------------------------------------------------
// OffsetGPUDescriptor
//-----------------------------------------------------------------------------
inline D3D12_GPU_DESCRIPTOR_HANDLE OffsetGPUDescriptor(UINT descriptorOffset, const D3D12MultibufferedGpuHandle& hHeapStart, UINT incrementSize)
{
    return CD3DX12_GPU_DESCRIPTOR_HANDLE(hHeapStart.GetCheckedElement(D3D12GetMultibufferedIndex()), descriptorOffset, incrementSize);
}

void D3D12OnPresent(IDXGISwapChain3* pSwapChain, ID3D12Resource* pOffscreenSurface, ID3D12Device* pDevice, ID3D12CommandQueue* pQueue, std::vector<CComPtr<ID3D12GraphicsCommandList>>& commandListVector, std::vector<CComPtr<ID3D12CommandAllocator>>& allocatorVector);

void D3D12TransitionState(NVD3D12MultiBufferedArray<ID3D12Resource> resources, ID3D12GraphicsCommandList* pInitCommandList, UINT subresourceCount, const BarrierStates* pInitStates, const BarrierStates* pFrameBeginStates);

void D3D12InitResourceData(
    ID3D12Device* pDevice,
    ID3D12CommandQueue* pQueue,
    ID3D12GraphicsCommandList* pInitCommandList,
    ID3D12CommandAllocator* pInitAllocator,
    ID3D12Fence* pFence,
    UINT64& fenceValue,
    NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList> resetDataCommandLists,
    NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList> resetStateCommandLists,
    NVD3D12MultiBufferedArray<ID3D12Resource> pResource,
    ID3D12Resource** ppVidmemClone,
    UINT subresourceCount,
    std::vector<D3D12Chunk> initChunks,
    std::vector<D3D12Chunk> resetChunks,
    const BarrierStates* pFrameBeginStates,
    const BarrierStates* pFrameEndStates,
    ID3D12Heap* pHeap);

void D3D12ResetBufferData(NVD3D12MultiBufferedArray<ID3D12Resource> pResource, Serialization::DATABASE_HANDLE hData, uint64_t destinationOffset, uint64_t size, NVCheckedMemcpyState& state, bool isAsync);

void D3D12InitTiledResourceData(ID3D12Device* pDevice, ID3D12CommandQueue* pQueue, D3D12TiledResourceCopier& copier, ID3D12GraphicsCommandList* pInitCommandList, NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& resetDataCommandLists, NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& resetStateCommandLists, NVD3D12MultiBufferedArray<ID3D12Resource> pResource, ID3D12Resource* pDataBuffer, UINT tileMappingsCount, const D3D12TiledResourceCopier::TileMapping* pTileMappings, UINT subresourceCount, const BarrierStates* pFrameBeginStates, const BarrierStates* pFrameEndStates);

D3D12_RESOURCE_BARRIER D3D12TransitionBarrier(ID3D12Resource* pResource, D3D12_RESOURCE_STATES beforeState, D3D12_RESOURCE_STATES afterState, UINT subresource);

// Apply D3D12-external data (from another API or even process)
void D3D12ApplyExternalData(ID3D12CommandQueue* pQueue, ID3D12Resource* pResource, const D3D12Chunk* pChunks, size_t chunkCount);
void D3D12ApplyExternalData(ID3D12CommandQueue* pQueue, ID3D12Heap* pHeap, NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const D3D12Chunk* pChunks, size_t chunkCount);

//-----------------------------------------------------------------------------
// D3D12 SRV helpers
//-----------------------------------------------------------------------------
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVBuffer(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT64 firstElement, UINT numElements, UINT stuctureByteStride, D3D12_BUFFER_SRV_FLAGS flags);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTexture1D(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT mostDetailedMip, UINT mipLevels, FLOAT resourceMinLODClamp);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTexture1DArray(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT mostDetailedMip, UINT mipLevels, UINT firstArraySlice, UINT arraySize, FLOAT resourceMinLODClamp);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTexture2D(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT mostDetailedMip, UINT mipLevels, UINT planeSlice, FLOAT resourceMinLODClamp);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTexture2DArray(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT mostDetailedMip, UINT mipLevels, UINT firstArraySlice, UINT arraySize, UINT planeSlice, FLOAT resourceMinLODClamp);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTexture2DMS(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTexture2DMSArray(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT firstArraySlice, UINT arraySize);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTexture3D(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT mostDetailedMip, UINT mipLevels, FLOAT resourceMinLODClamp);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTextureCube(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT mostDetailedMip, UINT mipLevels, FLOAT resourceMinLODClamp);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVTextureCubeArray(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, UINT mostDetailedMip, UINT mipLevels, UINT first2DArrayFace, UINT numCubes, FLOAT resourceMinLODClamp);

//-----------------------------------------------------------------------------
// D3D12 UAV helpers
//-----------------------------------------------------------------------------
D3D12_UNORDERED_ACCESS_VIEW_DESC* D3D12InitUAVBuffer(D3D12_UNORDERED_ACCESS_VIEW_DESC& desc, DXGI_FORMAT format, UINT64 firstElement, UINT numElements, UINT stuctureByteStride, UINT64 counterOffsetInBytes, D3D12_BUFFER_UAV_FLAGS flags);
D3D12_UNORDERED_ACCESS_VIEW_DESC* D3D12InitUAVTexture1D(D3D12_UNORDERED_ACCESS_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice);
D3D12_UNORDERED_ACCESS_VIEW_DESC* D3D12InitUAVTexture1DArray(D3D12_UNORDERED_ACCESS_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstArraySlice, UINT arraySize);
D3D12_UNORDERED_ACCESS_VIEW_DESC* D3D12InitUAVTexture2D(D3D12_UNORDERED_ACCESS_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT planeSlice);
D3D12_UNORDERED_ACCESS_VIEW_DESC* D3D12InitUAVTexture2DArray(D3D12_UNORDERED_ACCESS_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstArraySlice, UINT arraySize, UINT planeSlice);
D3D12_UNORDERED_ACCESS_VIEW_DESC* D3D12InitUAVTexture3D(D3D12_UNORDERED_ACCESS_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstWSlice, UINT wSize);

//-----------------------------------------------------------------------------
// D3D12 RTV helpers
//-----------------------------------------------------------------------------
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVBuffer(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format, UINT64 firstElement, UINT numElements);
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVTexture1D(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice);
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVTexture1DArray(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstArraySlice, UINT arraySize);
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVTexture2D(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT planeSlice);
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVTexture2DArray(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstArraySlice, UINT arraySize, UINT planeSlice);
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVTexture2DMS(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format);
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVTexture2DMSArray(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format, UINT firstArraySlice, UINT arraySize);
D3D12_RENDER_TARGET_VIEW_DESC* D3D12InitRTVTexture3D(D3D12_RENDER_TARGET_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstWSlice, UINT wSize);

//-----------------------------------------------------------------------------
// D3D12 DSV helpers
//-----------------------------------------------------------------------------
D3D12_DEPTH_STENCIL_VIEW_DESC* D3D12InitDSVTexture1D(D3D12_DEPTH_STENCIL_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice);
D3D12_DEPTH_STENCIL_VIEW_DESC* D3D12InitDSVTexture1DArray(D3D12_DEPTH_STENCIL_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstArraySlice, UINT arraySize);
D3D12_DEPTH_STENCIL_VIEW_DESC* D3D12InitDSVTexture2D(D3D12_DEPTH_STENCIL_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice);
D3D12_DEPTH_STENCIL_VIEW_DESC* D3D12InitDSVTexture2DArray(D3D12_DEPTH_STENCIL_VIEW_DESC& desc, DXGI_FORMAT format, UINT mipSlice, UINT firstArraySlice, UINT arraySize);
D3D12_DEPTH_STENCIL_VIEW_DESC* D3D12InitDSVTexture2DMS(D3D12_DEPTH_STENCIL_VIEW_DESC& desc, DXGI_FORMAT format);
D3D12_DEPTH_STENCIL_VIEW_DESC* D3D12InitDSVTexture2DMSArray(D3D12_DEPTH_STENCIL_VIEW_DESC& desc, DXGI_FORMAT format, UINT firstArraySlice, UINT arraySize);

//-----------------------------------------------------------------------------
// D3D12 CBV helpers
//-----------------------------------------------------------------------------
D3D12_CONSTANT_BUFFER_VIEW_DESC* D3D12InitCBVDesc(D3D12_CONSTANT_BUFFER_VIEW_DESC& desc, D3D12_GPU_VIRTUAL_ADDRESS bufferLocation, UINT sizeInBytes);

//-----------------------------------------------------------------------------
// D3D12 Sampler helpers
//-----------------------------------------------------------------------------
D3D12_SAMPLER_DESC* D3D12InitSamplerDesc(D3D12_SAMPLER_DESC& desc, D3D12_FILTER filter, D3D12_TEXTURE_ADDRESS_MODE addressU, D3D12_TEXTURE_ADDRESS_MODE addressV, D3D12_TEXTURE_ADDRESS_MODE addressW, FLOAT mipLODBias, UINT maxAnisotropy, D3D12_COMPARISON_FUNC comparisonFunc, FLOAT borderColor[4], FLOAT minLOD, FLOAT maxLOD);
D3D12_SAMPLER_DESC2 D3D12InitSamplerDesc2(D3D12_FILTER filter, D3D12_TEXTURE_ADDRESS_MODE addressU, D3D12_TEXTURE_ADDRESS_MODE addressV, D3D12_TEXTURE_ADDRESS_MODE addressW, FLOAT mipLODBias, UINT maxAnisotropy, D3D12_COMPARISON_FUNC comparisonFunc, UINT borderColor[4], FLOAT minLOD, FLOAT maxLOD);

//-----------------------------------------------------------------------------
// D3D12 Device creation
//-----------------------------------------------------------------------------
HRESULT D3D12CreateIndependentDevice(IUnknown* pAdapter, D3D_FEATURE_LEVEL featureLevel, UINT numExperimentalFeatures, const IID* pExperimentalFeatures, UINT* pExperimentalFeatureDataSizes, void* pExperimentalFeatureData, D3D12_DEVICE_FACTORY_FLAGS factoryFlags, const IID& iid, void** ppDevice);

//-----------------------------------------------------------------------------
// D3D12 Descriptor creation
//-----------------------------------------------------------------------------
void D3D12CreateConstantBufferView(ID3D12Device* pDevice, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, UINT64 offset, UINT size, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);
void D3D12CreateShaderResourceView(ID3D12Device* pDevice, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);
void D3D12CreateUnorderedAccessView(ID3D12Device* pDevice, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const NVD3D12MultiBufferedArray<ID3D12Resource>& pCounterResource, const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);
void D3D12CreateSamplerFeedbackUnorderedAccessView(ID3D12Device* pDevice, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const NVD3D12MultiBufferedArray<ID3D12Resource>& pFeedbackResource, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);
void D3D12CreateRenderTargetView(ID3D12Device* pDevice, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const D3D12_RENDER_TARGET_VIEW_DESC* pDesc, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);
void D3D12CreateRenderTargetViewForSwapchain(ID3D12Device* pDevice, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const D3D12_RENDER_TARGET_VIEW_DESC* pDesc, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);
void D3D12CreateDepthStencilView(ID3D12Device* pDevice, const NVD3D12MultiBufferedArray<ID3D12Resource>& pResource, const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);
void D3D12CreateSampler(ID3D12Device* pDevice, const D3D12_SAMPLER_DESC* pDesc, D3D12MultibufferedCpuHandle hHeapStart, UINT descriptorOffset);

//-----------------------------------------------------------------------------
// D3D12 Multibuffering policy
//-----------------------------------------------------------------------------
bool D3D12ShouldMultibuffer(const D3D12_HEAP_PROPERTIES& heapProperties, bool hasRevisions);
bool D3D12ShouldMultibuffer(const D3D12_HEAP_PROPERTIES& heapProperties, const D3D12_RESOURCE_DESC& resourceDesc, bool hasRevisions);
bool D3D12ShouldMultibuffer(const D3D12_RESOURCE_DESC& resourceDesc, bool hasRevisions);

//-----------------------------------------------------------------------------
// D3D12 Resource creation
//-----------------------------------------------------------------------------
HRESULT D3D12CreateCommittedResource(ID3D12Device* pDevice, const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS heapFlags, const D3D12_RESOURCE_DESC1* pResourceDesc, D3D12_RESOURCE_STATES initialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, const IID& riid, NVD3D12MultiBufferedArray<ID3D12Resource>& resource, const wchar_t* name, bool hasRevisions);
HRESULT D3D12CreateCommittedResource(ID3D12Device* pDevice, const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS heapFlags, const D3D12_RESOURCE_DESC1* pResourceDesc, D3D12_BARRIER_LAYOUT initialLayout, UINT numCastableFormats, const DXGI_FORMAT* pCastableFormats, const D3D12_CLEAR_VALUE* pOptimizedClearValue, const IID& riid, NVD3D12MultiBufferedArray<ID3D12Resource>& resource, const wchar_t* name, bool hasRevisions);
HRESULT D3D12CreatePlacedResource(ID3D12Device* pDevice, NVD3D12MultiBufferedArray<ID3D12Heap>& heap, UINT64 offset, const D3D12_RESOURCE_DESC1* pResourceDesc, D3D12_RESOURCE_STATES initialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, const IID& riid, NVD3D12MultiBufferedArray<ID3D12Resource>& resource, const wchar_t* name, bool hasRevisions);
HRESULT D3D12CreatePlacedResource(ID3D12Device* pDevice, NVD3D12MultiBufferedArray<ID3D12Heap>& heap, UINT64 offset, const D3D12_RESOURCE_DESC1* pResourceDesc, D3D12_BARRIER_LAYOUT initialLayout, UINT numCastableFormats, const DXGI_FORMAT* pCastableFormats, const D3D12_CLEAR_VALUE* pOptimizedClearValue, const IID& riid, NVD3D12MultiBufferedArray<ID3D12Resource>& resource, const wchar_t* name, bool hasRevisions);
HRESULT D3D12CreateReservedResource(ID3D12Device* pDevice, const D3D12_RESOURCE_DESC* pResourceDesc, D3D12_RESOURCE_STATES initialState, const D3D12_CLEAR_VALUE* pOptimizedClearValue, const IID& riid, NVD3D12MultiBufferedArray<ID3D12Resource>& resource, const wchar_t* name, bool hasRevisions);
HRESULT D3D12CreateReservedResource(ID3D12Device* pDevice, const D3D12_RESOURCE_DESC* pResourceDesc, D3D12_BARRIER_LAYOUT initialLayout, UINT numCastableFormats, const DXGI_FORMAT* pCastableFormats, const D3D12_CLEAR_VALUE* pOptimizedClearValue, const IID& riid, NVD3D12MultiBufferedArray<ID3D12Resource>& resource, const wchar_t* name, bool hasRevisions);
HRESULT D3D12CreateDescriptorHeap(ID3D12Device* pDevice, const D3D12_DESCRIPTOR_HEAP_DESC* pDesc, NVD3D12MultiBufferedArray<ID3D12DescriptorHeap>& descriptorHeap, D3D12MultibufferedCpuHandle& cpuBegin, D3D12MultibufferedGpuHandle& gpuBegin, const wchar_t* name);

//-----------------------------------------------------------------------------
// D3D12GetHeapAddress- workaround for buggy applications that use a GPUVA outside the bounds of any placed buffer.
//-----------------------------------------------------------------------------
D3D12_GPU_VIRTUAL_ADDRESS D3D12GetHeapAddress(NVD3D12MultiBufferedArray<ID3D12Heap>& heap, UINT64 offset);

//-----------------------------------------------------------------------------
// DXRT helpers
//-----------------------------------------------------------------------------
#if (defined(NTDDI_WIN10_RS5) && NTDDI_VERSION >= NTDDI_WIN10_RS5)
D3D12_RAYTRACING_GEOMETRY_DESC D3D12InitGeomDescTri(D3D12_RAYTRACING_GEOMETRY_FLAGS flags, D3D12_GPU_VIRTUAL_ADDRESS transform, DXGI_FORMAT indexFormat, DXGI_FORMAT vertexFormat, UINT indexCount, UINT vertexCount, D3D12_GPU_VIRTUAL_ADDRESS indexBuffer, D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE vertexBuffer);
D3D12_RAYTRACING_GEOMETRY_DESC D3D12InitGeomDescAABB(D3D12_RAYTRACING_GEOMETRY_FLAGS flags, UINT64 aabbCount, D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE aabbs);
#if NV_CAPTURE_USES_NVAPI
NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX NVAPIInitGeomDescTri(D3D12_RAYTRACING_GEOMETRY_FLAGS flags, D3D12_GPU_VIRTUAL_ADDRESS transform, DXGI_FORMAT indexFormat, DXGI_FORMAT vertexFormat, UINT indexCount, UINT vertexCount, D3D12_GPU_VIRTUAL_ADDRESS indexBuffer, D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE vertexBuffer);
NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX NVAPIInitGeomDescAABB(D3D12_RAYTRACING_GEOMETRY_FLAGS flags, UINT64 aabbCount, D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE aabbs);
NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX NVAPIInitGeomDescOMMTriangles(D3D12_RAYTRACING_GEOMETRY_FLAGS flags, D3D12_GPU_VIRTUAL_ADDRESS transform, DXGI_FORMAT indexFormat, DXGI_FORMAT vertexFormat, UINT indexCount, UINT vertexCount, D3D12_GPU_VIRTUAL_ADDRESS indexBuffer, D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE vertexBuffer, D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE opacityMicromapIndexBuffer, DXGI_FORMAT opacityMicromapIndexFormat, UINT opacityMicromapBaseLocation, D3D12_GPU_VIRTUAL_ADDRESS opacityMicromapArray, UINT numOMMUsageCounts, const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT* pOMMUsageCounts);
#endif
void CreateAccelerationStructureBuffers(ID3D12Device* pDevice, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& desc, ID3D12Resource*& pDestination, ID3D12Resource*& pScratch, const wchar_t* name);
D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO ToPrebuildInfo(ID3D12Device* pDevice, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& desc);
void CreateAccelerationStructureBuffer(ID3D12Device* pDevice, ID3D12Resource*& pDestination, UINT64 size, D3D12_RESOURCE_STATES initialState, const wchar_t* name);
D3D12_SHADER_RESOURCE_VIEW_DESC* D3D12InitSRVAccelStruct(D3D12_SHADER_RESOURCE_VIEW_DESC& desc, DXGI_FORMAT format, UINT shader4ComponentMapping, D3D12_GPU_VIRTUAL_ADDRESS location);
#endif

//-----------------------------------------------------------------------------
// Write struct, and advance to the next element
//-----------------------------------------------------------------------------
template <typename T_Struct, typename T_Ptr>
void WriteAndIncrement(T_Ptr& inout, const T_Struct& value)
{
    BEGIN_DATA_SCOPE_FUNCTION();

    *(T_Struct*)inout = value;
    inout = T_Ptr((T_Struct*)inout + 1);
}

//-----------------------------------------------------------------------------
// Align value to explicit size
//-----------------------------------------------------------------------------
template <typename T_Ptr>
void AlignToSize(T_Ptr& inout, size_t alignment)
{
    BEGIN_DATA_SCOPE_FUNCTION();

    auto mask = alignment - 1;
    inout = (T_Ptr)((UINT_PTR(inout) + mask) & ~mask);
}

//-----------------------------------------------------------------------------
// Align value to struct size
//-----------------------------------------------------------------------------
template <typename T_AlignStruct, typename T_Ptr>
void AlignToStruct(T_Ptr& inout)
{
    BEGIN_DATA_SCOPE_FUNCTION();

    AlignToSize(inout, sizeof(T_AlignStruct));
}

//-----------------------------------------------------------------------------
// Align start to size of struct, write struct, and advance to the next element
//-----------------------------------------------------------------------------
template <typename T_AlignStruct, typename T_Ptr>
void AlignedWriteAndIncrement(T_Ptr& inout, const T_AlignStruct&& value)
{
    BEGIN_DATA_SCOPE_FUNCTION();

    AlignToStruct<T_AlignStruct>(inout);
    WriteAndIncrement(inout, value);
}

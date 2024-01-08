//--------------------------------------------------------------------------------------
// File: D3D12ResourceStreamer.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#if GTI_PROJECT
#include "API/D3D12/Resources/ID3D12CommandListPool.h"
#include <d3d12.h>
#else
#include "ID3D12CommandListPool.h"
#include <d3d12.h>
#include <vector>
#endif

#include <functional>
#include <memory>
#include <tuple>

struct ID3D12CommandListPool;

enum class D3D12ResourceStreamerStatus
{
    OK = 0,

    NOT_READY = -1,
    FAIL = -2,
    INVALID_ARG = -3,
};

inline bool Succeeded(D3D12ResourceStreamerStatus status)
{
    return status >= D3D12ResourceStreamerStatus::OK;
}

inline bool Failed(D3D12ResourceStreamerStatus status)
{
    return !Succeeded(status);
}

enum D3D12ResourceStreamerIDTag
{
    DO_NOT_USE
};
using D3D12ResourceStreamerID = std::tuple<uint64_t, D3D12ResourceStreamerIDTag>;
inline D3D12ResourceStreamerID MakeD3D12ResourceStreamerID(uint64_t val)
{
    return D3D12ResourceStreamerID{ val, DO_NOT_USE };
}
const D3D12ResourceStreamerID D3D12ResourceStreamerID_Invalid = MakeD3D12ResourceStreamerID(~0ull);

enum class D3D12ResourceStreamerOutputType
{
    CHUNKED,
    DEFAULT = CHUNKED,
    CONTIGUOUS,
    CONTIGUOUS_USER_POINTER,
};

enum class D3D12ResourceStreamerOptions
{
    NONE = 0x0,
    AUTO_MAKE_RESIDENT = 0x1,
};

// Allocator adaptor that interposes construct() calls to
// convert value initialization into default initialization.
// From: https://stackoverflow.com/a/21028912
template <typename T, typename A = std::allocator<T>>
class no_init_allocator : public A
{
    using a_t = std::allocator_traits<A>;

public:
    template <typename U>
    struct rebind
    {
        using other = no_init_allocator<
            U, typename a_t::template rebind_alloc<U>>;
    };

    using A::A;

    template <typename U>
    void construct(U* ptr) noexcept(std::is_nothrow_default_constructible<U>::value)
    {
        ::new (static_cast<void*>(ptr)) U;
    }
    template <typename U, typename... Args>
    void construct(U* ptr, Args&&... args)
    {
        a_t::construct(static_cast<A&>(*this),
            ptr, std::forward<Args>(args)...);
    }
};

class ID3D12ResourceStreamer
{
public:
    const static uint64_t MAX_SPAN_SIZE = ~0ull;

    using ChunkId = uint32_t;
    struct Chunk
    {
        ChunkId id;
        std::vector<uint8_t, no_init_allocator<uint8_t>> data;
    };
    using Data = std::vector<std::shared_ptr<Chunk>>;
    using ConstData = const Data&;

    using ConstBarriers = const std::vector<D3D12_RESOURCE_BARRIER>&;
    using ConstFootprints = const std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>&;

    // OnCompletedCallback:
    // Should return whether the data should be preserved by ID3D12ResourceStreamer.  Otherwise the data will be discarded
    using OnCompletedCallback = std::function<bool(ConstData data)>;

#if defined(_MSC_VER) && (_MSC_VER >= 1928)
    using ResourcePtr = com_unique_ptr<ID3D12Resource>;
#else
    using ResourcePtr = std::shared_ptr<ID3D12Resource>;
#endif

    // Give the user the option of providing allocation and deallocation functions
    using AllocD3D12BufferFn = std::function<ResourcePtr(ID3D12Device& device, const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC* pDesc, D3D12_RESOURCE_STATES InitialResourceState)>;
    using FreeD3D12BufferFn = std::function<void(ResourcePtr& spResource)>;

    ID3D12ResourceStreamer() = default;
    virtual ~ID3D12ResourceStreamer() = default;

    // Given resource data that was previously registered, return the binary (packed) data
    virtual ConstData GetDataFromBackingStore(const D3D12ResourceStreamerID id) = 0;

    // Return the packed size for a given resource
    virtual uint32_t GetChunkCount(ConstFootprints footprints, const D3D12_RESOURCE_DESC& desc, uint64_t offset = 0, uint64_t size = MAX_SPAN_SIZE) const = 0;
    virtual uint64_t GetSerializedSize(uint32_t chunkIndex, ConstFootprints footprints, const D3D12_RESOURCE_DESC& desc, uint64_t offset = 0, uint64_t size = MAX_SPAN_SIZE) const = 0;
    virtual uint64_t GetMaxChunkSizeForBuffers() const = 0;

    // Return whether any subresource is too large for a preallocated pool of buffers.  If so, the resource can be handled but at a performance cost.
    virtual bool IsTooLargeForPool(ConstFootprints footprints, UINT64 footprintTotalSize, const D3D12_RESOURCE_DESC& desc) const = 0;

    virtual D3D12ResourceStreamerStatus EnqueueBarriers(ConstBarriers barriers) = 0;

    virtual D3D12ResourceStreamerStatus Execute(std::function<void(ID3D12GraphicsCommandList&)>&& fcn) = 0;

    // Download from resource to backing store
    virtual D3D12ResourceStreamerID EnqueueDownload(ID3D12Resource& resource, ID3D12Heap* pOptionalBackingHeap, D3D12ResourceStreamerOptions options, OnCompletedCallback&& onDownloaded) = 0;

    // Download from resource to backing store
    // @param spanOffset must be 0 for textures.
    // @param spanSize must be MAX_SPAN_SIZE for textures.
    virtual D3D12ResourceStreamerID EnqueueDownload(ID3D12Resource& resource, ID3D12Heap* pOptionalBackingHeap, uint64_t spanOffset, uint64_t spanSize, D3D12ResourceStreamerOutputType outputType, D3D12ResourceStreamerOptions options, OnCompletedCallback&& onDownloaded, uint8_t* pUserPointer) = 0;

    // Upload from user data to resource, using the binary (packed) data.  Backing data will be discarded after operation.
    virtual D3D12ResourceStreamerStatus EnqueueUpload(ID3D12Resource& resource, ID3D12Heap* pOptionalBackingHeap, ConstData data, D3D12ResourceStreamerOptions options = D3D12ResourceStreamerOptions::NONE) = 0;

    // Remove the specified resource data from our tracking.
    virtual D3D12ResourceStreamerStatus Remove(const D3D12ResourceStreamerID id) = 0;

    // Submit work but do not wait
    virtual uint32_t CollectResultsAndReturnOutstandingOps() = 0;

    // Submit and wait for any pending GPU work.
    virtual D3D12ResourceStreamerStatus FinishQueuedWork() = 0;
};

using WaitForSingleObjectFcn = decltype(&::WaitForSingleObject);
std::unique_ptr<ID3D12ResourceStreamer> CreateD3D12ResourceStreamer(ID3D12Device& device, ID3D12CommandListPool& commandListPool, ID3D12ResourceStreamer::AllocD3D12BufferFn&& allocBufferFn = nullptr, ID3D12ResourceStreamer::FreeD3D12BufferFn&& freeBufferFn = nullptr);

// Include comparators for the data
bool operator==(const ID3D12ResourceStreamer::Chunk& lhs, const ID3D12ResourceStreamer::Chunk& rhs);
bool operator!=(const ID3D12ResourceStreamer::Chunk& lhs, const ID3D12ResourceStreamer::Chunk& rhs);
bool operator==(ID3D12ResourceStreamer::ConstData lhs, ID3D12ResourceStreamer::ConstData rhs);
bool operator!=(ID3D12ResourceStreamer::ConstData lhs, ID3D12ResourceStreamer::ConstData rhs);

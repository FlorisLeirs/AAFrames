//--------------------------------------------------------------------------------------
// File: D3D12TiledResourceCopier.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include <d3d12.h>

#if GTI_PROJECT
#include <Utilities/Windows/CComPtr.h>
#include <d3d12.h>
#else
#include <atlbase.h>
#endif

#include <utility>
#include <vector>

struct ID3D12Device;
struct ID3D12Heap;

class D3D12TiledResourceCopier
{
public:
    D3D12TiledResourceCopier(ID3D12Device& device, void* nvapiD3D12UpdateTileMappings);
    ~D3D12TiledResourceCopier();

    struct TileMapping
    {
        TileMapping()
            : pRealHeap(nullptr)
            , offset(0)
        {
        }

        TileMapping(ID3D12Heap* pHeap, UINT64 heapOffset)
            : pRealHeap(pHeap)
            , offset(heapOffset)
        {
        }

        ID3D12Heap* pRealHeap; // nullptr = null mapped
        UINT64 offset;
    };

    static std::pair<D3D12_TILED_RESOURCE_COORDINATE, bool> ConvertTileIndexToResourceCoordinate(
        const D3D12_RESOURCE_DESC& desc,
        UINT numTilesForEntireResource,
        UINT numStandardMipTiles,
        const std::vector<D3D12_SUBRESOURCE_TILING>& subresourceTilingsForStandardMips,
        UINT64 tileIndex);

    void ApplyMappingsToTiledResource(
        ID3D12CommandQueue& queue,
        ID3D12Resource& tiledResource,
        const std::vector<TileMapping>& tileMappings) const;

    // Query for buffer size to allocate
    UINT64 GetSerializedSize(
        ID3D12Resource& tiledResource,
        const std::vector<TileMapping>& tileMappings) const;

    // Caller is responsible for any necessary resource barriers
    bool DownloadFromTiledResource(
        ID3D12GraphicsCommandList& cmdList,
        ID3D12Resource& downloadDestination,
        ID3D12Resource& tiledSourceResource,
        const std::vector<TileMapping>& tileMappings) const;

    // Caller is responsible for any necessary resource barriers
    bool UploadToTiledResource(
        ID3D12GraphicsCommandList& cmdList,
        ID3D12Resource& tiledDestResource,
        const std::vector<TileMapping>& tileMappings,
        ID3D12Resource& uploadSource) const;

    template <size_t N>
    void ApplyMappingsToTiledResource(
        ID3D12CommandQueue& queue,
        ID3D12Resource& tiledResource,
        const TileMapping (&tileMappings)[N]) const
    {
        ApplyMappingsToTiledResource(queue, tiledResource, ToVector<N>(tileMappings));
    }

    template <size_t N>
    bool UploadToTiledResource(
        ID3D12GraphicsCommandList& cmdList,
        ID3D12Resource& tiledDestResource,
        const TileMapping (&tileMappings)[N],
        ID3D12Resource& uploadSource) const
    {
        return UploadToTiledResource(cmdList, tiledDestResource, ToVector<N>(tileMappings), uploadSource);
    }

    bool CanCreateResourceSpanningEntireHeap(const D3D12_HEAP_DESC& heapDesc) const;
    HRESULT CreateResourceSpanningEntireHeap(ID3D12Heap& heap, ID3D12CommandQueue& queue, D3D12_RESOURCE_STATES initialState, ID3D12Resource** ppResource);

    bool HasValidPackedMipData(const std::vector<TileMapping>& mappings, UINT numStandardMipTiles, UINT numTilesForEntireResource) const;

private:
    void UpdateTileMappings(
        ID3D12CommandQueue* pQueue,
        ID3D12Resource* pResource,
        UINT NumResourceRegions,
        const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
        const D3D12_TILE_REGION_SIZE* pResourceRegionSizes,
        ID3D12Heap* pHeap,
        UINT NumRanges,
        const D3D12_TILE_RANGE_FLAGS* pRangeFlags,
        const UINT* pHeapRangeStartOffsets,
        const UINT* pRangeTileCounts,
        D3D12_TILE_MAPPING_FLAGS Flags) const;

    template <size_t N>
    std::vector<TileMapping> ToVector(const TileMapping (&tileMappings)[N]) const
    {
        return { tileMappings, tileMappings + N };
    }

    ID3D12Device& m_device;

    void* m_nvapiD3D12UpdateTileMappings;
};

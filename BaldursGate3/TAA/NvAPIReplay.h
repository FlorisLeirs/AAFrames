#pragma once

#include <cstdint>
#include <windows.h>

#include <d3d11.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <dxgi.h>
#include <nvapi.h>

#include "CommonReplay.h"

HRESULT NvAPIReplay_D3D11_CreateDeviceAndSwapChain(
    IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    CONST DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain** ppSwapChain,
    ID3D11Device** ppDevice,
    D3D_FEATURE_LEVEL* pFeatureLevel,
    ID3D11DeviceContext** ppImmediateContext,
    NVAPI_DEVICE_FEATURE_LEVEL* pSupportedLevel);

NvAPI_Status NvAPIReplay_NvAPI_D3D12_UpdateTileMappings(
    ID3D12CommandQueue* pCommandQueue,
    ID3D12Resource* pResource,
    UINT NumResourceRegions,
    const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
    const D3D12_TILE_REGION_SIZE* pResourceRegionSizes,
    ID3D12Heap* pHeap,
    UINT NumRanges,
    const D3D12_TILE_RANGE_FLAGS* pRangeFlags,
    const UINT* pHeapRangeStartOffsets,
    const UINT* pRangeTileCounts,
    D3D12_TILE_MAPPING_FLAGS Flags);

NvAPI_Status NvAPIReplay_D3D_SetSleepMode(IUnknown* pDev, NV_SET_SLEEP_MODE_PARAMS* pParams);
NvAPI_Status NvAPIReplay_D3D_SetLatencyMarker(IUnknown* pDev, NV_LATENCY_MARKER_PARAMS* pParams);
NvAPI_Status NvAPIReplay_D3D_Sleep(IUnknown* pDev);
NvAPI_Status NvAPIReplay_D3D12_SetAsyncFrameMarker(ID3D12CommandQueue* pCommandQueue, NV_ASYNC_FRAME_MARKER_PARAMS* pSetAsyncFrameMarkerParams);

//-----------------------------------------------------------------------------
// Helpers
//-----------------------------------------------------------------------------
NV_REPLAY_EXPORT extern void CheckResult(NvAPI_Status result, const char* file, int line);
#define NV_CHECK_NVAPI_STATUS(_result) CheckResult(_result, __FILE__, __LINE__)

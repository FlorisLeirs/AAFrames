#pragma once

#include <cstdint>
#include <d3d12.h>
#include <string>

#include "D3D12NVAPIUnionStructs.h"
#include <D3D12ReplayTypes.h>

extern bool s_useAuxResetQueue;

struct D3D12GeometryData
{
    struct DataArray
    {
        const void* pData;
        size_t stride;
        size_t originalStride;
        size_t size;
        bool deepCopiedData;
    };

    D3D12_RAYTRACING_GEOMETRY_FLAGS flags;
    UNION_RAYTRACING_GEOMETRY_TYPE type;
    DXGI_FORMAT vertexFormat;
    DXGI_FORMAT indexFormat;
    DXGI_FORMAT ommIndexBufferFormat;
    UINT indexCount;
    UINT ommBaseLocation;
    UINT numUsageCounts;
    DataArray vertexData;
    DataArray transformData;
    DataArray aabbData;
    DataArray ommIndexBufferData;
    D3D12_GPU_VIRTUAL_ADDRESS opacityMicromapArray;

#if NV_CAPTURE_USES_NVAPI
    const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT* pOMMUsageCounts;
#else
    const void* pOMMUsageCounts;
#endif
};

struct D3D12AccelerationStructureInputs
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE type;
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS flags;
    const D3D12GeometryData* pGeometryData;
    size_t geometryCount;
    size_t instanceCount;
    D3D12RaytracingApi api;
};

namespace Serialization {
struct DATABASE_HANDLE;
}

//------------------------------------------------------------------------------
// Create buffers associated with an acceleration structure
//------------------------------------------------------------------------------
#define D3D12CreateAccelerationStructureBuffers(ppAccelerationStructure, ...) D3D12DoCreateAccelerationStructureBuffers(L#ppAccelerationStructure, ppAccelerationStructure, __VA_ARGS__)

void D3D12DoCreateAccelerationStructureBuffers(
    const std::wstring& Name,
    NVD3D12MultiBufferedArray<ID3D12Resource>& accelerationStructure,
    ID3D12Resource** ppScratchBuffer,
    ID3D12Resource** ppDataBuffer,
    ID3D12Resource** ppCloneBuffer,
    ID3D12Device* pDevice,
    const D3D12AccelerationStructureInputs* pInputs,
    size_t inputCount,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO captureTimeSizes);

enum ReplayBeginDataState
{
    NO_MUTATIONS,
    DISCARD_ORIGINAL,
    RESTORE_ORIGINAL
};

//------------------------------------------------------------------------------
// Build the contents of an acceleration structure, from shallow data.
//------------------------------------------------------------------------------
void D3D12InitAccelerationStructure(
    std::pair<NVD3D12MultiBufferedArray<ID3D12Resource>, UINT64> accelerationStructure,
    ID3D12Resource*& pScratchBuffer,
    ID3D12CommandList* pCommandList,
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS inputs,
    Serialization::DATABASE_HANDLE hDeepCopiedTransformData,
    ID3D12Resource*& pDeepCopiedTransformBuffer,
    D3D12RaytracingApi api,
    ReplayBeginDataState dataState,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE copyMode,
    UINT64 captureTimeSize,
    ID3D12CommandQueue* pQueue,
    ID3D12Fence* pFence,
    UINT64& fenceValue);

//------------------------------------------------------------------------------
// Build the contents of an acceleration structure, from deep copied data.
//------------------------------------------------------------------------------
void D3D12InitAccelerationStructure(
    std::pair<NVD3D12MultiBufferedArray<ID3D12Resource>, UINT64> accelerationStructure,
    ID3D12Resource*& pScratchBuffer,
    ID3D12Resource*& pDataBuffer,
    ID3D12CommandList* pCommandList,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE type,
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS flags,
    const D3D12GeometryData* pGeometry,
    size_t geometryCount,
    size_t instanceCount,
    D3D12RaytracingApi api,
    ReplayBeginDataState dataState,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE copyMode,
    UINT64 captureTimeSize,
    ID3D12CommandQueue* pQueue,
    ID3D12Fence* pFence,
    UINT64& fenceValue);

//------------------------------------------------------------------------------
// Choose the acceleration structure based on replay options
//------------------------------------------------------------------------------
D3D12_GPU_VIRTUAL_ADDRESS D3D12GetRTAS(
    ID3D12Resource* pOriginalResource,
    UINT64 originalOffset,
    ID3D12Resource* pDynamicallyAllocated);

std::pair<NVD3D12MultiBufferedArray<ID3D12Resource>, UINT64> D3D12GetRTASMultibuffered(
    NVD3D12MultiBufferedArray<ID3D12Resource> pOriginalResource,
    UINT64 originalOffset,
    NVD3D12MultiBufferedArray<ID3D12Resource> pDynamicallyAllocated);

//------------------------------------------------------------------------------
// Clone an acceleration structure
//------------------------------------------------------------------------------
void D3D12CopyAccelerationStructure(
    ID3D12CommandList* pCommandList,
    D3D12_GPU_VIRTUAL_ADDRESS dest,
    D3D12_GPU_VIRTUAL_ADDRESS src);

//------------------------------------------------------------------------------
// Clone a multibuffered acceleration structure
//------------------------------------------------------------------------------
void D3D12CopyAccelerationStructure(
    NVD3D12MultiBufferedArray<ID3D12GraphicsCommandList>& pCommandList,
    std::pair<NVD3D12MultiBufferedArray<ID3D12Resource>, UINT64>& dest,
    D3D12_GPU_VIRTUAL_ADDRESS src);

//------------------------------------------------------------------------------
// Debug validaton of build params
//------------------------------------------------------------------------------
void D3D12ValidateBuildASParams(
    const UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& buildDesc,
    ID3D12Resource* pDest,
    ID3D12Resource* pScratch);

//------------------------------------------------------------------------------
// Write a block of constants to the SBT
//------------------------------------------------------------------------------
void WriteSBTConstantsFromArray(uint8_t*& pBuffer, UINT* list, size_t len);

#define SBT_CONSTANT_ARGS(...) __VA_ARGS__
#define WRITE_SBT_CONSTANTS(pBuffer, name, list, len) \
    static UINT UINT_temp_##name[len] = list;         \
    WriteSBTConstantsFromArray(pBuffer, UINT_temp_##name, len);

//------------------------------------------------------------------------------
// Stub function for ID3D12StateObjectProperties::SetPipelineStackSize
//------------------------------------------------------------------------------
void D3D12SetPipelineStackSize(ID3D12StateObjectProperties* This, UINT64 PipelineStackSizeInBytes);

//------------------------------------------------------------------------------
// Populate AS instance buffer
//------------------------------------------------------------------------------
HRESULT D3D12InitTopLevelInstances(ID3D12Resource*& pBuffer, D3D12_HEAP_PROPERTIES heapProps, D3D12_HEAP_FLAGS flags, const D3D12_RAYTRACING_INSTANCE_DESC* pData, UINT dataCount);

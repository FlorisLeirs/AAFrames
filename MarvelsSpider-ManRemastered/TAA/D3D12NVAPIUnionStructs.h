#pragma once

// In the GTI, always include NvAPI because we can always include/link against it.
// For C++ captures, only include NvAPI if the capture uses NvAPI. The NvAPI header and
// lib are only exported if the capture uses NVAPI. NvAPI only defines some structures if
// the associated D3D header is already included.  We need to make sure those headers are
// included before including nvapi.h.
#if GTI_PROJECT
#include "NVAPISDKIncludes.h"
#define NV_CAPTURE_USES_NVAPI 1
#else
#include <d3d12.h>
#if NV_CAPTURE_USES_NVAPI
#include <d3d11.h>
#include <d3dcommon.h>
#include <dxgi.h>
#include <nvapi.h>
#endif
#endif

#include <vector>

//----------------------------------------------------------------------------------
// D3D12NVAPIUnionStructs.h
//
// The structures defined in this file store either the D3D12 or NVAPI version of a
// raytracing structure. This allows us to support NVAPI raytracing calls along the
// same paths we support D3D12.
//----------------------------------------------------------------------------------

enum class D3D12RaytracingApi
{
    UNSET,
    D3D12,
    NVAPI,
};

//----------------------------------------------------------------------------------
// UNION_RAYTRACING_GEOMETRY_TYPE
//----------------------------------------------------------------------------------
struct UNION_RAYTRACING_GEOMETRY_TYPE
{
    UNION_RAYTRACING_GEOMETRY_TYPE();
    UNION_RAYTRACING_GEOMETRY_TYPE(D3D12_RAYTRACING_GEOMETRY_TYPE inType);
#if NV_CAPTURE_USES_NVAPI
    UNION_RAYTRACING_GEOMETRY_TYPE(NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_EX inType);
#endif

    // Operators (add as needed)
    bool operator==(const UNION_RAYTRACING_GEOMETRY_TYPE& other) const;
    bool operator==(const UNION_RAYTRACING_GEOMETRY_TYPE& other);
    bool operator!=(const UNION_RAYTRACING_GEOMETRY_TYPE& other) const;
    bool operator!=(const UNION_RAYTRACING_GEOMETRY_TYPE& other);

    // Accessors
    D3D12_RAYTRACING_GEOMETRY_TYPE D3D12Type() const;
#if NV_CAPTURE_USES_NVAPI
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_EX NVAPIType() const;
#endif
    int32_t Value() const;

    // Modifiers
    void SetValue(D3D12_RAYTRACING_GEOMETRY_TYPE value);
#if NV_CAPTURE_USES_NVAPI
    void SetValue(NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_EX value);
#endif

    D3D12RaytracingApi api;

private:
    int32_t type;
};

//----------------------------------------------------------------------------------
// UNION_RAYTRACING_GEOMETRY_DESC
//----------------------------------------------------------------------------------
struct UNION_RAYTRACING_GEOMETRY_DESC
{
    UNION_RAYTRACING_GEOMETRY_DESC();
    UNION_RAYTRACING_GEOMETRY_DESC(D3D12RaytracingApi inApi);
    UNION_RAYTRACING_GEOMETRY_DESC(const D3D12_RAYTRACING_GEOMETRY_DESC& desc);
#if NV_CAPTURE_USES_NVAPI
    UNION_RAYTRACING_GEOMETRY_DESC(const NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX& desc);
#endif

    // Accessors
    const D3D12_RAYTRACING_GEOMETRY_DESC* D3D12Desc() const;
#if NV_CAPTURE_USES_NVAPI
    const NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX* NVAPIDesc() const;
#endif

    UNION_RAYTRACING_GEOMETRY_TYPE Type() const;
    D3D12_RAYTRACING_GEOMETRY_FLAGS Flags() const;
    D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC Triangles() const;
    D3D12_RAYTRACING_GEOMETRY_AABBS_DESC AABBs() const;
#if NV_CAPTURE_USES_NVAPI
    NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC OMMTriangles() const;
#endif

    // Modifiers
    void SetType(UNION_RAYTRACING_GEOMETRY_TYPE type);
    void SetFlags(D3D12_RAYTRACING_GEOMETRY_FLAGS flags);
    void SetTriangles(const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& triangles);
    void SetAABBs(const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& aabbs);
#if NV_CAPTURE_USES_NVAPI
    void SetOMMTriangles(const NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC& ommTriangles);
#endif

    D3D12RaytracingApi api;

private:
    union
    {
        D3D12_RAYTRACING_GEOMETRY_DESC d3d12Desc;
#if NV_CAPTURE_USES_NVAPI
        NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX nvapiDesc;
#endif
    };
};

//----------------------------------------------------------------------------------
// UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS
//----------------------------------------------------------------------------------
struct UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS
{
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS();
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS inFlags);
#if NV_CAPTURE_USES_NVAPI
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS(NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX inFlags);
#endif

    // Operators (add as needed)
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS operator&(const UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS& other);
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS operator|(const UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS& other);
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS& operator&=(const UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS& other);
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS& operator|=(const UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS& other);

    // Accessors
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS D3D12Flags() const;
#if NV_CAPTURE_USES_NVAPI
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX NVAPIFlags() const;
#endif
    uint32_t Value() const;

    // Modifiers
    void SetValue(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS value);
#if NV_CAPTURE_USES_NVAPI
    void SetValue(NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX value);
#endif

    D3D12RaytracingApi api;

private:
    uint32_t flags;
};

//----------------------------------------------------------------------------------
// UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS
//
// Note: pGeometryDescs and ppGeometryDescs are shallow copied when creating this structure.
// To deep copy these structures, you will need to allocate the memory yourself and
// call SetpGeometryDescs().
//----------------------------------------------------------------------------------
struct UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS
{
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS();
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS(D3D12RaytracingApi inApi);
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& inputs);
#if NV_CAPTURE_USES_NVAPI
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS(const NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_EX& inputs);
#endif

    // Accessors
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* D3D12Inputs() const;
#if NV_CAPTURE_USES_NVAPI
    const NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_EX* NVAPIInputs() const;
#endif

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE Type() const;
    UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS Flags() const;
    uint32_t NumDescs() const;
    D3D12_ELEMENTS_LAYOUT DescsLayout() const;
#if NV_CAPTURE_USES_NVAPI
    uint32_t GeometryDescStrideInBytes() const;
#endif

    D3D12_GPU_VIRTUAL_ADDRESS InstanceDescs() const;
    UNION_RAYTRACING_GEOMETRY_DESC pGeometryDesc(uint32_t index) const;
    UNION_RAYTRACING_GEOMETRY_DESC ppGeometryDesc(uint32_t index) const;

    // Modifiers
    void SetType(D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE type);
    void SetFlags(UNION_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS flags);
    void SetNumDescs(uint32_t numDescs);
    void SetDescsLayout(D3D12_ELEMENTS_LAYOUT layout);
    void SetGeometryDescStrideInBytes(uint32_t geometryDescStrideInBytes);
    void SetInstanceDescs(D3D12_GPU_VIRTUAL_ADDRESS instanceDescs);
    void SetpGeometryDescs(void* pData);
    void SetppGeometryDescs(void* pData);

    D3D12RaytracingApi api;

private:
    union
    {
        D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS d3d12Inputs;
#if NV_CAPTURE_USES_NVAPI
        NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_EX nvapiInputs;
#endif
    };
};

//----------------------------------------------------------------------------------
// UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC
//----------------------------------------------------------------------------------
struct UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC
{
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC();
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC(D3D12RaytracingApi inApi);
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& desc);
#if NV_CAPTURE_USES_NVAPI
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC(const NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC_EX& desc);
#endif

    // Accessors
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* D3D12Desc() const;
#if NV_CAPTURE_USES_NVAPI
    const NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC_EX* NVAPIDesc() const;
#endif

    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData() const;
    UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS Inputs() const;
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData() const;
    D3D12_GPU_VIRTUAL_ADDRESS ScratchAccelerationStructureData() const;

    // Modifiers
    void SetDestAccelerationStructureData(D3D12_GPU_VIRTUAL_ADDRESS destAccelerationStructureData);
    void SetInputs(const UNION_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& inputs);
    void SetSourceAccelerationStructureData(D3D12_GPU_VIRTUAL_ADDRESS sourceAccelerationStructureData);
    void SetScratchAccelerationStructureData(D3D12_GPU_VIRTUAL_ADDRESS scratchAccelerationStructureData);

    D3D12RaytracingApi api;

private:
    union
    {
        D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC d3d12Desc;
#if NV_CAPTURE_USES_NVAPI
        NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC_EX nvapiDesc;
#endif
    };
};

//----------------------------------------------------------------------------------
// UNION_VEC_GEOMETRY_DESC
//----------------------------------------------------------------------------------
struct UNION_VEC_GEOMETRY_DESC
{
    UNION_VEC_GEOMETRY_DESC();
    UNION_VEC_GEOMETRY_DESC(D3D12RaytracingApi inApi);
    UNION_VEC_GEOMETRY_DESC(const std::vector<D3D12_RAYTRACING_GEOMETRY_DESC>& geometries);
#if NV_CAPTURE_USES_NVAPI
    UNION_VEC_GEOMETRY_DESC(const std::vector<NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX>& geometries);
#endif

    // Accessors
    void* Data();
    UNION_RAYTRACING_GEOMETRY_DESC At(size_t index) const;
    size_t Size() const;
    const std::vector<D3D12_RAYTRACING_GEOMETRY_DESC>& D3D12Geometries() const;
#if NV_CAPTURE_USES_NVAPI
    const std::vector<NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX>& NVAPIGeometries() const;
#endif

    // Modifiers
    void Resize(size_t count);
    void Reserve(D3D12RaytracingApi inApi, size_t count);
    void Append(const UNION_RAYTRACING_GEOMETRY_DESC& desc);
    void Insert(size_t pos, const UNION_RAYTRACING_GEOMETRY_DESC& desc);
    void Clear();

    D3D12RaytracingApi api;

private:
    std::vector<D3D12_RAYTRACING_GEOMETRY_DESC> d3d12Geometries;
#if NV_CAPTURE_USES_NVAPI
    std::vector<NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX> nvapiGeometries;
#endif
};

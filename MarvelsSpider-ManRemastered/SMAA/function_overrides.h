//--------------------------------------------------------------------------------------
// File: function_overrides.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------------------
#define My_init()\
    init()
#define My_frame(frame_number, frame_functions)\
    frame_functions
#define My_done()\
    done()

#define My_memcpy(Dst, Src, Size)\
    memcpy(Dst, Src, Size)

#define My_NvAPI_D3D11_AliasMSAATexture2DAsNonMSAA(pDevice, pInputTex, ppOutTex)\
    NvAPI_D3D11_AliasMSAATexture2DAsNonMSAA(pDevice, pInputTex, ppOutTex)
#define My_NvAPI_D3D11_BeginUAVOverlap(pDeviceOrContext)\
    NvAPI_D3D11_BeginUAVOverlap(pDeviceOrContext)
#define My_NvAPI_D3D11_BeginUAVOverlapEx(pDeviceOrContext, insertWFIFlags)\
    NvAPI_D3D11_BeginUAVOverlapEx(pDeviceOrContext, insertWFIFlags)
#define My_NvAPI_D3D11_CreateComputeOnlyDevice(pBase3DDevice, Flags, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext)\
    NvAPI_D3D11_CreateComputeOnlyDevice(pBase3DDevice, Flags, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext)
#define My_NvAPI_D3D11_CreateDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext, pSupportedLevel)\
    NvAPI_D3D11_CreateDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext, pSupportedLevel)
#define My_NvAPI_D3D11_CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext, pSupportedLevel)\
    NvAPI_D3D11_CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext, pSupportedLevel)
#define My_NvAPI_D3D11_CreateFastGeometryShader(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, ppGeometryShader)\
    NvAPI_D3D11_CreateFastGeometryShader(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, ppGeometryShader)
#define My_NvAPI_D3D11_CreateFastGeometryShaderExplicit(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, pCreateFastGSArgs, ppGeometryShader)\
    NvAPI_D3D11_CreateFastGeometryShaderExplicit(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, pCreateFastGSArgs, ppGeometryShader)
#define My_NvAPI_D3D11_CreateGeometryShaderEx_2(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, pCreateGeometryShaderExArgs, ppGeometryShader)\
    NvAPI_D3D11_CreateGeometryShaderEx_2(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, pCreateGeometryShaderExArgs, ppGeometryShader)
#define My_NvAPI_D3D11_CreateRasterizerState(pDevice, pRasterizerDesc, ppRasterizerState)\
    NvAPI_D3D11_CreateRasterizerState(pDevice, pRasterizerDesc, ppRasterizerState)
#define My_NvAPI_D3D11_CreateVertexShaderEx(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, pCreateVertexShaderExArgs, ppVertexShader)\
    NvAPI_D3D11_CreateVertexShaderEx(pDevice, pShaderBytecode, BytecodeLength, pClassLinkage, pCreateVertexShaderExArgs, ppVertexShader)
#define My_NvAPI_D3D11_EndUAVOverlap(pDeviceOrContext)\
    NvAPI_D3D11_EndUAVOverlap(pDeviceOrContext)
#define My_NvAPI_D3D11_RSSetViewportsEx(pDevice, pViewportsExArgs)\
    NvAPI_D3D11_RSSetViewportsEx(pDevice, pViewportsExArgs)
#define My_NvAPI_D3D11_SetDepthBoundsTest(pDeviceOrContext, bEnable, fMinDepth, fMaxDepth)\
    NvAPI_D3D11_SetDepthBoundsTest(pDeviceOrContext, bEnable, fMinDepth, fMaxDepth)
#define My_NvAPI_D3D11_SetNvShaderExtnSlot(pDev, uavSlot)\
    NvAPI_D3D11_SetNvShaderExtnSlot(pDev, uavSlot)
#define My_NvAPI_D3D12_BuildRaytracingAccelerationStructureEx(pCommandList, pParams)\
    NvAPI_D3D12_BuildRaytracingAccelerationStructureEx(pCommandList, pParams)
#define My_NvAPI_D3D12_BuildRaytracingOpacityMicromapArray(pCommandList, pParams)\
    NvAPI_D3D12_BuildRaytracingOpacityMicromapArray(pCommandList, pParams)
#define My_NvAPI_D3D12_EmitRaytracingOpacityMicromapArrayPostbuildInfo(pCommandList, pParams)\
    NvAPI_D3D12_EmitRaytracingOpacityMicromapArrayPostbuildInfo(pCommandList, pParams)
#define My_NvAPI_D3D12_GetRaytracingAccelerationStructurePrebuildInfoEx(pDevice, pParams)\
    NvAPI_D3D12_GetRaytracingAccelerationStructurePrebuildInfoEx(pDevice, pParams)
#define My_NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo(pDevice, pParams)\
    NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo(pDevice, pParams)
#define My_NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo(pDevice, pParams)\
    NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo(pDevice, pParams)
#define My_NvAPI_D3D12_UpdateTileMappings(pCommandQueue, pResource, NumResourceRegions, pResourceRegionStartCoordinates, pResourceRegionSizes, pHeap, NumRanges, pRangeFlags, pHeapRangeStartOffsets, pRangeTileCounts, Flags)\
    NvAPI_D3D12_UpdateTileMappings(pCommandQueue, pResource, NumResourceRegions, pResourceRegionStartCoordinates, pResourceRegionSizes, pHeap, NumRanges, pRangeFlags, pHeapRangeStartOffsets, pRangeTileCounts, Flags)
#define My_NvAPI_D3D_BeginResourceRendering(pDeviceOrContext, obj, Flags)\
    NvAPI_D3D_BeginResourceRendering(pDeviceOrContext, obj, Flags)
#define My_NvAPI_D3D_EndResourceRendering(pDeviceOrContext, obj, Flags)\
    NvAPI_D3D_EndResourceRendering(pDeviceOrContext, obj, Flags)
#define My_NvAPI_D3D_GetObjectHandleForResource(pDevice, pResource, pHandle)\
    NvAPI_D3D_GetObjectHandleForResource(pDevice, pResource, pHandle)
#define My_NvAPI_D3D_RegisterApp(pDev, userAppId)\
    NvAPI_D3D_RegisterApp(pDev, userAppId)
#define My_NvAPI_D3D_RegisterDevice(pDev)\
    NvAPI_D3D_RegisterDevice(pDev)
#define My_NvAPI_D3D_SetModifiedWMode(pDevOrContext, psModifiedWParams)\
    NvAPI_D3D_SetModifiedWMode(pDevOrContext, psModifiedWParams)
#define My_NvAPI_D3D_SetResourceHint(pDev, obj, dwHintCategory, dwHintName, pdwHintValue)\
    NvAPI_D3D_SetResourceHint(pDev, obj, dwHintCategory, dwHintName, pdwHintValue)
#define My_NvAPI_D3D_SetSinglePassStereoMode(pDevOrContext, numViews, renderTargetIndexOffset, independentViewportMaskEnable)\
    NvAPI_D3D_SetSinglePassStereoMode(pDevOrContext, numViews, renderTargetIndexOffset, independentViewportMaskEnable)

#define My_ID3D11NvShadingRateResourceView_QueryInterface(pID3D11NvShadingRateResourceView, iid, ppv)\
    (pID3D11NvShadingRateResourceView)->QueryInterface(iid, ppv)
#define My_IUnknown_QueryInterface(pIUnknown, iid, ppv)\
    (pIUnknown)->QueryInterface(iid, ppv)
#define My_ID3D11NvShadingRateResourceView_AddRef(pID3D11NvShadingRateResourceView)\
    (pID3D11NvShadingRateResourceView)->AddRef()
#define My_IUnknown_AddRef(pIUnknown)\
    (pIUnknown)->AddRef()
#define My_ID3D11NvShadingRateResourceView_Release(pID3D11NvShadingRateResourceView)\
    (pID3D11NvShadingRateResourceView)->Release()
#define My_IUnknown_Release(pIUnknown)\
    (pIUnknown)->Release()
#define My_ID3D11NvShadingRateResourceView_GetDesc(pID3D11NvShadingRateResourceView, pDesc)\
    (pID3D11NvShadingRateResourceView)->GetDesc(pDesc)

#define My_ID3DNvSMPAssist_Disable(pID3DNvSMPAssist, pDevContext, psSMPAssistDisableParams)\
    (pID3DNvSMPAssist)->Disable(pDevContext, psSMPAssistDisableParams)
#define My_ID3DNvSMPAssist_Enable(pID3DNvSMPAssist, pDevContext, psSMPAssistEnableParams)\
    (pID3DNvSMPAssist)->Enable(pDevContext, psSMPAssistEnableParams)
#define My_ID3DNvSMPAssist_GetConstants(pID3DNvSMPAssist, psSMPAssistGetConstants)\
    (pID3DNvSMPAssist)->GetConstants(psSMPAssistGetConstants)
#define My_ID3DNvSMPAssist_SetupProjections(pID3DNvSMPAssist, pDevContext, psSMPAssistSetupParams)\
    (pID3DNvSMPAssist)->SetupProjections(pDevContext, psSMPAssistSetupParams)
#define My_ID3DNvSMPAssist_UpdateInstancedStereoData(pID3DNvSMPAssist, pDevContext, psSMPAssistInstancedStereoParams)\
    (pID3DNvSMPAssist)->UpdateInstancedStereoData(pDevContext, psSMPAssistInstancedStereoParams)

#define My_ID3D11NvMetaCommand_QueryInterface(pID3D11NvMetaCommand, riid, ppvObj)\
    (pID3D11NvMetaCommand)->QueryInterface(riid, ppvObj)
#define My_ID3D11NvMetaCommand_AddRef(pID3D11NvMetaCommand)\
    (pID3D11NvMetaCommand)->AddRef()
#define My_ID3D11NvMetaCommand_Release(pID3D11NvMetaCommand)\
    (pID3D11NvMetaCommand)->Release()
#define My_ID3D11NvMetaCommand_GetRequiredParameterResourceSize(pID3D11NvMetaCommand, ResourceType, SizeInBytes)\
    (pID3D11NvMetaCommand)->GetRequiredParameterResourceSize(ResourceType, SizeInBytes)

#define My_ID3D12NvMetaCommand_QueryInterface(pID3D12NvMetaCommand, riid, ppvObj)\
    (pID3D12NvMetaCommand)->QueryInterface(riid, ppvObj)
#define My_ID3D12NvMetaCommand_AddRef(pID3D12NvMetaCommand)\
    (pID3D12NvMetaCommand)->AddRef()
#define My_ID3D12NvMetaCommand_Release(pID3D12NvMetaCommand)\
    (pID3D12NvMetaCommand)->Release()
#define My_ID3D12NvMetaCommand_GetRequiredParameterResourceSize(pID3D12NvMetaCommand, ResourceType, SizeInBytes)\
    (pID3D12NvMetaCommand)->GetRequiredParameterResourceSize(ResourceType, SizeInBytes)

#define My_nvtxMarkEx(eventAttrib)\
    nvtxMarkEx(eventAttrib)
#define My_nvtxMarkA(message)\
    nvtxMarkA(message)
#define My_nvtxMarkW(message)\
    nvtxMarkW(message)
#define My_nvtxRangeStartEx(eventAttrib)\
    nvtxRangeStartEx(eventAttrib)
#define My_nvtxRangeStartA(message)\
    nvtxRangeStartA(message)
#define My_nvtxRangeStartW(message)\
    nvtxRangeStartW(message)
#define My_nvtxRangeEnd(id)\
    nvtxRangeEnd(id)
#define My_nvtxRangePushEx(eventAttrib)\
    nvtxRangePushEx(eventAttrib)
#define My_nvtxRangePushA(message)\
    nvtxRangePushA(message)
#define My_nvtxRangePushW(message)\
    nvtxRangePushW(message)
#define My_nvtxRangePop()\
    nvtxRangePop()
#define My_nvtxNameCategoryA(category, name)\
    nvtxNameCategoryA(category, name)
#define My_nvtxNameCategoryW(category, name)\
    nvtxNameCategoryW(category, name)
#define My_nvtxNameOsThreadA(threadId, name)\
    nvtxNameOsThreadA(threadId, name)
#define My_nvtxNameOsThreadW(threadId, name)\
    nvtxNameOsThreadW(threadId, name)

#define My_D3D11CreateDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext)\
    D3D11CreateDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext)
#define My_D3D11CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext)\
    D3D11CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext)

#define My_ID3D11DeviceChild_QueryInterface(pID3D11DeviceChild, riid, ppvObj)\
    (pID3D11DeviceChild)->QueryInterface(riid, ppvObj)
#define My_ID3D11DeviceChild_AddRef(pID3D11DeviceChild)\
    (pID3D11DeviceChild)->AddRef()
#define My_ID3D11DeviceChild_Release(pID3D11DeviceChild)\
    (pID3D11DeviceChild)->Release()
#define My_ID3D11DeviceChild_GetDevice(pID3D11DeviceChild, ppDevice)\
    (pID3D11DeviceChild)->GetDevice(ppDevice)
#define My_ID3D11DeviceChild_GetPrivateData(pID3D11DeviceChild, guid, pDataSize, pData)\
    (pID3D11DeviceChild)->GetPrivateData(guid, pDataSize, pData)
#define My_ID3D11DeviceChild_SetPrivateData(pID3D11DeviceChild, guid, DataSize, pData)\
    (pID3D11DeviceChild)->SetPrivateData(guid, DataSize, pData)
#define My_ID3D11DeviceChild_SetPrivateDataInterface(pID3D11DeviceChild, guid, pData)\
    (pID3D11DeviceChild)->SetPrivateDataInterface(guid, pData)

#define My_ID3D11DepthStencilState_QueryInterface(pID3D11DepthStencilState, riid, ppvObj)\
    (pID3D11DepthStencilState)->QueryInterface(riid, ppvObj)
#define My_ID3D11DepthStencilState_AddRef(pID3D11DepthStencilState)\
    (pID3D11DepthStencilState)->AddRef()
#define My_ID3D11DepthStencilState_Release(pID3D11DepthStencilState)\
    (pID3D11DepthStencilState)->Release()
#define My_ID3D11DepthStencilState_GetDesc(pID3D11DepthStencilState, pDesc)\
    (pID3D11DepthStencilState)->GetDesc(pDesc)

#define My_ID3D11BlendState_QueryInterface(pID3D11BlendState, riid, ppvObj)\
    (pID3D11BlendState)->QueryInterface(riid, ppvObj)
#define My_ID3D11BlendState_AddRef(pID3D11BlendState)\
    (pID3D11BlendState)->AddRef()
#define My_ID3D11BlendState_Release(pID3D11BlendState)\
    (pID3D11BlendState)->Release()
#define My_ID3D11BlendState_GetDesc(pID3D11BlendState, pDesc)\
    (pID3D11BlendState)->GetDesc(pDesc)

#define My_ID3D11RasterizerState_QueryInterface(pID3D11RasterizerState, riid, ppvObj)\
    (pID3D11RasterizerState)->QueryInterface(riid, ppvObj)
#define My_ID3D11RasterizerState_AddRef(pID3D11RasterizerState)\
    (pID3D11RasterizerState)->AddRef()
#define My_ID3D11RasterizerState_Release(pID3D11RasterizerState)\
    (pID3D11RasterizerState)->Release()
#define My_ID3D11RasterizerState_GetDesc(pID3D11RasterizerState, pDesc)\
    (pID3D11RasterizerState)->GetDesc(pDesc)

#define My_ID3D11Resource_QueryInterface(pID3D11Resource, riid, ppvObj)\
    (pID3D11Resource)->QueryInterface(riid, ppvObj)
#define My_ID3D11Resource_AddRef(pID3D11Resource)\
    (pID3D11Resource)->AddRef()
#define My_ID3D11Resource_Release(pID3D11Resource)\
    (pID3D11Resource)->Release()
#define My_ID3D11Resource_GetType(pID3D11Resource, pResourceDimension)\
    (pID3D11Resource)->GetType(pResourceDimension)
#define My_ID3D11Resource_SetEvictionPriority(pID3D11Resource, EvictionPriority)\
    (pID3D11Resource)->SetEvictionPriority(EvictionPriority)
#define My_ID3D11Resource_GetEvictionPriority(pID3D11Resource)\
    (pID3D11Resource)->GetEvictionPriority()

#define My_ID3D11Buffer_QueryInterface(pID3D11Buffer, riid, ppvObj)\
    (pID3D11Buffer)->QueryInterface(riid, ppvObj)
#define My_ID3D11Buffer_AddRef(pID3D11Buffer)\
    (pID3D11Buffer)->AddRef()
#define My_ID3D11Buffer_Release(pID3D11Buffer)\
    (pID3D11Buffer)->Release()
#define My_ID3D11Buffer_GetDesc(pID3D11Buffer, pDesc)\
    (pID3D11Buffer)->GetDesc(pDesc)

#define My_ID3D11Texture1D_QueryInterface(pID3D11Texture1D, riid, ppvObj)\
    (pID3D11Texture1D)->QueryInterface(riid, ppvObj)
#define My_ID3D11Texture1D_AddRef(pID3D11Texture1D)\
    (pID3D11Texture1D)->AddRef()
#define My_ID3D11Texture1D_Release(pID3D11Texture1D)\
    (pID3D11Texture1D)->Release()
#define My_ID3D11Texture1D_GetDesc(pID3D11Texture1D, pDesc)\
    (pID3D11Texture1D)->GetDesc(pDesc)

#define My_ID3D11Texture2D_QueryInterface(pID3D11Texture2D, riid, ppvObj)\
    (pID3D11Texture2D)->QueryInterface(riid, ppvObj)
#define My_ID3D11Texture2D_AddRef(pID3D11Texture2D)\
    (pID3D11Texture2D)->AddRef()
#define My_ID3D11Texture2D_Release(pID3D11Texture2D)\
    (pID3D11Texture2D)->Release()
#define My_ID3D11Texture2D_GetDesc(pID3D11Texture2D, pDesc)\
    (pID3D11Texture2D)->GetDesc(pDesc)

#define My_ID3D11Texture3D_QueryInterface(pID3D11Texture3D, riid, ppvObj)\
    (pID3D11Texture3D)->QueryInterface(riid, ppvObj)
#define My_ID3D11Texture3D_AddRef(pID3D11Texture3D)\
    (pID3D11Texture3D)->AddRef()
#define My_ID3D11Texture3D_Release(pID3D11Texture3D)\
    (pID3D11Texture3D)->Release()
#define My_ID3D11Texture3D_GetDesc(pID3D11Texture3D, pDesc)\
    (pID3D11Texture3D)->GetDesc(pDesc)

#define My_ID3D11View_QueryInterface(pID3D11View, riid, ppvObj)\
    (pID3D11View)->QueryInterface(riid, ppvObj)
#define My_ID3D11View_AddRef(pID3D11View)\
    (pID3D11View)->AddRef()
#define My_ID3D11View_Release(pID3D11View)\
    (pID3D11View)->Release()
#define My_ID3D11View_GetResource(pID3D11View, ppResource)\
    (pID3D11View)->GetResource(ppResource)

#define My_ID3D11ShaderResourceView_QueryInterface(pID3D11ShaderResourceView, riid, ppvObj)\
    (pID3D11ShaderResourceView)->QueryInterface(riid, ppvObj)
#define My_ID3D11ShaderResourceView_AddRef(pID3D11ShaderResourceView)\
    (pID3D11ShaderResourceView)->AddRef()
#define My_ID3D11ShaderResourceView_Release(pID3D11ShaderResourceView)\
    (pID3D11ShaderResourceView)->Release()
#define My_ID3D11ShaderResourceView_GetDesc(pID3D11ShaderResourceView, pDesc)\
    (pID3D11ShaderResourceView)->GetDesc(pDesc)

#define My_ID3D11RenderTargetView_QueryInterface(pID3D11RenderTargetView, riid, ppvObj)\
    (pID3D11RenderTargetView)->QueryInterface(riid, ppvObj)
#define My_ID3D11RenderTargetView_AddRef(pID3D11RenderTargetView)\
    (pID3D11RenderTargetView)->AddRef()
#define My_ID3D11RenderTargetView_Release(pID3D11RenderTargetView)\
    (pID3D11RenderTargetView)->Release()
#define My_ID3D11RenderTargetView_GetDesc(pID3D11RenderTargetView, pDesc)\
    (pID3D11RenderTargetView)->GetDesc(pDesc)

#define My_ID3D11DepthStencilView_QueryInterface(pID3D11DepthStencilView, riid, ppvObj)\
    (pID3D11DepthStencilView)->QueryInterface(riid, ppvObj)
#define My_ID3D11DepthStencilView_AddRef(pID3D11DepthStencilView)\
    (pID3D11DepthStencilView)->AddRef()
#define My_ID3D11DepthStencilView_Release(pID3D11DepthStencilView)\
    (pID3D11DepthStencilView)->Release()
#define My_ID3D11DepthStencilView_GetDesc(pID3D11DepthStencilView, pDesc)\
    (pID3D11DepthStencilView)->GetDesc(pDesc)

#define My_ID3D11UnorderedAccessView_QueryInterface(pID3D11UnorderedAccessView, riid, ppvObj)\
    (pID3D11UnorderedAccessView)->QueryInterface(riid, ppvObj)
#define My_ID3D11UnorderedAccessView_AddRef(pID3D11UnorderedAccessView)\
    (pID3D11UnorderedAccessView)->AddRef()
#define My_ID3D11UnorderedAccessView_Release(pID3D11UnorderedAccessView)\
    (pID3D11UnorderedAccessView)->Release()
#define My_ID3D11UnorderedAccessView_GetDesc(pID3D11UnorderedAccessView, pDesc)\
    (pID3D11UnorderedAccessView)->GetDesc(pDesc)

#define My_ID3D11VertexShader_QueryInterface(pID3D11VertexShader, riid, ppvObj)\
    (pID3D11VertexShader)->QueryInterface(riid, ppvObj)
#define My_ID3D11VertexShader_AddRef(pID3D11VertexShader)\
    (pID3D11VertexShader)->AddRef()
#define My_ID3D11VertexShader_Release(pID3D11VertexShader)\
    (pID3D11VertexShader)->Release()

#define My_ID3D11HullShader_QueryInterface(pID3D11HullShader, riid, ppvObj)\
    (pID3D11HullShader)->QueryInterface(riid, ppvObj)
#define My_ID3D11HullShader_AddRef(pID3D11HullShader)\
    (pID3D11HullShader)->AddRef()
#define My_ID3D11HullShader_Release(pID3D11HullShader)\
    (pID3D11HullShader)->Release()

#define My_ID3D11DomainShader_QueryInterface(pID3D11DomainShader, riid, ppvObj)\
    (pID3D11DomainShader)->QueryInterface(riid, ppvObj)
#define My_ID3D11DomainShader_AddRef(pID3D11DomainShader)\
    (pID3D11DomainShader)->AddRef()
#define My_ID3D11DomainShader_Release(pID3D11DomainShader)\
    (pID3D11DomainShader)->Release()

#define My_ID3D11GeometryShader_QueryInterface(pID3D11GeometryShader, riid, ppvObj)\
    (pID3D11GeometryShader)->QueryInterface(riid, ppvObj)
#define My_ID3D11GeometryShader_AddRef(pID3D11GeometryShader)\
    (pID3D11GeometryShader)->AddRef()
#define My_ID3D11GeometryShader_Release(pID3D11GeometryShader)\
    (pID3D11GeometryShader)->Release()

#define My_ID3D11PixelShader_QueryInterface(pID3D11PixelShader, riid, ppvObj)\
    (pID3D11PixelShader)->QueryInterface(riid, ppvObj)
#define My_ID3D11PixelShader_AddRef(pID3D11PixelShader)\
    (pID3D11PixelShader)->AddRef()
#define My_ID3D11PixelShader_Release(pID3D11PixelShader)\
    (pID3D11PixelShader)->Release()

#define My_ID3D11ComputeShader_QueryInterface(pID3D11ComputeShader, riid, ppvObj)\
    (pID3D11ComputeShader)->QueryInterface(riid, ppvObj)
#define My_ID3D11ComputeShader_AddRef(pID3D11ComputeShader)\
    (pID3D11ComputeShader)->AddRef()
#define My_ID3D11ComputeShader_Release(pID3D11ComputeShader)\
    (pID3D11ComputeShader)->Release()

#define My_ID3D11InputLayout_QueryInterface(pID3D11InputLayout, riid, ppvObj)\
    (pID3D11InputLayout)->QueryInterface(riid, ppvObj)
#define My_ID3D11InputLayout_AddRef(pID3D11InputLayout)\
    (pID3D11InputLayout)->AddRef()
#define My_ID3D11InputLayout_Release(pID3D11InputLayout)\
    (pID3D11InputLayout)->Release()

#define My_ID3D11SamplerState_QueryInterface(pID3D11SamplerState, riid, ppvObj)\
    (pID3D11SamplerState)->QueryInterface(riid, ppvObj)
#define My_ID3D11SamplerState_AddRef(pID3D11SamplerState)\
    (pID3D11SamplerState)->AddRef()
#define My_ID3D11SamplerState_Release(pID3D11SamplerState)\
    (pID3D11SamplerState)->Release()
#define My_ID3D11SamplerState_GetDesc(pID3D11SamplerState, pDesc)\
    (pID3D11SamplerState)->GetDesc(pDesc)

#define My_ID3D11Asynchronous_QueryInterface(pID3D11Asynchronous, riid, ppvObj)\
    (pID3D11Asynchronous)->QueryInterface(riid, ppvObj)
#define My_ID3D11Asynchronous_AddRef(pID3D11Asynchronous)\
    (pID3D11Asynchronous)->AddRef()
#define My_ID3D11Asynchronous_Release(pID3D11Asynchronous)\
    (pID3D11Asynchronous)->Release()
#define My_ID3D11Asynchronous_GetDataSize(pID3D11Asynchronous)\
    (pID3D11Asynchronous)->GetDataSize()

#define My_ID3D11Query_QueryInterface(pID3D11Query, riid, ppvObj)\
    (pID3D11Query)->QueryInterface(riid, ppvObj)
#define My_ID3D11Query_AddRef(pID3D11Query)\
    (pID3D11Query)->AddRef()
#define My_ID3D11Query_Release(pID3D11Query)\
    (pID3D11Query)->Release()
#define My_ID3D11Query_GetDesc(pID3D11Query, pDesc)\
    (pID3D11Query)->GetDesc(pDesc)

#define My_ID3D11Predicate_QueryInterface(pID3D11Predicate, riid, ppvObj)\
    (pID3D11Predicate)->QueryInterface(riid, ppvObj)
#define My_ID3D11Predicate_AddRef(pID3D11Predicate)\
    (pID3D11Predicate)->AddRef()
#define My_ID3D11Predicate_Release(pID3D11Predicate)\
    (pID3D11Predicate)->Release()

#define My_ID3D11Counter_QueryInterface(pID3D11Counter, riid, ppvObj)\
    (pID3D11Counter)->QueryInterface(riid, ppvObj)
#define My_ID3D11Counter_AddRef(pID3D11Counter)\
    (pID3D11Counter)->AddRef()
#define My_ID3D11Counter_Release(pID3D11Counter)\
    (pID3D11Counter)->Release()
#define My_ID3D11Counter_GetDesc(pID3D11Counter, pDesc)\
    (pID3D11Counter)->GetDesc(pDesc)

#define My_ID3D11ClassInstance_QueryInterface(pID3D11ClassInstance, riid, ppvObj)\
    (pID3D11ClassInstance)->QueryInterface(riid, ppvObj)
#define My_ID3D11ClassInstance_AddRef(pID3D11ClassInstance)\
    (pID3D11ClassInstance)->AddRef()
#define My_ID3D11ClassInstance_Release(pID3D11ClassInstance)\
    (pID3D11ClassInstance)->Release()
#define My_ID3D11ClassInstance_GetClassLinkage(pID3D11ClassInstance, ppLinkage)\
    (pID3D11ClassInstance)->GetClassLinkage(ppLinkage)
#define My_ID3D11ClassInstance_GetDesc(pID3D11ClassInstance, pDesc)\
    (pID3D11ClassInstance)->GetDesc(pDesc)
#define My_ID3D11ClassInstance_GetInstanceName(pID3D11ClassInstance, pInstanceName, pBufferLength)\
    (pID3D11ClassInstance)->GetInstanceName(pInstanceName, pBufferLength)
#define My_ID3D11ClassInstance_GetTypeName(pID3D11ClassInstance, pTypeName, pBufferLength)\
    (pID3D11ClassInstance)->GetTypeName(pTypeName, pBufferLength)

#define My_ID3D11ClassLinkage_QueryInterface(pID3D11ClassLinkage, riid, ppvObj)\
    (pID3D11ClassLinkage)->QueryInterface(riid, ppvObj)
#define My_ID3D11ClassLinkage_AddRef(pID3D11ClassLinkage)\
    (pID3D11ClassLinkage)->AddRef()
#define My_ID3D11ClassLinkage_Release(pID3D11ClassLinkage)\
    (pID3D11ClassLinkage)->Release()
#define My_ID3D11ClassLinkage_GetClassInstance(pID3D11ClassLinkage, pClassInstanceName, InstanceIndex, ppInstance)\
    (pID3D11ClassLinkage)->GetClassInstance(pClassInstanceName, InstanceIndex, ppInstance)
#define My_ID3D11ClassLinkage_CreateClassInstance(pID3D11ClassLinkage, pClassTypeName, ConstantBufferOffset, ConstantVectorOffset, TextureOffset, SamplerOffset, ppInstance)\
    (pID3D11ClassLinkage)->CreateClassInstance(pClassTypeName, ConstantBufferOffset, ConstantVectorOffset, TextureOffset, SamplerOffset, ppInstance)

#define My_ID3D11CommandList_QueryInterface(pID3D11CommandList, riid, ppvObj)\
    (pID3D11CommandList)->QueryInterface(riid, ppvObj)
#define My_ID3D11CommandList_AddRef(pID3D11CommandList)\
    (pID3D11CommandList)->AddRef()
#define My_ID3D11CommandList_Release(pID3D11CommandList)\
    (pID3D11CommandList)->Release()
#define My_ID3D11CommandList_GetContextFlags(pID3D11CommandList)\
    (pID3D11CommandList)->GetContextFlags()

#define My_ID3D11DeviceContext_QueryInterface(pID3D11DeviceContext, riid, ppvObj)\
    (pID3D11DeviceContext)->QueryInterface(riid, ppvObj)
#define My_ID3D11DeviceContext_AddRef(pID3D11DeviceContext)\
    (pID3D11DeviceContext)->AddRef()
#define My_ID3D11DeviceContext_Release(pID3D11DeviceContext)\
    (pID3D11DeviceContext)->Release()
#define My_ID3D11DeviceContext_VSSetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_PSSetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_PSSetShader(pID3D11DeviceContext, pPixelShader, ppClassInstances, NumClassInstances)\
    (pID3D11DeviceContext)->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances)
#define My_ID3D11DeviceContext_PSSetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->PSSetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_VSSetShader(pID3D11DeviceContext, pVertexShader, ppClassInstances, NumClassInstances)\
    (pID3D11DeviceContext)->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances)
#define My_ID3D11DeviceContext_DrawIndexed(pID3D11DeviceContext, IndexCount, StartIndexLocation, BaseVertexLocation)\
    (pID3D11DeviceContext)->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation)
#define My_ID3D11DeviceContext_Draw(pID3D11DeviceContext, VertexCount, StartVertexLocation)\
    (pID3D11DeviceContext)->Draw(VertexCount, StartVertexLocation)
#define My_ID3D11DeviceContext_Map(pID3D11DeviceContext, pResource, Subresource, MapType, MapFlags, pMappedResource)\
    (pID3D11DeviceContext)->Map(pResource, Subresource, MapType, MapFlags, pMappedResource)
#define My_ID3D11DeviceContext_Unmap(pID3D11DeviceContext, pResource, Subresource)\
    (pID3D11DeviceContext)->Unmap(pResource, Subresource)
#define My_ID3D11DeviceContext_PSSetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_IASetInputLayout(pID3D11DeviceContext, pInputLayout)\
    (pID3D11DeviceContext)->IASetInputLayout(pInputLayout)
#define My_ID3D11DeviceContext_IASetVertexBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets)\
    (pID3D11DeviceContext)->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets)
#define My_ID3D11DeviceContext_IASetIndexBuffer(pID3D11DeviceContext, pIndexBuffer, Format, Offset)\
    (pID3D11DeviceContext)->IASetIndexBuffer(pIndexBuffer, Format, Offset)
#define My_ID3D11DeviceContext_DrawIndexedInstanced(pID3D11DeviceContext, IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation)\
    (pID3D11DeviceContext)->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation)
#define My_ID3D11DeviceContext_DrawInstanced(pID3D11DeviceContext, VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation)\
    (pID3D11DeviceContext)->DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation)
#define My_ID3D11DeviceContext_GSSetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->GSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_GSSetShader(pID3D11DeviceContext, pShader, ppClassInstances, NumClassInstances)\
    (pID3D11DeviceContext)->GSSetShader(pShader, ppClassInstances, NumClassInstances)
#define My_ID3D11DeviceContext_IASetPrimitiveTopology(pID3D11DeviceContext, Topology)\
    (pID3D11DeviceContext)->IASetPrimitiveTopology(Topology)
#define My_ID3D11DeviceContext_VSSetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->VSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_VSSetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->VSSetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_Begin(pID3D11DeviceContext, pAsync)\
    (pID3D11DeviceContext)->Begin(pAsync)
#define My_ID3D11DeviceContext_End(pID3D11DeviceContext, pAsync)\
    (pID3D11DeviceContext)->End(pAsync)
#define My_ID3D11DeviceContext_GetData(pID3D11DeviceContext, pAsync, pData, DataSize, GetDataFlags)\
    (pID3D11DeviceContext)->GetData(pAsync, pData, DataSize, GetDataFlags)
#define My_ID3D11DeviceContext_SetPredication(pID3D11DeviceContext, pPredicate, PredicateValue)\
    (pID3D11DeviceContext)->SetPredication(pPredicate, PredicateValue)
#define My_ID3D11DeviceContext_GSSetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->GSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_GSSetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->GSSetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_OMSetRenderTargets(pID3D11DeviceContext, NumViews, ppRenderTargetViews, pDepthStencilView)\
    (pID3D11DeviceContext)->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView)
#define My_ID3D11DeviceContext_OMSetRenderTargetsAndUnorderedAccessViews(pID3D11DeviceContext, NumRTVs, ppRenderTargetViews, pDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts)\
    (pID3D11DeviceContext)->OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, pDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts)
#define My_ID3D11DeviceContext_OMSetBlendState(pID3D11DeviceContext, pBlendState, BlendFactor, SampleMask)\
    (pID3D11DeviceContext)->OMSetBlendState(pBlendState, BlendFactor, SampleMask)
#define My_ID3D11DeviceContext_OMSetDepthStencilState(pID3D11DeviceContext, pDepthStencilState, StencilRef)\
    (pID3D11DeviceContext)->OMSetDepthStencilState(pDepthStencilState, StencilRef)
#define My_ID3D11DeviceContext_SOSetTargets(pID3D11DeviceContext, NumBuffers, ppSOTargets, pOffsets)\
    (pID3D11DeviceContext)->SOSetTargets(NumBuffers, ppSOTargets, pOffsets)
#define My_ID3D11DeviceContext_DrawAuto(pID3D11DeviceContext)\
    (pID3D11DeviceContext)->DrawAuto()
#define My_ID3D11DeviceContext_DrawIndexedInstancedIndirect(pID3D11DeviceContext, pBufferForArgs, AlignedByteOffsetForArgs)\
    (pID3D11DeviceContext)->DrawIndexedInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs)
#define My_ID3D11DeviceContext_DrawInstancedIndirect(pID3D11DeviceContext, pBufferForArgs, AlignedByteOffsetForArgs)\
    (pID3D11DeviceContext)->DrawInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs)
#define My_ID3D11DeviceContext_Dispatch(pID3D11DeviceContext, ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ)\
    (pID3D11DeviceContext)->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ)
#define My_ID3D11DeviceContext_DispatchIndirect(pID3D11DeviceContext, pBufferForArgs, AlignedByteOffsetForArgs)\
    (pID3D11DeviceContext)->DispatchIndirect(pBufferForArgs, AlignedByteOffsetForArgs)
#define My_ID3D11DeviceContext_RSSetState(pID3D11DeviceContext, pRasterizerState)\
    (pID3D11DeviceContext)->RSSetState(pRasterizerState)
#define My_ID3D11DeviceContext_RSSetViewports(pID3D11DeviceContext, NumViewports, pViewports)\
    (pID3D11DeviceContext)->RSSetViewports(NumViewports, pViewports)
#define My_ID3D11DeviceContext_RSSetScissorRects(pID3D11DeviceContext, NumRects, pRects)\
    (pID3D11DeviceContext)->RSSetScissorRects(NumRects, pRects)
#define My_ID3D11DeviceContext_CopySubresourceRegion(pID3D11DeviceContext, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox)\
    (pID3D11DeviceContext)->CopySubresourceRegion(pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox)
#define My_ID3D11DeviceContext_CopyResource(pID3D11DeviceContext, pDstResource, pSrcResource)\
    (pID3D11DeviceContext)->CopyResource(pDstResource, pSrcResource)
#define My_ID3D11DeviceContext_UpdateSubresource(pID3D11DeviceContext, pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch)\
    (pID3D11DeviceContext)->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch)
#define My_ID3D11DeviceContext_CopyStructureCount(pID3D11DeviceContext, pDstBuffer, DstAlignedByteOffset, pSrcView)\
    (pID3D11DeviceContext)->CopyStructureCount(pDstBuffer, DstAlignedByteOffset, pSrcView)
#define My_ID3D11DeviceContext_ClearRenderTargetView(pID3D11DeviceContext, pRenderTargetView, ColorRGBA)\
    (pID3D11DeviceContext)->ClearRenderTargetView(pRenderTargetView, ColorRGBA)
#define My_ID3D11DeviceContext_ClearUnorderedAccessViewUint(pID3D11DeviceContext, pUnorderedAccessView, Values)\
    (pID3D11DeviceContext)->ClearUnorderedAccessViewUint(pUnorderedAccessView, Values)
#define My_ID3D11DeviceContext_ClearUnorderedAccessViewFloat(pID3D11DeviceContext, pUnorderedAccessView, Values)\
    (pID3D11DeviceContext)->ClearUnorderedAccessViewFloat(pUnorderedAccessView, Values)
#define My_ID3D11DeviceContext_ClearDepthStencilView(pID3D11DeviceContext, pDepthStencilView, ClearFlags, Depth, Stencil)\
    (pID3D11DeviceContext)->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil)
#define My_ID3D11DeviceContext_GenerateMips(pID3D11DeviceContext, pShaderResourceView)\
    (pID3D11DeviceContext)->GenerateMips(pShaderResourceView)
#define My_ID3D11DeviceContext_SetResourceMinLOD(pID3D11DeviceContext, pResource, MinLOD)\
    (pID3D11DeviceContext)->SetResourceMinLOD(pResource, MinLOD)
#define My_ID3D11DeviceContext_GetResourceMinLOD(pID3D11DeviceContext, pResource)\
    (pID3D11DeviceContext)->GetResourceMinLOD(pResource)
#define My_ID3D11DeviceContext_ResolveSubresource(pID3D11DeviceContext, pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format)\
    (pID3D11DeviceContext)->ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format)
#define My_ID3D11DeviceContext_ExecuteCommandList(pID3D11DeviceContext, pCommandList, RestoreContextState)\
    (pID3D11DeviceContext)->ExecuteCommandList(pCommandList, RestoreContextState)
#define My_ID3D11DeviceContext_HSSetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->HSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_HSSetShader(pID3D11DeviceContext, pHullShader, ppClassInstances, NumClassInstances)\
    (pID3D11DeviceContext)->HSSetShader(pHullShader, ppClassInstances, NumClassInstances)
#define My_ID3D11DeviceContext_HSSetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->HSSetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_HSSetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->HSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_DSSetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->DSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_DSSetShader(pID3D11DeviceContext, pDomainShader, ppClassInstances, NumClassInstances)\
    (pID3D11DeviceContext)->DSSetShader(pDomainShader, ppClassInstances, NumClassInstances)
#define My_ID3D11DeviceContext_DSSetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->DSSetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_DSSetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->DSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_CSSetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->CSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_CSSetUnorderedAccessViews(pID3D11DeviceContext, StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts)\
    (pID3D11DeviceContext)->CSSetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts)
#define My_ID3D11DeviceContext_CSSetShader(pID3D11DeviceContext, pComputeShader, ppClassInstances, NumClassInstances)\
    (pID3D11DeviceContext)->CSSetShader(pComputeShader, ppClassInstances, NumClassInstances)
#define My_ID3D11DeviceContext_CSSetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->CSSetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_CSSetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->CSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_VSGetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->VSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_PSGetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->PSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_PSGetShader(pID3D11DeviceContext, ppPixelShader, ppClassInstances, pNumClassInstances)\
    (pID3D11DeviceContext)->PSGetShader(ppPixelShader, ppClassInstances, pNumClassInstances)
#define My_ID3D11DeviceContext_PSGetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->PSGetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_VSGetShader(pID3D11DeviceContext, ppVertexShader, ppClassInstances, pNumClassInstances)\
    (pID3D11DeviceContext)->VSGetShader(ppVertexShader, ppClassInstances, pNumClassInstances)
#define My_ID3D11DeviceContext_PSGetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->PSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_IAGetInputLayout(pID3D11DeviceContext, ppInputLayout)\
    (pID3D11DeviceContext)->IAGetInputLayout(ppInputLayout)
#define My_ID3D11DeviceContext_IAGetVertexBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets)\
    (pID3D11DeviceContext)->IAGetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets)
#define My_ID3D11DeviceContext_IAGetIndexBuffer(pID3D11DeviceContext, pIndexBuffer, Format, Offset)\
    (pID3D11DeviceContext)->IAGetIndexBuffer(pIndexBuffer, Format, Offset)
#define My_ID3D11DeviceContext_GSGetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->GSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_GSGetShader(pID3D11DeviceContext, ppGeometryShader, ppClassInstances, pNumClassInstances)\
    (pID3D11DeviceContext)->GSGetShader(ppGeometryShader, ppClassInstances, pNumClassInstances)
#define My_ID3D11DeviceContext_IAGetPrimitiveTopology(pID3D11DeviceContext, pTopology)\
    (pID3D11DeviceContext)->IAGetPrimitiveTopology(pTopology)
#define My_ID3D11DeviceContext_VSGetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->VSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_VSGetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->VSGetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_GetPredication(pID3D11DeviceContext, ppPredicate, pPredicateValue)\
    (pID3D11DeviceContext)->GetPredication(ppPredicate, pPredicateValue)
#define My_ID3D11DeviceContext_GSGetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->GSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_GSGetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->GSGetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_OMGetRenderTargets(pID3D11DeviceContext, NumViews, ppRenderTargetViews, ppDepthStencilView)\
    (pID3D11DeviceContext)->OMGetRenderTargets(NumViews, ppRenderTargetViews, ppDepthStencilView)
#define My_ID3D11DeviceContext_OMGetRenderTargetsAndUnorderedAccessViews(pID3D11DeviceContext, NumRTVs, ppRenderTargetViews, ppDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews)\
    (pID3D11DeviceContext)->OMGetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, ppDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews)
#define My_ID3D11DeviceContext_OMGetBlendState(pID3D11DeviceContext, ppBlendState, BlendFactor, pSampleMask)\
    (pID3D11DeviceContext)->OMGetBlendState(ppBlendState, BlendFactor, pSampleMask)
#define My_ID3D11DeviceContext_OMGetDepthStencilState(pID3D11DeviceContext, ppDepthStencilState, pStencilRef)\
    (pID3D11DeviceContext)->OMGetDepthStencilState(ppDepthStencilState, pStencilRef)
#define My_ID3D11DeviceContext_SOGetTargets(pID3D11DeviceContext, NumBuffers, ppSOTargets)\
    (pID3D11DeviceContext)->SOGetTargets(NumBuffers, ppSOTargets)
#define My_ID3D11DeviceContext_RSGetState(pID3D11DeviceContext, ppRasterizerState)\
    (pID3D11DeviceContext)->RSGetState(ppRasterizerState)
#define My_ID3D11DeviceContext_RSGetViewports(pID3D11DeviceContext, pNumViewports, pViewports)\
    (pID3D11DeviceContext)->RSGetViewports(pNumViewports, pViewports)
#define My_ID3D11DeviceContext_RSGetScissorRects(pID3D11DeviceContext, pNumRects, pRects)\
    (pID3D11DeviceContext)->RSGetScissorRects(pNumRects, pRects)
#define My_ID3D11DeviceContext_HSGetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->HSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_HSGetShader(pID3D11DeviceContext, ppHullShader, ppClassInstances, pNumClassInstances)\
    (pID3D11DeviceContext)->HSGetShader(ppHullShader, ppClassInstances, pNumClassInstances)
#define My_ID3D11DeviceContext_HSGetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->HSGetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_HSGetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->HSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_DSGetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->DSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_DSGetShader(pID3D11DeviceContext, ppDomainShader, ppClassInstances, pNumClassInstances)\
    (pID3D11DeviceContext)->DSGetShader(ppDomainShader, ppClassInstances, pNumClassInstances)
#define My_ID3D11DeviceContext_DSGetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->DSGetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_DSGetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->DSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_CSGetShaderResources(pID3D11DeviceContext, StartSlot, NumViews, ppShaderResourceViews)\
    (pID3D11DeviceContext)->CSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews)
#define My_ID3D11DeviceContext_CSGetUnorderedAccessViews(pID3D11DeviceContext, StartSlot, NumUAVs, ppUnorderedAccessViews)\
    (pID3D11DeviceContext)->CSGetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews)
#define My_ID3D11DeviceContext_CSGetShader(pID3D11DeviceContext, ppComputeShader, ppClassInstances, pNumClassInstances)\
    (pID3D11DeviceContext)->CSGetShader(ppComputeShader, ppClassInstances, pNumClassInstances)
#define My_ID3D11DeviceContext_CSGetSamplers(pID3D11DeviceContext, StartSlot, NumSamplers, ppSamplers)\
    (pID3D11DeviceContext)->CSGetSamplers(StartSlot, NumSamplers, ppSamplers)
#define My_ID3D11DeviceContext_CSGetConstantBuffers(pID3D11DeviceContext, StartSlot, NumBuffers, ppConstantBuffers)\
    (pID3D11DeviceContext)->CSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers)
#define My_ID3D11DeviceContext_ClearState(pID3D11DeviceContext)\
    (pID3D11DeviceContext)->ClearState()
#define My_ID3D11DeviceContext_Flush(pID3D11DeviceContext)\
    (pID3D11DeviceContext)->Flush()
#define My_ID3D11DeviceContext_GetType(pID3D11DeviceContext)\
    (pID3D11DeviceContext)->GetType()
#define My_ID3D11DeviceContext_GetContextFlags(pID3D11DeviceContext)\
    (pID3D11DeviceContext)->GetContextFlags()
#define My_ID3D11DeviceContext_FinishCommandList(pID3D11DeviceContext, RestoreDeferredContextState, ppCommandList)\
    (pID3D11DeviceContext)->FinishCommandList(RestoreDeferredContextState, ppCommandList)

#define My_ID3D11Device_QueryInterface(pID3D11Device, riid, ppvObj)\
    (pID3D11Device)->QueryInterface(riid, ppvObj)
#define My_ID3D11Device_AddRef(pID3D11Device)\
    (pID3D11Device)->AddRef()
#define My_ID3D11Device_Release(pID3D11Device)\
    (pID3D11Device)->Release()
#define My_ID3D11Device_CreateBuffer(pID3D11Device, pDesc, pInitialData, ppBuffer)\
    (pID3D11Device)->CreateBuffer(pDesc, pInitialData, ppBuffer)
#define My_ID3D11Device_CreateTexture1D(pID3D11Device, pDesc, pInitialData, ppTexture1D)\
    (pID3D11Device)->CreateTexture1D(pDesc, pInitialData, ppTexture1D)
#define My_ID3D11Device_CreateTexture2D(pID3D11Device, pDesc, pInitialData, ppTexture2D)\
    (pID3D11Device)->CreateTexture2D(pDesc, pInitialData, ppTexture2D)
#define My_ID3D11Device_CreateTexture3D(pID3D11Device, pDesc, pInitialData, ppTexture3D)\
    (pID3D11Device)->CreateTexture3D(pDesc, pInitialData, ppTexture3D)
#define My_ID3D11Device_CreateShaderResourceView(pID3D11Device, pResource, pDesc, ppSRView)\
    (pID3D11Device)->CreateShaderResourceView(pResource, pDesc, ppSRView)
#define My_ID3D11Device_CreateUnorderedAccessView(pID3D11Device, pResource, pDesc, ppUAView)\
    (pID3D11Device)->CreateUnorderedAccessView(pResource, pDesc, ppUAView)
#define My_ID3D11Device_CreateRenderTargetView(pID3D11Device, pResource, pDesc, ppRTView)\
    (pID3D11Device)->CreateRenderTargetView(pResource, pDesc, ppRTView)
#define My_ID3D11Device_CreateDepthStencilView(pID3D11Device, pResource, pDesc, ppDepthStencilView)\
    (pID3D11Device)->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView)
#define My_ID3D11Device_CreateInputLayout(pID3D11Device, pInputElementDescs, NumElements, pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout)\
    (pID3D11Device)->CreateInputLayout(pInputElementDescs, NumElements, pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout)
#define My_ID3D11Device_CreateVertexShader(pID3D11Device, pShaderBytecode, BytecodeLength, pClassLinkage, ppVertexShader)\
    (pID3D11Device)->CreateVertexShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppVertexShader)
#define My_ID3D11Device_CreateGeometryShader(pID3D11Device, pShaderBytecode, BytecodeLength, pClassLinkage, ppGeometryShader)\
    (pID3D11Device)->CreateGeometryShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppGeometryShader)
#define My_ID3D11Device_CreateGeometryShaderWithStreamOutput(pID3D11Device, pShaderBytecode, BytecodeLength, pSODeclaration, NumEntries, pBufferStrides, NumStrides, RasterizedStream, pClassLinkage, ppGeometryShader)\
    (pID3D11Device)->CreateGeometryShaderWithStreamOutput(pShaderBytecode, BytecodeLength, pSODeclaration, NumEntries, pBufferStrides, NumStrides, RasterizedStream, pClassLinkage, ppGeometryShader)
#define My_ID3D11Device_CreatePixelShader(pID3D11Device, pShaderBytecode, BytecodeLength, pClassLinkage, ppPixelShader)\
    (pID3D11Device)->CreatePixelShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppPixelShader)
#define My_ID3D11Device_CreateHullShader(pID3D11Device, pShaderBytecode, BytecodeLength, pClassLinkage, ppHullShader)\
    (pID3D11Device)->CreateHullShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppHullShader)
#define My_ID3D11Device_CreateDomainShader(pID3D11Device, pShaderBytecode, BytecodeLength, pClassLinkage, ppDomainShader)\
    (pID3D11Device)->CreateDomainShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppDomainShader)
#define My_ID3D11Device_CreateComputeShader(pID3D11Device, pShaderBytecode, BytecodeLength, pClassLinkage, ppComputeShader)\
    (pID3D11Device)->CreateComputeShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppComputeShader)
#define My_ID3D11Device_CreateClassLinkage(pID3D11Device, ppLinkage)\
    (pID3D11Device)->CreateClassLinkage(ppLinkage)
#define My_ID3D11Device_CreateBlendState(pID3D11Device, pBlendStateDesc, ppBlendState)\
    (pID3D11Device)->CreateBlendState(pBlendStateDesc, ppBlendState)
#define My_ID3D11Device_CreateDepthStencilState(pID3D11Device, pDepthStencilDesc, ppDepthStencilState)\
    (pID3D11Device)->CreateDepthStencilState(pDepthStencilDesc, ppDepthStencilState)
#define My_ID3D11Device_CreateRasterizerState(pID3D11Device, pRasterizerDesc, ppRasterizerState)\
    (pID3D11Device)->CreateRasterizerState(pRasterizerDesc, ppRasterizerState)
#define My_ID3D11Device_CreateSamplerState(pID3D11Device, pSamplerDesc, ppSamplerState)\
    (pID3D11Device)->CreateSamplerState(pSamplerDesc, ppSamplerState)
#define My_ID3D11Device_CreateQuery(pID3D11Device, pQueryDesc, ppQuery)\
    (pID3D11Device)->CreateQuery(pQueryDesc, ppQuery)
#define My_ID3D11Device_CreatePredicate(pID3D11Device, pPredicateDesc, ppPredicate)\
    (pID3D11Device)->CreatePredicate(pPredicateDesc, ppPredicate)
#define My_ID3D11Device_CreateCounter(pID3D11Device, pCounterDesc, ppCounter)\
    (pID3D11Device)->CreateCounter(pCounterDesc, ppCounter)
#define My_ID3D11Device_CreateDeferredContext(pID3D11Device, ContextFlags, ppDeferredContext)\
    (pID3D11Device)->CreateDeferredContext(ContextFlags, ppDeferredContext)
#define My_ID3D11Device_OpenSharedResource(pID3D11Device, hResource, ReturnedInterface, ppResource)\
    (pID3D11Device)->OpenSharedResource(hResource, ReturnedInterface, ppResource)
#define My_ID3D11Device_CheckFormatSupport(pID3D11Device, Format, pFormatSupport)\
    (pID3D11Device)->CheckFormatSupport(Format, pFormatSupport)
#define My_ID3D11Device_CheckMultisampleQualityLevels(pID3D11Device, Format, SampleCount, pNumQualityLevels)\
    (pID3D11Device)->CheckMultisampleQualityLevels(Format, SampleCount, pNumQualityLevels)
#define My_ID3D11Device_CheckCounterInfo(pID3D11Device, pCounterInfo)\
    (pID3D11Device)->CheckCounterInfo(pCounterInfo)
#define My_ID3D11Device_CheckCounter(pID3D11Device, pDesc, pType, pActiveCounters, szName, pNameLength, szUnits, pUnitsLength, szDescription, pDescriptionLength)\
    (pID3D11Device)->CheckCounter(pDesc, pType, pActiveCounters, szName, pNameLength, szUnits, pUnitsLength, szDescription, pDescriptionLength)
#define My_ID3D11Device_CheckFeatureSupport(pID3D11Device, Feature, pFeatureSupportData, FeatureSupportDataSize)\
    (pID3D11Device)->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize)
#define My_ID3D11Device_GetPrivateData(pID3D11Device, guid, pDataSize, pData)\
    (pID3D11Device)->GetPrivateData(guid, pDataSize, pData)
#define My_ID3D11Device_SetPrivateData(pID3D11Device, guid, DataSize, pData)\
    (pID3D11Device)->SetPrivateData(guid, DataSize, pData)
#define My_ID3D11Device_SetPrivateDataInterface(pID3D11Device, guid, pData)\
    (pID3D11Device)->SetPrivateDataInterface(guid, pData)
#define My_ID3D11Device_GetFeatureLevel(pID3D11Device)\
    (pID3D11Device)->GetFeatureLevel()
#define My_ID3D11Device_GetCreationFlags(pID3D11Device)\
    (pID3D11Device)->GetCreationFlags()
#define My_ID3D11Device_GetDeviceRemovedReason(pID3D11Device)\
    (pID3D11Device)->GetDeviceRemovedReason()
#define My_ID3D11Device_GetImmediateContext(pID3D11Device, ppImmediateContext)\
    (pID3D11Device)->GetImmediateContext(ppImmediateContext)
#define My_ID3D11Device_SetExceptionMode(pID3D11Device, RaiseFlags)\
    (pID3D11Device)->SetExceptionMode(RaiseFlags)
#define My_ID3D11Device_GetExceptionMode(pID3D11Device)\
    (pID3D11Device)->GetExceptionMode()

#define My_ID3D11VideoDecoder_QueryInterface(pID3D11VideoDecoder, riid, ppvObj)\
    (pID3D11VideoDecoder)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoDecoder_AddRef(pID3D11VideoDecoder)\
    (pID3D11VideoDecoder)->AddRef()
#define My_ID3D11VideoDecoder_Release(pID3D11VideoDecoder)\
    (pID3D11VideoDecoder)->Release()
#define My_ID3D11VideoDecoder_GetCreationParameters(pID3D11VideoDecoder, pVideoDesc, pConfig)\
    (pID3D11VideoDecoder)->GetCreationParameters(pVideoDesc, pConfig)
#define My_ID3D11VideoDecoder_GetDriverHandle(pID3D11VideoDecoder, pDriverHandle)\
    (pID3D11VideoDecoder)->GetDriverHandle(pDriverHandle)

#define My_ID3D11VideoProcessorEnumerator_QueryInterface(pID3D11VideoProcessorEnumerator, riid, ppvObj)\
    (pID3D11VideoProcessorEnumerator)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoProcessorEnumerator_AddRef(pID3D11VideoProcessorEnumerator)\
    (pID3D11VideoProcessorEnumerator)->AddRef()
#define My_ID3D11VideoProcessorEnumerator_Release(pID3D11VideoProcessorEnumerator)\
    (pID3D11VideoProcessorEnumerator)->Release()
#define My_ID3D11VideoProcessorEnumerator_GetVideoProcessorContentDesc(pID3D11VideoProcessorEnumerator, pContentDesc)\
    (pID3D11VideoProcessorEnumerator)->GetVideoProcessorContentDesc(pContentDesc)
#define My_ID3D11VideoProcessorEnumerator_CheckVideoProcessorFormat(pID3D11VideoProcessorEnumerator, Format, pFlags)\
    (pID3D11VideoProcessorEnumerator)->CheckVideoProcessorFormat(Format, pFlags)
#define My_ID3D11VideoProcessorEnumerator_GetVideoProcessorCaps(pID3D11VideoProcessorEnumerator, pCaps)\
    (pID3D11VideoProcessorEnumerator)->GetVideoProcessorCaps(pCaps)
#define My_ID3D11VideoProcessorEnumerator_GetVideoProcessorRateConversionCaps(pID3D11VideoProcessorEnumerator, TypeIndex, pCaps)\
    (pID3D11VideoProcessorEnumerator)->GetVideoProcessorRateConversionCaps(TypeIndex, pCaps)
#define My_ID3D11VideoProcessorEnumerator_GetVideoProcessorCustomRate(pID3D11VideoProcessorEnumerator, TypeIndex, CustomRateIndex, pRate)\
    (pID3D11VideoProcessorEnumerator)->GetVideoProcessorCustomRate(TypeIndex, CustomRateIndex, pRate)
#define My_ID3D11VideoProcessorEnumerator_GetVideoProcessorFilterRange(pID3D11VideoProcessorEnumerator, Filter, pRange)\
    (pID3D11VideoProcessorEnumerator)->GetVideoProcessorFilterRange(Filter, pRange)

#define My_ID3D11VideoProcessor_QueryInterface(pID3D11VideoProcessor, riid, ppvObj)\
    (pID3D11VideoProcessor)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoProcessor_AddRef(pID3D11VideoProcessor)\
    (pID3D11VideoProcessor)->AddRef()
#define My_ID3D11VideoProcessor_Release(pID3D11VideoProcessor)\
    (pID3D11VideoProcessor)->Release()
#define My_ID3D11VideoProcessor_GetContentDesc(pID3D11VideoProcessor, pDesc)\
    (pID3D11VideoProcessor)->GetContentDesc(pDesc)
#define My_ID3D11VideoProcessor_GetRateConversionCaps(pID3D11VideoProcessor, pCaps)\
    (pID3D11VideoProcessor)->GetRateConversionCaps(pCaps)

#define My_ID3D11AuthenticatedChannel_QueryInterface(pID3D11AuthenticatedChannel, riid, ppvObj)\
    (pID3D11AuthenticatedChannel)->QueryInterface(riid, ppvObj)
#define My_ID3D11AuthenticatedChannel_AddRef(pID3D11AuthenticatedChannel)\
    (pID3D11AuthenticatedChannel)->AddRef()
#define My_ID3D11AuthenticatedChannel_Release(pID3D11AuthenticatedChannel)\
    (pID3D11AuthenticatedChannel)->Release()
#define My_ID3D11AuthenticatedChannel_GetCertificateSize(pID3D11AuthenticatedChannel, pCertificateSize)\
    (pID3D11AuthenticatedChannel)->GetCertificateSize(pCertificateSize)
#define My_ID3D11AuthenticatedChannel_GetCertificate(pID3D11AuthenticatedChannel, CertificateSize, pCertificate)\
    (pID3D11AuthenticatedChannel)->GetCertificate(CertificateSize, pCertificate)
#define My_ID3D11AuthenticatedChannel_GetChannelHandle(pID3D11AuthenticatedChannel, pChannelHandle)\
    (pID3D11AuthenticatedChannel)->GetChannelHandle(pChannelHandle)

#define My_ID3D11CryptoSession_QueryInterface(pID3D11CryptoSession, riid, ppvObj)\
    (pID3D11CryptoSession)->QueryInterface(riid, ppvObj)
#define My_ID3D11CryptoSession_AddRef(pID3D11CryptoSession)\
    (pID3D11CryptoSession)->AddRef()
#define My_ID3D11CryptoSession_Release(pID3D11CryptoSession)\
    (pID3D11CryptoSession)->Release()
#define My_ID3D11CryptoSession_GetCryptoType(pID3D11CryptoSession, pCryptoType)\
    (pID3D11CryptoSession)->GetCryptoType(pCryptoType)
#define My_ID3D11CryptoSession_GetDecoderProfile(pID3D11CryptoSession, pDecoderProfile)\
    (pID3D11CryptoSession)->GetDecoderProfile(pDecoderProfile)
#define My_ID3D11CryptoSession_GetCertificateSize(pID3D11CryptoSession, pCertificateSize)\
    (pID3D11CryptoSession)->GetCertificateSize(pCertificateSize)
#define My_ID3D11CryptoSession_GetCertificate(pID3D11CryptoSession, CertificateSize, pCertificate)\
    (pID3D11CryptoSession)->GetCertificate(CertificateSize, pCertificate)
#define My_ID3D11CryptoSession_GetCryptoSessionHandle(pID3D11CryptoSession, pCryptoSessionHandle)\
    (pID3D11CryptoSession)->GetCryptoSessionHandle(pCryptoSessionHandle)

#define My_ID3D11VideoDecoderOutputView_QueryInterface(pID3D11VideoDecoderOutputView, riid, ppvObj)\
    (pID3D11VideoDecoderOutputView)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoDecoderOutputView_AddRef(pID3D11VideoDecoderOutputView)\
    (pID3D11VideoDecoderOutputView)->AddRef()
#define My_ID3D11VideoDecoderOutputView_Release(pID3D11VideoDecoderOutputView)\
    (pID3D11VideoDecoderOutputView)->Release()
#define My_ID3D11VideoDecoderOutputView_GetDesc(pID3D11VideoDecoderOutputView, pDesc)\
    (pID3D11VideoDecoderOutputView)->GetDesc(pDesc)

#define My_ID3D11VideoProcessorInputView_QueryInterface(pID3D11VideoProcessorInputView, riid, ppvObj)\
    (pID3D11VideoProcessorInputView)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoProcessorInputView_AddRef(pID3D11VideoProcessorInputView)\
    (pID3D11VideoProcessorInputView)->AddRef()
#define My_ID3D11VideoProcessorInputView_Release(pID3D11VideoProcessorInputView)\
    (pID3D11VideoProcessorInputView)->Release()
#define My_ID3D11VideoProcessorInputView_GetDesc(pID3D11VideoProcessorInputView, pDesc)\
    (pID3D11VideoProcessorInputView)->GetDesc(pDesc)

#define My_ID3D11VideoProcessorOutputView_QueryInterface(pID3D11VideoProcessorOutputView, riid, ppvObj)\
    (pID3D11VideoProcessorOutputView)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoProcessorOutputView_AddRef(pID3D11VideoProcessorOutputView)\
    (pID3D11VideoProcessorOutputView)->AddRef()
#define My_ID3D11VideoProcessorOutputView_Release(pID3D11VideoProcessorOutputView)\
    (pID3D11VideoProcessorOutputView)->Release()
#define My_ID3D11VideoProcessorOutputView_GetDesc(pID3D11VideoProcessorOutputView, pDesc)\
    (pID3D11VideoProcessorOutputView)->GetDesc(pDesc)

#define My_ID3D11VideoContext_QueryInterface(pID3D11VideoContext, riid, ppvObj)\
    (pID3D11VideoContext)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoContext_AddRef(pID3D11VideoContext)\
    (pID3D11VideoContext)->AddRef()
#define My_ID3D11VideoContext_Release(pID3D11VideoContext)\
    (pID3D11VideoContext)->Release()
#define My_ID3D11VideoContext_GetDecoderBuffer(pID3D11VideoContext, pDecoder, Type, pBufferSize, ppBuffer)\
    (pID3D11VideoContext)->GetDecoderBuffer(pDecoder, Type, pBufferSize, ppBuffer)
#define My_ID3D11VideoContext_ReleaseDecoderBuffer(pID3D11VideoContext, pDecoder, Type)\
    (pID3D11VideoContext)->ReleaseDecoderBuffer(pDecoder, Type)
#define My_ID3D11VideoContext_DecoderBeginFrame(pID3D11VideoContext, pDecoder, pView, ContentKeySize, pContentKey)\
    (pID3D11VideoContext)->DecoderBeginFrame(pDecoder, pView, ContentKeySize, pContentKey)
#define My_ID3D11VideoContext_DecoderEndFrame(pID3D11VideoContext, pDecoder)\
    (pID3D11VideoContext)->DecoderEndFrame(pDecoder)
#define My_ID3D11VideoContext_SubmitDecoderBuffers(pID3D11VideoContext, pDecoder, NumBuffers, pBufferDesc)\
    (pID3D11VideoContext)->SubmitDecoderBuffers(pDecoder, NumBuffers, pBufferDesc)
#define My_ID3D11VideoContext_DecoderExtension(pID3D11VideoContext, pDecoder, pExtensionData)\
    (pID3D11VideoContext)->DecoderExtension(pDecoder, pExtensionData)
#define My_ID3D11VideoContext_VideoProcessorSetOutputTargetRect(pID3D11VideoContext, pVideoProcessor, Enable, pRect)\
    (pID3D11VideoContext)->VideoProcessorSetOutputTargetRect(pVideoProcessor, Enable, pRect)
#define My_ID3D11VideoContext_VideoProcessorSetOutputBackgroundColor(pID3D11VideoContext, pVideoProcessor, YCbCr, pColor)\
    (pID3D11VideoContext)->VideoProcessorSetOutputBackgroundColor(pVideoProcessor, YCbCr, pColor)
#define My_ID3D11VideoContext_VideoProcessorSetOutputColorSpace(pID3D11VideoContext, pVideoProcessor, pColorSpace)\
    (pID3D11VideoContext)->VideoProcessorSetOutputColorSpace(pVideoProcessor, pColorSpace)
#define My_ID3D11VideoContext_VideoProcessorSetOutputAlphaFillMode(pID3D11VideoContext, pVideoProcessor, AlphaFillMode, StreamIndex)\
    (pID3D11VideoContext)->VideoProcessorSetOutputAlphaFillMode(pVideoProcessor, AlphaFillMode, StreamIndex)
#define My_ID3D11VideoContext_VideoProcessorSetOutputConstriction(pID3D11VideoContext, pVideoProcessor, Enable, Size)\
    (pID3D11VideoContext)->VideoProcessorSetOutputConstriction(pVideoProcessor, Enable, Size)
#define My_ID3D11VideoContext_VideoProcessorSetOutputStereoMode(pID3D11VideoContext, pVideoProcessor, Enable)\
    (pID3D11VideoContext)->VideoProcessorSetOutputStereoMode(pVideoProcessor, Enable)
#define My_ID3D11VideoContext_VideoProcessorSetOutputExtension(pID3D11VideoContext, pVideoProcessor, pExtensionGuid, DataSize, pData)\
    (pID3D11VideoContext)->VideoProcessorSetOutputExtension(pVideoProcessor, pExtensionGuid, DataSize, pData)
#define My_ID3D11VideoContext_VideoProcessorGetOutputTargetRect(pID3D11VideoContext, pVideoProcessor, Enabled, pRect)\
    (pID3D11VideoContext)->VideoProcessorGetOutputTargetRect(pVideoProcessor, Enabled, pRect)
#define My_ID3D11VideoContext_VideoProcessorGetOutputBackgroundColor(pID3D11VideoContext, pVideoProcessor, pYCbCr, pColor)\
    (pID3D11VideoContext)->VideoProcessorGetOutputBackgroundColor(pVideoProcessor, pYCbCr, pColor)
#define My_ID3D11VideoContext_VideoProcessorGetOutputColorSpace(pID3D11VideoContext, pVideoProcessor, pColorSpace)\
    (pID3D11VideoContext)->VideoProcessorGetOutputColorSpace(pVideoProcessor, pColorSpace)
#define My_ID3D11VideoContext_VideoProcessorGetOutputAlphaFillMode(pID3D11VideoContext, pVideoProcessor, pAlphaFillMode, pStreamIndex)\
    (pID3D11VideoContext)->VideoProcessorGetOutputAlphaFillMode(pVideoProcessor, pAlphaFillMode, pStreamIndex)
#define My_ID3D11VideoContext_VideoProcessorGetOutputConstriction(pID3D11VideoContext, pVideoProcessor, pEnabled, pSize)\
    (pID3D11VideoContext)->VideoProcessorGetOutputConstriction(pVideoProcessor, pEnabled, pSize)
#define My_ID3D11VideoContext_VideoProcessorGetOutputStereoMode(pID3D11VideoContext, pVideoProcessor, pEnabled)\
    (pID3D11VideoContext)->VideoProcessorGetOutputStereoMode(pVideoProcessor, pEnabled)
#define My_ID3D11VideoContext_VideoProcessorGetOutputExtension(pID3D11VideoContext, pVideoProcessor, pExtensionGuid, DataSize, pData)\
    (pID3D11VideoContext)->VideoProcessorGetOutputExtension(pVideoProcessor, pExtensionGuid, DataSize, pData)
#define My_ID3D11VideoContext_VideoProcessorSetStreamFrameFormat(pID3D11VideoContext, pVideoProcessor, StreamIndex, FrameFormat)\
    (pID3D11VideoContext)->VideoProcessorSetStreamFrameFormat(pVideoProcessor, StreamIndex, FrameFormat)
#define My_ID3D11VideoContext_VideoProcessorSetStreamColorSpace(pID3D11VideoContext, pVideoProcessor, StreamIndex, pColorSpace)\
    (pID3D11VideoContext)->VideoProcessorSetStreamColorSpace(pVideoProcessor, StreamIndex, pColorSpace)
#define My_ID3D11VideoContext_VideoProcessorSetStreamOutputRate(pID3D11VideoContext, pVideoProcessor, StreamIndex, OutputRate, RepeatFrame, pCustomRate)\
    (pID3D11VideoContext)->VideoProcessorSetStreamOutputRate(pVideoProcessor, StreamIndex, OutputRate, RepeatFrame, pCustomRate)
#define My_ID3D11VideoContext_VideoProcessorSetStreamSourceRect(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable, pRect)\
    (pID3D11VideoContext)->VideoProcessorSetStreamSourceRect(pVideoProcessor, StreamIndex, Enable, pRect)
#define My_ID3D11VideoContext_VideoProcessorSetStreamDestRect(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable, pRect)\
    (pID3D11VideoContext)->VideoProcessorSetStreamDestRect(pVideoProcessor, StreamIndex, Enable, pRect)
#define My_ID3D11VideoContext_VideoProcessorSetStreamAlpha(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable, Alpha)\
    (pID3D11VideoContext)->VideoProcessorSetStreamAlpha(pVideoProcessor, StreamIndex, Enable, Alpha)
#define My_ID3D11VideoContext_VideoProcessorSetStreamPalette(pID3D11VideoContext, pVideoProcessor, StreamIndex, Count, pEntries)\
    (pID3D11VideoContext)->VideoProcessorSetStreamPalette(pVideoProcessor, StreamIndex, Count, pEntries)
#define My_ID3D11VideoContext_VideoProcessorSetStreamPixelAspectRatio(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable, pSourceAspectRatio, pDestinationAspectRatio)\
    (pID3D11VideoContext)->VideoProcessorSetStreamPixelAspectRatio(pVideoProcessor, StreamIndex, Enable, pSourceAspectRatio, pDestinationAspectRatio)
#define My_ID3D11VideoContext_VideoProcessorSetStreamLumaKey(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable, Lower, Upper)\
    (pID3D11VideoContext)->VideoProcessorSetStreamLumaKey(pVideoProcessor, StreamIndex, Enable, Lower, Upper)
#define My_ID3D11VideoContext_VideoProcessorSetStreamStereoFormat(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable, Format, LeftViewFrame0, BaseViewFrame0, FlipMode, MonoOffset)\
    (pID3D11VideoContext)->VideoProcessorSetStreamStereoFormat(pVideoProcessor, StreamIndex, Enable, Format, LeftViewFrame0, BaseViewFrame0, FlipMode, MonoOffset)
#define My_ID3D11VideoContext_VideoProcessorSetStreamAutoProcessingMode(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable)\
    (pID3D11VideoContext)->VideoProcessorSetStreamAutoProcessingMode(pVideoProcessor, StreamIndex, Enable)
#define My_ID3D11VideoContext_VideoProcessorSetStreamFilter(pID3D11VideoContext, pVideoProcessor, StreamIndex, Filter, Enable, Level)\
    (pID3D11VideoContext)->VideoProcessorSetStreamFilter(pVideoProcessor, StreamIndex, Filter, Enable, Level)
#define My_ID3D11VideoContext_VideoProcessorSetStreamExtension(pID3D11VideoContext, pVideoProcessor, StreamIndex, pExtensionGuid, DataSize, pData)\
    (pID3D11VideoContext)->VideoProcessorSetStreamExtension(pVideoProcessor, StreamIndex, pExtensionGuid, DataSize, pData)
#define My_ID3D11VideoContext_VideoProcessorGetStreamFrameFormat(pID3D11VideoContext, pVideoProcessor, StreamIndex, pFrameFormat)\
    (pID3D11VideoContext)->VideoProcessorGetStreamFrameFormat(pVideoProcessor, StreamIndex, pFrameFormat)
#define My_ID3D11VideoContext_VideoProcessorGetStreamColorSpace(pID3D11VideoContext, pVideoProcessor, StreamIndex, pColorSpace)\
    (pID3D11VideoContext)->VideoProcessorGetStreamColorSpace(pVideoProcessor, StreamIndex, pColorSpace)
#define My_ID3D11VideoContext_VideoProcessorGetStreamOutputRate(pID3D11VideoContext, pVideoProcessor, StreamIndex, pOutputRate, pRepeatFrame, pCustomRate)\
    (pID3D11VideoContext)->VideoProcessorGetStreamOutputRate(pVideoProcessor, StreamIndex, pOutputRate, pRepeatFrame, pCustomRate)
#define My_ID3D11VideoContext_VideoProcessorGetStreamSourceRect(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnabled, pRect)\
    (pID3D11VideoContext)->VideoProcessorGetStreamSourceRect(pVideoProcessor, StreamIndex, pEnabled, pRect)
#define My_ID3D11VideoContext_VideoProcessorGetStreamDestRect(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnabled, pRect)\
    (pID3D11VideoContext)->VideoProcessorGetStreamDestRect(pVideoProcessor, StreamIndex, pEnabled, pRect)
#define My_ID3D11VideoContext_VideoProcessorGetStreamAlpha(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnabled, pAlpha)\
    (pID3D11VideoContext)->VideoProcessorGetStreamAlpha(pVideoProcessor, StreamIndex, pEnabled, pAlpha)
#define My_ID3D11VideoContext_VideoProcessorGetStreamPalette(pID3D11VideoContext, pVideoProcessor, StreamIndex, Count, pEntries)\
    (pID3D11VideoContext)->VideoProcessorGetStreamPalette(pVideoProcessor, StreamIndex, Count, pEntries)
#define My_ID3D11VideoContext_VideoProcessorGetStreamPixelAspectRatio(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnabled, pSourceAspectRatio, pDestinationAspectRatio)\
    (pID3D11VideoContext)->VideoProcessorGetStreamPixelAspectRatio(pVideoProcessor, StreamIndex, pEnabled, pSourceAspectRatio, pDestinationAspectRatio)
#define My_ID3D11VideoContext_VideoProcessorGetStreamLumaKey(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnabled, pLower, pUpper)\
    (pID3D11VideoContext)->VideoProcessorGetStreamLumaKey(pVideoProcessor, StreamIndex, pEnabled, pLower, pUpper)
#define My_ID3D11VideoContext_VideoProcessorGetStreamStereoFormat(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnable, pFormat, pLeftViewFrame0, pBaseViewFrame0, pFlipMode, MonoOffset)\
    (pID3D11VideoContext)->VideoProcessorGetStreamStereoFormat(pVideoProcessor, StreamIndex, pEnable, pFormat, pLeftViewFrame0, pBaseViewFrame0, pFlipMode, MonoOffset)
#define My_ID3D11VideoContext_VideoProcessorGetStreamAutoProcessingMode(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnabled)\
    (pID3D11VideoContext)->VideoProcessorGetStreamAutoProcessingMode(pVideoProcessor, StreamIndex, pEnabled)
#define My_ID3D11VideoContext_VideoProcessorGetStreamFilter(pID3D11VideoContext, pVideoProcessor, StreamIndex, Filter, pEnabled, pLevel)\
    (pID3D11VideoContext)->VideoProcessorGetStreamFilter(pVideoProcessor, StreamIndex, Filter, pEnabled, pLevel)
#define My_ID3D11VideoContext_VideoProcessorGetStreamExtension(pID3D11VideoContext, pVideoProcessor, StreamIndex, pExtensionGuid, DataSize, pData)\
    (pID3D11VideoContext)->VideoProcessorGetStreamExtension(pVideoProcessor, StreamIndex, pExtensionGuid, DataSize, pData)
#define My_ID3D11VideoContext_VideoProcessorBlt(pID3D11VideoContext, pVideoProcessor, pView, OutputFrame, StreamCount, pStreams)\
    (pID3D11VideoContext)->VideoProcessorBlt(pVideoProcessor, pView, OutputFrame, StreamCount, pStreams)
#define My_ID3D11VideoContext_NegotiateCryptoSessionKeyExchange(pID3D11VideoContext, pCryptoSession, DataSize, pData)\
    (pID3D11VideoContext)->NegotiateCryptoSessionKeyExchange(pCryptoSession, DataSize, pData)
#define My_ID3D11VideoContext_EncryptionBlt(pID3D11VideoContext, pCryptoSession, pSrcSurface, pDstSurface, IVSize, pIV)\
    (pID3D11VideoContext)->EncryptionBlt(pCryptoSession, pSrcSurface, pDstSurface, IVSize, pIV)
#define My_ID3D11VideoContext_DecryptionBlt(pID3D11VideoContext, pCryptoSession, pSrcSurface, pDstSurface, pEncryptedBlockInfo, ContentKeySize, pContentKey, IVSize, pIV)\
    (pID3D11VideoContext)->DecryptionBlt(pCryptoSession, pSrcSurface, pDstSurface, pEncryptedBlockInfo, ContentKeySize, pContentKey, IVSize, pIV)
#define My_ID3D11VideoContext_StartSessionKeyRefresh(pID3D11VideoContext, pCryptoSession, RandomNumberSize, pRandomNumber)\
    (pID3D11VideoContext)->StartSessionKeyRefresh(pCryptoSession, RandomNumberSize, pRandomNumber)
#define My_ID3D11VideoContext_FinishSessionKeyRefresh(pID3D11VideoContext, pCryptoSession)\
    (pID3D11VideoContext)->FinishSessionKeyRefresh(pCryptoSession)
#define My_ID3D11VideoContext_GetEncryptionBltKey(pID3D11VideoContext, pCryptoSession, KeySize, pReadbackKey)\
    (pID3D11VideoContext)->GetEncryptionBltKey(pCryptoSession, KeySize, pReadbackKey)
#define My_ID3D11VideoContext_NegotiateAuthenticatedChannelKeyExchange(pID3D11VideoContext, pChannel, DataSize, pData)\
    (pID3D11VideoContext)->NegotiateAuthenticatedChannelKeyExchange(pChannel, DataSize, pData)
#define My_ID3D11VideoContext_QueryAuthenticatedChannel(pID3D11VideoContext, pChannel, InputSize, pInput, OutputSize, pOutput)\
    (pID3D11VideoContext)->QueryAuthenticatedChannel(pChannel, InputSize, pInput, OutputSize, pOutput)
#define My_ID3D11VideoContext_ConfigureAuthenticatedChannel(pID3D11VideoContext, pChannel, InputSize, pInput, pOutput)\
    (pID3D11VideoContext)->ConfigureAuthenticatedChannel(pChannel, InputSize, pInput, pOutput)
#define My_ID3D11VideoContext_VideoProcessorSetStreamRotation(pID3D11VideoContext, pVideoProcessor, StreamIndex, Enable, Rotation)\
    (pID3D11VideoContext)->VideoProcessorSetStreamRotation(pVideoProcessor, StreamIndex, Enable, Rotation)
#define My_ID3D11VideoContext_VideoProcessorGetStreamRotation(pID3D11VideoContext, pVideoProcessor, StreamIndex, pEnable, pRotation)\
    (pID3D11VideoContext)->VideoProcessorGetStreamRotation(pVideoProcessor, StreamIndex, pEnable, pRotation)

#define My_ID3D11VideoDevice_QueryInterface(pID3D11VideoDevice, riid, ppvObj)\
    (pID3D11VideoDevice)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoDevice_AddRef(pID3D11VideoDevice)\
    (pID3D11VideoDevice)->AddRef()
#define My_ID3D11VideoDevice_Release(pID3D11VideoDevice)\
    (pID3D11VideoDevice)->Release()
#define My_ID3D11VideoDevice_CreateVideoDecoder(pID3D11VideoDevice, pVideoDesc, pConfig, ppDecoder)\
    (pID3D11VideoDevice)->CreateVideoDecoder(pVideoDesc, pConfig, ppDecoder)
#define My_ID3D11VideoDevice_CreateVideoProcessor(pID3D11VideoDevice, pEnum, RateConversionIndex, ppVideoProcessor)\
    (pID3D11VideoDevice)->CreateVideoProcessor(pEnum, RateConversionIndex, ppVideoProcessor)
#define My_ID3D11VideoDevice_CreateAuthenticatedChannel(pID3D11VideoDevice, ChannelType, ppAuthenticatedChannel)\
    (pID3D11VideoDevice)->CreateAuthenticatedChannel(ChannelType, ppAuthenticatedChannel)
#define My_ID3D11VideoDevice_CreateCryptoSession(pID3D11VideoDevice, pCryptoType, pDecoderProfile, pKeyExchangeType, ppCryptoSession)\
    (pID3D11VideoDevice)->CreateCryptoSession(pCryptoType, pDecoderProfile, pKeyExchangeType, ppCryptoSession)
#define My_ID3D11VideoDevice_CreateVideoDecoderOutputView(pID3D11VideoDevice, pResource, pDesc, ppVDOVView)\
    (pID3D11VideoDevice)->CreateVideoDecoderOutputView(pResource, pDesc, ppVDOVView)
#define My_ID3D11VideoDevice_CreateVideoProcessorInputView(pID3D11VideoDevice, pResource, pEnum, pDesc, ppVPIView)\
    (pID3D11VideoDevice)->CreateVideoProcessorInputView(pResource, pEnum, pDesc, ppVPIView)
#define My_ID3D11VideoDevice_CreateVideoProcessorOutputView(pID3D11VideoDevice, pResource, pEnum, pDesc, ppVPOView)\
    (pID3D11VideoDevice)->CreateVideoProcessorOutputView(pResource, pEnum, pDesc, ppVPOView)
#define My_ID3D11VideoDevice_CreateVideoProcessorEnumerator(pID3D11VideoDevice, pDesc, ppEnum)\
    (pID3D11VideoDevice)->CreateVideoProcessorEnumerator(pDesc, ppEnum)
#define My_ID3D11VideoDevice_GetVideoDecoderProfileCount(pID3D11VideoDevice)\
    (pID3D11VideoDevice)->GetVideoDecoderProfileCount()
#define My_ID3D11VideoDevice_GetVideoDecoderProfile(pID3D11VideoDevice, Index, pDecoderProfile)\
    (pID3D11VideoDevice)->GetVideoDecoderProfile(Index, pDecoderProfile)
#define My_ID3D11VideoDevice_CheckVideoDecoderFormat(pID3D11VideoDevice, pDecoderProfile, Format, pSupported)\
    (pID3D11VideoDevice)->CheckVideoDecoderFormat(pDecoderProfile, Format, pSupported)
#define My_ID3D11VideoDevice_GetVideoDecoderConfigCount(pID3D11VideoDevice, pDesc, pCount)\
    (pID3D11VideoDevice)->GetVideoDecoderConfigCount(pDesc, pCount)
#define My_ID3D11VideoDevice_GetVideoDecoderConfig(pID3D11VideoDevice, pDesc, Index, pConfig)\
    (pID3D11VideoDevice)->GetVideoDecoderConfig(pDesc, Index, pConfig)
#define My_ID3D11VideoDevice_GetContentProtectionCaps(pID3D11VideoDevice, pCryptoType, pDecoderProfile, pCaps)\
    (pID3D11VideoDevice)->GetContentProtectionCaps(pCryptoType, pDecoderProfile, pCaps)
#define My_ID3D11VideoDevice_CheckCryptoKeyExchange(pID3D11VideoDevice, pCryptoType, pDecoderProfile, Index, pKeyExchangeType)\
    (pID3D11VideoDevice)->CheckCryptoKeyExchange(pCryptoType, pDecoderProfile, Index, pKeyExchangeType)
#define My_ID3D11VideoDevice_SetPrivateData(pID3D11VideoDevice, guid, DataSize, pData)\
    (pID3D11VideoDevice)->SetPrivateData(guid, DataSize, pData)
#define My_ID3D11VideoDevice_SetPrivateDataInterface(pID3D11VideoDevice, guid, pData)\
    (pID3D11VideoDevice)->SetPrivateDataInterface(guid, pData)

#define My_ID3D11BlendState1_QueryInterface(pID3D11BlendState1, riid, ppvObj)\
    (pID3D11BlendState1)->QueryInterface(riid, ppvObj)
#define My_ID3D11BlendState1_AddRef(pID3D11BlendState1)\
    (pID3D11BlendState1)->AddRef()
#define My_ID3D11BlendState1_Release(pID3D11BlendState1)\
    (pID3D11BlendState1)->Release()
#define My_ID3D11BlendState1_GetDesc1(pID3D11BlendState1, pDesc)\
    (pID3D11BlendState1)->GetDesc1(pDesc)

#define My_ID3D11RasterizerState1_QueryInterface(pID3D11RasterizerState1, riid, ppvObj)\
    (pID3D11RasterizerState1)->QueryInterface(riid, ppvObj)
#define My_ID3D11RasterizerState1_AddRef(pID3D11RasterizerState1)\
    (pID3D11RasterizerState1)->AddRef()
#define My_ID3D11RasterizerState1_Release(pID3D11RasterizerState1)\
    (pID3D11RasterizerState1)->Release()
#define My_ID3D11RasterizerState1_GetDesc1(pID3D11RasterizerState1, pDesc)\
    (pID3D11RasterizerState1)->GetDesc1(pDesc)

#define My_ID3DDeviceContextState_QueryInterface(pID3DDeviceContextState, riid, ppvObj)\
    (pID3DDeviceContextState)->QueryInterface(riid, ppvObj)
#define My_ID3DDeviceContextState_AddRef(pID3DDeviceContextState)\
    (pID3DDeviceContextState)->AddRef()
#define My_ID3DDeviceContextState_Release(pID3DDeviceContextState)\
    (pID3DDeviceContextState)->Release()

#define My_ID3D11DeviceContext1_QueryInterface(pID3D11DeviceContext1, riid, ppvObj)\
    (pID3D11DeviceContext1)->QueryInterface(riid, ppvObj)
#define My_ID3D11DeviceContext1_AddRef(pID3D11DeviceContext1)\
    (pID3D11DeviceContext1)->AddRef()
#define My_ID3D11DeviceContext1_Release(pID3D11DeviceContext1)\
    (pID3D11DeviceContext1)->Release()
#define My_ID3D11DeviceContext1_CopySubresourceRegion1(pID3D11DeviceContext1, pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox, CopyFlags)\
    (pID3D11DeviceContext1)->CopySubresourceRegion1(pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox, CopyFlags)
#define My_ID3D11DeviceContext1_UpdateSubresource1(pID3D11DeviceContext1, pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch, CopyFlags)\
    (pID3D11DeviceContext1)->UpdateSubresource1(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch, CopyFlags)
#define My_ID3D11DeviceContext1_DiscardResource(pID3D11DeviceContext1, pResource)\
    (pID3D11DeviceContext1)->DiscardResource(pResource)
#define My_ID3D11DeviceContext1_DiscardView(pID3D11DeviceContext1, pResourceView)\
    (pID3D11DeviceContext1)->DiscardView(pResourceView)
#define My_ID3D11DeviceContext1_VSSetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->VSSetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_HSSetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->HSSetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_DSSetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->DSSetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_GSSetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->GSSetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_PSSetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->PSSetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_CSSetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->CSSetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_VSGetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->VSGetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_HSGetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->HSGetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_DSGetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->DSGetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_GSGetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->GSGetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_PSGetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->PSGetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_CSGetConstantBuffers1(pID3D11DeviceContext1, StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)\
    (pID3D11DeviceContext1)->CSGetConstantBuffers1(StartSlot, NumBuffers, ppConstantBuffers, pFirstConstant, pNumConstants)
#define My_ID3D11DeviceContext1_SwapDeviceContextState(pID3D11DeviceContext1, pState, ppPreviousState)\
    (pID3D11DeviceContext1)->SwapDeviceContextState(pState, ppPreviousState)
#define My_ID3D11DeviceContext1_ClearView(pID3D11DeviceContext1, pView, Color, pRect, NumRects)\
    (pID3D11DeviceContext1)->ClearView(pView, Color, pRect, NumRects)
#define My_ID3D11DeviceContext1_DiscardView1(pID3D11DeviceContext1, pResourceView, pRects, NumRects)\
    (pID3D11DeviceContext1)->DiscardView1(pResourceView, pRects, NumRects)

#define My_ID3D11Device1_QueryInterface(pID3D11Device1, riid, ppvObj)\
    (pID3D11Device1)->QueryInterface(riid, ppvObj)
#define My_ID3D11Device1_AddRef(pID3D11Device1)\
    (pID3D11Device1)->AddRef()
#define My_ID3D11Device1_Release(pID3D11Device1)\
    (pID3D11Device1)->Release()
#define My_ID3D11Device1_GetImmediateContext1(pID3D11Device1, ppImmediateContext)\
    (pID3D11Device1)->GetImmediateContext1(ppImmediateContext)
#define My_ID3D11Device1_CreateDeferredContext1(pID3D11Device1, ContextFlags, ppDeferredContext)\
    (pID3D11Device1)->CreateDeferredContext1(ContextFlags, ppDeferredContext)
#define My_ID3D11Device1_CreateBlendState1(pID3D11Device1, pBlendStateDesc, ppBlendState)\
    (pID3D11Device1)->CreateBlendState1(pBlendStateDesc, ppBlendState)
#define My_ID3D11Device1_CreateRasterizerState1(pID3D11Device1, pRasterizerDesc, ppRasterizerState)\
    (pID3D11Device1)->CreateRasterizerState1(pRasterizerDesc, ppRasterizerState)
#define My_ID3D11Device1_CreateDeviceContextState(pID3D11Device1, Flags, pFeatureLevels, FeatureLevels, SDKVersion, EmulatedInterface, pChosenFeatureLevel, ppContextState)\
    (pID3D11Device1)->CreateDeviceContextState(Flags, pFeatureLevels, FeatureLevels, SDKVersion, EmulatedInterface, pChosenFeatureLevel, ppContextState)
#define My_ID3D11Device1_OpenSharedResource1(pID3D11Device1, hResource, returnedInterface, ppResource)\
    (pID3D11Device1)->OpenSharedResource1(hResource, returnedInterface, ppResource)
#define My_ID3D11Device1_OpenSharedResourceByName(pID3D11Device1, lpName, dwDesiredAccess, returnedInterface, ppResource)\
    (pID3D11Device1)->OpenSharedResourceByName(lpName, dwDesiredAccess, returnedInterface, ppResource)

#define My_ID3DUserDefinedAnnotation_QueryInterface(pID3DUserDefinedAnnotation, riid, ppvObj)\
    (pID3DUserDefinedAnnotation)->QueryInterface(riid, ppvObj)
#define My_ID3DUserDefinedAnnotation_AddRef(pID3DUserDefinedAnnotation)\
    (pID3DUserDefinedAnnotation)->AddRef()
#define My_ID3DUserDefinedAnnotation_Release(pID3DUserDefinedAnnotation)\
    (pID3DUserDefinedAnnotation)->Release()
#define My_ID3DUserDefinedAnnotation_BeginEvent(pID3DUserDefinedAnnotation, Name)\
    (pID3DUserDefinedAnnotation)->BeginEvent(Name)
#define My_ID3DUserDefinedAnnotation_EndEvent(pID3DUserDefinedAnnotation)\
    (pID3DUserDefinedAnnotation)->EndEvent()
#define My_ID3DUserDefinedAnnotation_SetMarker(pID3DUserDefinedAnnotation, Name)\
    (pID3DUserDefinedAnnotation)->SetMarker(Name)
#define My_ID3DUserDefinedAnnotation_GetStatus(pID3DUserDefinedAnnotation)\
    (pID3DUserDefinedAnnotation)->GetStatus()

#define My_ID3D11VideoContext1_QueryInterface(pID3D11VideoContext1, riid, ppvObj)\
    (pID3D11VideoContext1)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoContext1_AddRef(pID3D11VideoContext1)\
    (pID3D11VideoContext1)->AddRef()
#define My_ID3D11VideoContext1_Release(pID3D11VideoContext1)\
    (pID3D11VideoContext1)->Release()
#define My_ID3D11VideoContext1_SubmitDecoderBuffers1(pID3D11VideoContext1, pDecoder, NumBuffers, pBufferDesc)\
    (pID3D11VideoContext1)->SubmitDecoderBuffers1(pDecoder, NumBuffers, pBufferDesc)
#define My_ID3D11VideoContext1_GetDataForNewHardwareKey(pID3D11VideoContext1, pCryptoSession, PrivateInputSize, pPrivatInputData, pPrivateOutputData)\
    (pID3D11VideoContext1)->GetDataForNewHardwareKey(pCryptoSession, PrivateInputSize, pPrivatInputData, pPrivateOutputData)
#define My_ID3D11VideoContext1_CheckCryptoSessionStatus(pID3D11VideoContext1, pCryptoSession, pStatus)\
    (pID3D11VideoContext1)->CheckCryptoSessionStatus(pCryptoSession, pStatus)
#define My_ID3D11VideoContext1_DecoderEnableDownsampling(pID3D11VideoContext1, pDecoder, InputColorSpace, pOutputDesc, ReferenceFrameCount)\
    (pID3D11VideoContext1)->DecoderEnableDownsampling(pDecoder, InputColorSpace, pOutputDesc, ReferenceFrameCount)
#define My_ID3D11VideoContext1_DecoderUpdateDownsampling(pID3D11VideoContext1, pDecoder, pOutputDesc)\
    (pID3D11VideoContext1)->DecoderUpdateDownsampling(pDecoder, pOutputDesc)
#define My_ID3D11VideoContext1_VideoProcessorSetOutputColorSpace1(pID3D11VideoContext1, pVideoProcessor, ColorSpace)\
    (pID3D11VideoContext1)->VideoProcessorSetOutputColorSpace1(pVideoProcessor, ColorSpace)
#define My_ID3D11VideoContext1_VideoProcessorSetOutputShaderUsage(pID3D11VideoContext1, pVideoProcessor, ShaderUsage)\
    (pID3D11VideoContext1)->VideoProcessorSetOutputShaderUsage(pVideoProcessor, ShaderUsage)
#define My_ID3D11VideoContext1_VideoProcessorGetOutputColorSpace1(pID3D11VideoContext1, pVideoProcessor, pColorSpace)\
    (pID3D11VideoContext1)->VideoProcessorGetOutputColorSpace1(pVideoProcessor, pColorSpace)
#define My_ID3D11VideoContext1_VideoProcessorGetOutputShaderUsage(pID3D11VideoContext1, pVideoProcessor, pShaderUsage)\
    (pID3D11VideoContext1)->VideoProcessorGetOutputShaderUsage(pVideoProcessor, pShaderUsage)
#define My_ID3D11VideoContext1_VideoProcessorSetStreamColorSpace1(pID3D11VideoContext1, pVideoProcessor, StreamIndex, ColorSpace)\
    (pID3D11VideoContext1)->VideoProcessorSetStreamColorSpace1(pVideoProcessor, StreamIndex, ColorSpace)
#define My_ID3D11VideoContext1_VideoProcessorSetStreamMirror(pID3D11VideoContext1, pVideoProcessor, StreamIndex, Enable, FlipHorizontal, FlipVertical)\
    (pID3D11VideoContext1)->VideoProcessorSetStreamMirror(pVideoProcessor, StreamIndex, Enable, FlipHorizontal, FlipVertical)
#define My_ID3D11VideoContext1_VideoProcessorGetStreamColorSpace1(pID3D11VideoContext1, pVideoProcessor, StreamIndex, pColorSpace)\
    (pID3D11VideoContext1)->VideoProcessorGetStreamColorSpace1(pVideoProcessor, StreamIndex, pColorSpace)
#define My_ID3D11VideoContext1_VideoProcessorGetStreamMirror(pID3D11VideoContext1, pVideoProcessor, StreamIndex, pEnable, pFlipHorizontal, pFlipVertical)\
    (pID3D11VideoContext1)->VideoProcessorGetStreamMirror(pVideoProcessor, StreamIndex, pEnable, pFlipHorizontal, pFlipVertical)
#define My_ID3D11VideoContext1_VideoProcessorGetBehaviorHints(pID3D11VideoContext1, pVideoProcessor, OutputWidth, OutputHeight, OutputFormat, StreamCount, pStreams, pBehaviorHints)\
    (pID3D11VideoContext1)->VideoProcessorGetBehaviorHints(pVideoProcessor, OutputWidth, OutputHeight, OutputFormat, StreamCount, pStreams, pBehaviorHints)

#define My_ID3D11VideoDevice1_QueryInterface(pID3D11VideoDevice1, riid, ppvObj)\
    (pID3D11VideoDevice1)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoDevice1_AddRef(pID3D11VideoDevice1)\
    (pID3D11VideoDevice1)->AddRef()
#define My_ID3D11VideoDevice1_Release(pID3D11VideoDevice1)\
    (pID3D11VideoDevice1)->Release()
#define My_ID3D11VideoDevice1_GetCryptoSessionPrivateDataSize(pID3D11VideoDevice1, pCryptoType, pDecoderProfile, pKeyExchangeType, pPrivateInputSize, pPrivateOutputSize)\
    (pID3D11VideoDevice1)->GetCryptoSessionPrivateDataSize(pCryptoType, pDecoderProfile, pKeyExchangeType, pPrivateInputSize, pPrivateOutputSize)
#define My_ID3D11VideoDevice1_GetVideoDecoderCaps(pID3D11VideoDevice1, pDecoderProfile, SampleWidth, SampleHeight, pFrameRate, BitRate, pCryptoType, pDecoderCaps)\
    (pID3D11VideoDevice1)->GetVideoDecoderCaps(pDecoderProfile, SampleWidth, SampleHeight, pFrameRate, BitRate, pCryptoType, pDecoderCaps)
#define My_ID3D11VideoDevice1_CheckVideoDecoderDownsampling(pID3D11VideoDevice1, pInputDesc, InputColorSpace, pInputConfig, pFrameRate, pOutputDesc, pSupported, pRealTimeHint)\
    (pID3D11VideoDevice1)->CheckVideoDecoderDownsampling(pInputDesc, InputColorSpace, pInputConfig, pFrameRate, pOutputDesc, pSupported, pRealTimeHint)
#define My_ID3D11VideoDevice1_RecommendVideoDecoderDownsampleParameters(pID3D11VideoDevice1, pInputDesc, InputColorSpace, pInputConfig, pFrameRate, pRecommendedOutputDesc)\
    (pID3D11VideoDevice1)->RecommendVideoDecoderDownsampleParameters(pInputDesc, InputColorSpace, pInputConfig, pFrameRate, pRecommendedOutputDesc)

#define My_ID3D11VideoProcessorEnumerator1_QueryInterface(pID3D11VideoProcessorEnumerator1, riid, ppvObj)\
    (pID3D11VideoProcessorEnumerator1)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoProcessorEnumerator1_AddRef(pID3D11VideoProcessorEnumerator1)\
    (pID3D11VideoProcessorEnumerator1)->AddRef()
#define My_ID3D11VideoProcessorEnumerator1_Release(pID3D11VideoProcessorEnumerator1)\
    (pID3D11VideoProcessorEnumerator1)->Release()
#define My_ID3D11VideoProcessorEnumerator1_CheckVideoProcessorFormatConversion(pID3D11VideoProcessorEnumerator1, InputFormat, InputColorSpace, OutputFormat, OutputColorSpace, pSupported)\
    (pID3D11VideoProcessorEnumerator1)->CheckVideoProcessorFormatConversion(InputFormat, InputColorSpace, OutputFormat, OutputColorSpace, pSupported)

#define My_ID3D11DeviceContext2_QueryInterface(pID3D11DeviceContext2, riid, ppvObj)\
    (pID3D11DeviceContext2)->QueryInterface(riid, ppvObj)
#define My_ID3D11DeviceContext2_AddRef(pID3D11DeviceContext2)\
    (pID3D11DeviceContext2)->AddRef()
#define My_ID3D11DeviceContext2_Release(pID3D11DeviceContext2)\
    (pID3D11DeviceContext2)->Release()
#define My_ID3D11DeviceContext2_UpdateTileMappings(pID3D11DeviceContext2, pTiledResource, NumTiledResourceRegions, pTiledResourceRegionStartCoordinates, pTiledResourceRegionSizes, pTilePool, NumRanges, pRangeFlags, pTilePoolStartOffsets, pRangeTileCounts, Flags)\
    (pID3D11DeviceContext2)->UpdateTileMappings(pTiledResource, NumTiledResourceRegions, pTiledResourceRegionStartCoordinates, pTiledResourceRegionSizes, pTilePool, NumRanges, pRangeFlags, pTilePoolStartOffsets, pRangeTileCounts, Flags)
#define My_ID3D11DeviceContext2_CopyTileMappings(pID3D11DeviceContext2, pDestTiledResource, pDestRegionStartCoordinate, pSourceTiledResource, pSourceRegionStartCoordinate, pTileRegionSize, Flags)\
    (pID3D11DeviceContext2)->CopyTileMappings(pDestTiledResource, pDestRegionStartCoordinate, pSourceTiledResource, pSourceRegionStartCoordinate, pTileRegionSize, Flags)
#define My_ID3D11DeviceContext2_CopyTiles(pID3D11DeviceContext2, pTiledResource, pTileRegionStartCoordinate, pTileRegionSize, pBuffer, BufferStartOffsetInBytes, Flags)\
    (pID3D11DeviceContext2)->CopyTiles(pTiledResource, pTileRegionStartCoordinate, pTileRegionSize, pBuffer, BufferStartOffsetInBytes, Flags)
#define My_ID3D11DeviceContext2_UpdateTiles(pID3D11DeviceContext2, pDestTiledResource, pDestTileRegionStartCoordinate, pDestTileRegionSize, pSourceTileData, Flags)\
    (pID3D11DeviceContext2)->UpdateTiles(pDestTiledResource, pDestTileRegionStartCoordinate, pDestTileRegionSize, pSourceTileData, Flags)
#define My_ID3D11DeviceContext2_ResizeTilePool(pID3D11DeviceContext2, pTilePool, NewSizeInBytes)\
    (pID3D11DeviceContext2)->ResizeTilePool(pTilePool, NewSizeInBytes)
#define My_ID3D11DeviceContext2_TiledResourceBarrier(pID3D11DeviceContext2, pTiledResourceOrViewAccessBeforeBarrier, pTiledResourceOrViewAccessAfterBarrier)\
    (pID3D11DeviceContext2)->TiledResourceBarrier(pTiledResourceOrViewAccessBeforeBarrier, pTiledResourceOrViewAccessAfterBarrier)
#define My_ID3D11DeviceContext2_IsAnnotationEnabled(pID3D11DeviceContext2)\
    (pID3D11DeviceContext2)->IsAnnotationEnabled()
#define My_ID3D11DeviceContext2_SetMarkerInt(pID3D11DeviceContext2, pLabel, Data)\
    (pID3D11DeviceContext2)->SetMarkerInt(pLabel, Data)
#define My_ID3D11DeviceContext2_BeginEventInt(pID3D11DeviceContext2, pLabel, Data)\
    (pID3D11DeviceContext2)->BeginEventInt(pLabel, Data)
#define My_ID3D11DeviceContext2_EndEvent(pID3D11DeviceContext2)\
    (pID3D11DeviceContext2)->EndEvent()

#define My_ID3D11Device2_QueryInterface(pID3D11Device2, riid, ppvObj)\
    (pID3D11Device2)->QueryInterface(riid, ppvObj)
#define My_ID3D11Device2_AddRef(pID3D11Device2)\
    (pID3D11Device2)->AddRef()
#define My_ID3D11Device2_Release(pID3D11Device2)\
    (pID3D11Device2)->Release()
#define My_ID3D11Device2_GetImmediateContext2(pID3D11Device2, ppImmediateContext)\
    (pID3D11Device2)->GetImmediateContext2(ppImmediateContext)
#define My_ID3D11Device2_CreateDeferredContext2(pID3D11Device2, ContextFlags, ppDeferredContext)\
    (pID3D11Device2)->CreateDeferredContext2(ContextFlags, ppDeferredContext)
#define My_ID3D11Device2_GetResourceTiling(pID3D11Device2, pTiledResource, pNumTilesForEntireResource, pPackedMipDesc, pStandardTileShapeForNonPackedMips, pNumSubresourceTilings, FirstSubresourceTilingToGet, pSubresourceTilingsForNonPackedMips)\
    (pID3D11Device2)->GetResourceTiling(pTiledResource, pNumTilesForEntireResource, pPackedMipDesc, pStandardTileShapeForNonPackedMips, pNumSubresourceTilings, FirstSubresourceTilingToGet, pSubresourceTilingsForNonPackedMips)
#define My_ID3D11Device2_CheckMultisampleQualityLevels1(pID3D11Device2, Format, SampleCount, Flags, pNumQualityLevels)\
    (pID3D11Device2)->CheckMultisampleQualityLevels1(Format, SampleCount, Flags, pNumQualityLevels)

#define My_ID3D11Texture2D1_QueryInterface(pID3D11Texture2D1, riid, ppvObj)\
    (pID3D11Texture2D1)->QueryInterface(riid, ppvObj)
#define My_ID3D11Texture2D1_AddRef(pID3D11Texture2D1)\
    (pID3D11Texture2D1)->AddRef()
#define My_ID3D11Texture2D1_Release(pID3D11Texture2D1)\
    (pID3D11Texture2D1)->Release()
#define My_ID3D11Texture2D1_GetDesc1(pID3D11Texture2D1, pDesc)\
    (pID3D11Texture2D1)->GetDesc1(pDesc)

#define My_ID3D11Texture3D1_QueryInterface(pID3D11Texture3D1, riid, ppvObj)\
    (pID3D11Texture3D1)->QueryInterface(riid, ppvObj)
#define My_ID3D11Texture3D1_AddRef(pID3D11Texture3D1)\
    (pID3D11Texture3D1)->AddRef()
#define My_ID3D11Texture3D1_Release(pID3D11Texture3D1)\
    (pID3D11Texture3D1)->Release()
#define My_ID3D11Texture3D1_GetDesc1(pID3D11Texture3D1, pDesc)\
    (pID3D11Texture3D1)->GetDesc1(pDesc)

#define My_ID3D11RasterizerState2_QueryInterface(pID3D11RasterizerState2, riid, ppvObj)\
    (pID3D11RasterizerState2)->QueryInterface(riid, ppvObj)
#define My_ID3D11RasterizerState2_AddRef(pID3D11RasterizerState2)\
    (pID3D11RasterizerState2)->AddRef()
#define My_ID3D11RasterizerState2_Release(pID3D11RasterizerState2)\
    (pID3D11RasterizerState2)->Release()
#define My_ID3D11RasterizerState2_GetDesc2(pID3D11RasterizerState2, pDesc)\
    (pID3D11RasterizerState2)->GetDesc2(pDesc)

#define My_ID3D11ShaderResourceView1_QueryInterface(pID3D11ShaderResourceView1, riid, ppvObj)\
    (pID3D11ShaderResourceView1)->QueryInterface(riid, ppvObj)
#define My_ID3D11ShaderResourceView1_AddRef(pID3D11ShaderResourceView1)\
    (pID3D11ShaderResourceView1)->AddRef()
#define My_ID3D11ShaderResourceView1_Release(pID3D11ShaderResourceView1)\
    (pID3D11ShaderResourceView1)->Release()
#define My_ID3D11ShaderResourceView1_GetDesc1(pID3D11ShaderResourceView1, pDesc1)\
    (pID3D11ShaderResourceView1)->GetDesc1(pDesc1)

#define My_ID3D11RenderTargetView1_QueryInterface(pID3D11RenderTargetView1, riid, ppvObj)\
    (pID3D11RenderTargetView1)->QueryInterface(riid, ppvObj)
#define My_ID3D11RenderTargetView1_AddRef(pID3D11RenderTargetView1)\
    (pID3D11RenderTargetView1)->AddRef()
#define My_ID3D11RenderTargetView1_Release(pID3D11RenderTargetView1)\
    (pID3D11RenderTargetView1)->Release()
#define My_ID3D11RenderTargetView1_GetDesc1(pID3D11RenderTargetView1, pDesc1)\
    (pID3D11RenderTargetView1)->GetDesc1(pDesc1)

#define My_ID3D11UnorderedAccessView1_QueryInterface(pID3D11UnorderedAccessView1, riid, ppvObj)\
    (pID3D11UnorderedAccessView1)->QueryInterface(riid, ppvObj)
#define My_ID3D11UnorderedAccessView1_AddRef(pID3D11UnorderedAccessView1)\
    (pID3D11UnorderedAccessView1)->AddRef()
#define My_ID3D11UnorderedAccessView1_Release(pID3D11UnorderedAccessView1)\
    (pID3D11UnorderedAccessView1)->Release()
#define My_ID3D11UnorderedAccessView1_GetDesc1(pID3D11UnorderedAccessView1, pDesc1)\
    (pID3D11UnorderedAccessView1)->GetDesc1(pDesc1)

#define My_ID3D11Query1_QueryInterface(pID3D11Query1, riid, ppvObj)\
    (pID3D11Query1)->QueryInterface(riid, ppvObj)
#define My_ID3D11Query1_AddRef(pID3D11Query1)\
    (pID3D11Query1)->AddRef()
#define My_ID3D11Query1_Release(pID3D11Query1)\
    (pID3D11Query1)->Release()
#define My_ID3D11Query1_GetDesc1(pID3D11Query1, pDesc1)\
    (pID3D11Query1)->GetDesc1(pDesc1)

#define My_ID3D11DeviceContext3_QueryInterface(pID3D11DeviceContext3, riid, ppvObj)\
    (pID3D11DeviceContext3)->QueryInterface(riid, ppvObj)
#define My_ID3D11DeviceContext3_AddRef(pID3D11DeviceContext3)\
    (pID3D11DeviceContext3)->AddRef()
#define My_ID3D11DeviceContext3_Release(pID3D11DeviceContext3)\
    (pID3D11DeviceContext3)->Release()
#define My_ID3D11DeviceContext3_Flush1(pID3D11DeviceContext3, ContextType, hEvent)\
    (pID3D11DeviceContext3)->Flush1(ContextType, hEvent)
#define My_ID3D11DeviceContext3_SetHardwareProtectionState(pID3D11DeviceContext3, HwProtectionEnable)\
    (pID3D11DeviceContext3)->SetHardwareProtectionState(HwProtectionEnable)
#define My_ID3D11DeviceContext3_GetHardwareProtectionState(pID3D11DeviceContext3, pHwProtectionEnable)\
    (pID3D11DeviceContext3)->GetHardwareProtectionState(pHwProtectionEnable)

#define My_ID3D11Device3_QueryInterface(pID3D11Device3, riid, ppvObj)\
    (pID3D11Device3)->QueryInterface(riid, ppvObj)
#define My_ID3D11Device3_AddRef(pID3D11Device3)\
    (pID3D11Device3)->AddRef()
#define My_ID3D11Device3_Release(pID3D11Device3)\
    (pID3D11Device3)->Release()
#define My_ID3D11Device3_CreateTexture2D1(pID3D11Device3, pDesc1, pInitialData, ppTexture2D)\
    (pID3D11Device3)->CreateTexture2D1(pDesc1, pInitialData, ppTexture2D)
#define My_ID3D11Device3_CreateTexture3D1(pID3D11Device3, pDesc1, pInitialData, ppTexture3D)\
    (pID3D11Device3)->CreateTexture3D1(pDesc1, pInitialData, ppTexture3D)
#define My_ID3D11Device3_CreateRasterizerState2(pID3D11Device3, pRasterizerDesc, ppRasterizerState)\
    (pID3D11Device3)->CreateRasterizerState2(pRasterizerDesc, ppRasterizerState)
#define My_ID3D11Device3_CreateShaderResourceView1(pID3D11Device3, pResource, pDesc1, ppSRView1)\
    (pID3D11Device3)->CreateShaderResourceView1(pResource, pDesc1, ppSRView1)
#define My_ID3D11Device3_CreateUnorderedAccessView1(pID3D11Device3, pResource, pDesc1, ppUAView1)\
    (pID3D11Device3)->CreateUnorderedAccessView1(pResource, pDesc1, ppUAView1)
#define My_ID3D11Device3_CreateRenderTargetView1(pID3D11Device3, pResource, pDesc1, ppRTView1)\
    (pID3D11Device3)->CreateRenderTargetView1(pResource, pDesc1, ppRTView1)
#define My_ID3D11Device3_CreateQuery1(pID3D11Device3, pQueryDesc1, ppQuery1)\
    (pID3D11Device3)->CreateQuery1(pQueryDesc1, ppQuery1)
#define My_ID3D11Device3_GetImmediateContext3(pID3D11Device3, ppImmediateContext)\
    (pID3D11Device3)->GetImmediateContext3(ppImmediateContext)
#define My_ID3D11Device3_CreateDeferredContext3(pID3D11Device3, ContextFlags, ppDeferredContext)\
    (pID3D11Device3)->CreateDeferredContext3(ContextFlags, ppDeferredContext)
#define My_ID3D11Device3_WriteToSubresource(pID3D11Device3, pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch)\
    (pID3D11Device3)->WriteToSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch)
#define My_ID3D11Device3_ReadFromSubresource(pID3D11Device3, pDstData, DstRowPitch, DstDepthPitch, pSrcResource, SrcSubresource, pSrcBox)\
    (pID3D11Device3)->ReadFromSubresource(pDstData, DstRowPitch, DstDepthPitch, pSrcResource, SrcSubresource, pSrcBox)

#define My_ID3D11Fence_QueryInterface(pID3D11Fence, riid, ppvObj)\
    (pID3D11Fence)->QueryInterface(riid, ppvObj)
#define My_ID3D11Fence_AddRef(pID3D11Fence)\
    (pID3D11Fence)->AddRef()
#define My_ID3D11Fence_Release(pID3D11Fence)\
    (pID3D11Fence)->Release()
#define My_ID3D11Fence_CreateSharedHandle(pID3D11Fence, pAttributes, dwAccess, lpName, pHandle)\
    (pID3D11Fence)->CreateSharedHandle(pAttributes, dwAccess, lpName, pHandle)
#define My_ID3D11Fence_GetCompletedValue(pID3D11Fence)\
    (pID3D11Fence)->GetCompletedValue()
#define My_ID3D11Fence_SetEventOnCompletion(pID3D11Fence, Value, hEvent)\
    (pID3D11Fence)->SetEventOnCompletion(Value, hEvent)

#define My_ID3D11DeviceContext4_QueryInterface(pID3D11DeviceContext4, riid, ppvObj)\
    (pID3D11DeviceContext4)->QueryInterface(riid, ppvObj)
#define My_ID3D11DeviceContext4_AddRef(pID3D11DeviceContext4)\
    (pID3D11DeviceContext4)->AddRef()
#define My_ID3D11DeviceContext4_Release(pID3D11DeviceContext4)\
    (pID3D11DeviceContext4)->Release()
#define My_ID3D11DeviceContext4_Signal(pID3D11DeviceContext4, pFence, Value)\
    (pID3D11DeviceContext4)->Signal(pFence, Value)
#define My_ID3D11DeviceContext4_Wait(pID3D11DeviceContext4, pFence, Value)\
    (pID3D11DeviceContext4)->Wait(pFence, Value)

#define My_ID3D11Device4_QueryInterface(pID3D11Device4, riid, ppvObj)\
    (pID3D11Device4)->QueryInterface(riid, ppvObj)
#define My_ID3D11Device4_AddRef(pID3D11Device4)\
    (pID3D11Device4)->AddRef()
#define My_ID3D11Device4_Release(pID3D11Device4)\
    (pID3D11Device4)->Release()
#define My_ID3D11Device4_RegisterDeviceRemovedEvent(pID3D11Device4, hEvent, pdwCookie)\
    (pID3D11Device4)->RegisterDeviceRemovedEvent(hEvent, pdwCookie)
#define My_ID3D11Device4_UnregisterDeviceRemoved(pID3D11Device4, dwCookie)\
    (pID3D11Device4)->UnregisterDeviceRemoved(dwCookie)

#define My_ID3D11Multithread_QueryInterface(pID3D11Multithread, riid, ppvObj)\
    (pID3D11Multithread)->QueryInterface(riid, ppvObj)
#define My_ID3D11Multithread_AddRef(pID3D11Multithread)\
    (pID3D11Multithread)->AddRef()
#define My_ID3D11Multithread_Release(pID3D11Multithread)\
    (pID3D11Multithread)->Release()
#define My_ID3D11Multithread_Enter(pID3D11Multithread)\
    (pID3D11Multithread)->Enter()
#define My_ID3D11Multithread_Leave(pID3D11Multithread)\
    (pID3D11Multithread)->Leave()
#define My_ID3D11Multithread_SetMultithreadProtected(pID3D11Multithread, bMTProtect)\
    (pID3D11Multithread)->SetMultithreadProtected(bMTProtect)
#define My_ID3D11Multithread_GetMultithreadProtected(pID3D11Multithread)\
    (pID3D11Multithread)->GetMultithreadProtected()

#define My_ID3D11VideoContext2_QueryInterface(pID3D11VideoContext2, riid, ppvObj)\
    (pID3D11VideoContext2)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoContext2_AddRef(pID3D11VideoContext2)\
    (pID3D11VideoContext2)->AddRef()
#define My_ID3D11VideoContext2_Release(pID3D11VideoContext2)\
    (pID3D11VideoContext2)->Release()
#define My_ID3D11VideoContext2_VideoProcessorSetOutputHDRMetaData(pID3D11VideoContext2, pVideoProcessor, Type, Size, pHDRMetaData)\
    (pID3D11VideoContext2)->VideoProcessorSetOutputHDRMetaData(pVideoProcessor, Type, Size, pHDRMetaData)
#define My_ID3D11VideoContext2_VideoProcessorGetOutputHDRMetaData(pID3D11VideoContext2, pVideoProcessor, pType, Size, pMetaData)\
    (pID3D11VideoContext2)->VideoProcessorGetOutputHDRMetaData(pVideoProcessor, pType, Size, pMetaData)
#define My_ID3D11VideoContext2_VideoProcessorSetStreamHDRMetaData(pID3D11VideoContext2, pVideoProcessor, StreamIndex, Type, Size, pHDRMetaData)\
    (pID3D11VideoContext2)->VideoProcessorSetStreamHDRMetaData(pVideoProcessor, StreamIndex, Type, Size, pHDRMetaData)
#define My_ID3D11VideoContext2_VideoProcessorGetStreamHDRMetaData(pID3D11VideoContext2, pVideoProcessor, StreamIndex, pType, Size, pMetaData)\
    (pID3D11VideoContext2)->VideoProcessorGetStreamHDRMetaData(pVideoProcessor, StreamIndex, pType, Size, pMetaData)

#define My_ID3D11Device5_QueryInterface(pID3D11Device5, riid, ppvObj)\
    (pID3D11Device5)->QueryInterface(riid, ppvObj)
#define My_ID3D11Device5_AddRef(pID3D11Device5)\
    (pID3D11Device5)->AddRef()
#define My_ID3D11Device5_Release(pID3D11Device5)\
    (pID3D11Device5)->Release()
#define My_ID3D11Device5_OpenSharedFence(pID3D11Device5, hFence, ReturnedInterface, ppFence)\
    (pID3D11Device5)->OpenSharedFence(hFence, ReturnedInterface, ppFence)
#define My_ID3D11Device5_CreateFence(pID3D11Device5, InitialValue, Flags, ReturnedInterface, ppFence)\
    (pID3D11Device5)->CreateFence(InitialValue, Flags, ReturnedInterface, ppFence)

#define My_ID3D11VideoDevice2_QueryInterface(pID3D11VideoDevice2, riid, ppvObj)\
    (pID3D11VideoDevice2)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoDevice2_AddRef(pID3D11VideoDevice2)\
    (pID3D11VideoDevice2)->AddRef()
#define My_ID3D11VideoDevice2_Release(pID3D11VideoDevice2)\
    (pID3D11VideoDevice2)->Release()
#define My_ID3D11VideoDevice2_CheckFeatureSupport(pID3D11VideoDevice2, Feature, pFeatureSupportData, FeatureSupportDataSize)\
    (pID3D11VideoDevice2)->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize)
#define My_ID3D11VideoDevice2_NegotiateCryptoSessionKeyExchangeMT(pID3D11VideoDevice2, pCryptoSession, flags, DataSize, pData)\
    (pID3D11VideoDevice2)->NegotiateCryptoSessionKeyExchangeMT(pCryptoSession, flags, DataSize, pData)

#define My_ID3D11VideoContext3_QueryInterface(pID3D11VideoContext3, riid, ppvObj)\
    (pID3D11VideoContext3)->QueryInterface(riid, ppvObj)
#define My_ID3D11VideoContext3_AddRef(pID3D11VideoContext3)\
    (pID3D11VideoContext3)->AddRef()
#define My_ID3D11VideoContext3_Release(pID3D11VideoContext3)\
    (pID3D11VideoContext3)->Release()
#define My_ID3D11VideoContext3_DecoderBeginFrame1(pID3D11VideoContext3, pDecoder, pView, ContentKeySize, pContentKey, NumComponentHistograms, pHistogramOffsets, ppHistogramBuffers)\
    (pID3D11VideoContext3)->DecoderBeginFrame1(pDecoder, pView, ContentKeySize, pContentKey, NumComponentHistograms, pHistogramOffsets, ppHistogramBuffers)
#define My_ID3D11VideoContext3_SubmitDecoderBuffers2(pID3D11VideoContext3, pDecoder, NumBuffers, pBufferDesc)\
    (pID3D11VideoContext3)->SubmitDecoderBuffers2(pDecoder, NumBuffers, pBufferDesc)

#define My_D3D12SerializeRootSignature(pRootSignature, Version, ppBlob, ppErrorBlob)\
    D3D12SerializeRootSignature(pRootSignature, Version, ppBlob, ppErrorBlob)
#define My_D3D12CreateRootSignatureDeserializer(pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer)\
    D3D12CreateRootSignatureDeserializer(pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer)
#define My_D3D12CreateDevice(pAdapter, MinimumFeatureLevel, riid, ppDevice)\
    D3D12CreateDevice(pAdapter, MinimumFeatureLevel, riid, ppDevice)
#define My_D3D12GetDebugInterface(riid, ppvDebug)\
    D3D12GetDebugInterface(riid, ppvDebug)

#define My_ID3D12Object_QueryInterface(pID3D12Object, riid, ppvObj)\
    (pID3D12Object)->QueryInterface(riid, ppvObj)
#define My_ID3D12Object_AddRef(pID3D12Object)\
    (pID3D12Object)->AddRef()
#define My_ID3D12Object_Release(pID3D12Object)\
    (pID3D12Object)->Release()
#define My_ID3D12Object_GetPrivateData(pID3D12Object, guid, pDataSize, pData)\
    (pID3D12Object)->GetPrivateData(guid, pDataSize, pData)
#define My_ID3D12Object_SetPrivateData(pID3D12Object, guid, DataSize, pData)\
    (pID3D12Object)->SetPrivateData(guid, DataSize, pData)
#define My_ID3D12Object_SetPrivateDataInterface(pID3D12Object, guid, pData)\
    (pID3D12Object)->SetPrivateDataInterface(guid, pData)
#define My_ID3D12Object_SetName(pID3D12Object, Name)\
    (pID3D12Object)->SetName(Name)

#define My_ID3D12DeviceChild_QueryInterface(pID3D12DeviceChild, riid, ppvObj)\
    (pID3D12DeviceChild)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceChild_AddRef(pID3D12DeviceChild)\
    (pID3D12DeviceChild)->AddRef()
#define My_ID3D12DeviceChild_Release(pID3D12DeviceChild)\
    (pID3D12DeviceChild)->Release()
#define My_ID3D12DeviceChild_GetDevice(pID3D12DeviceChild, riid, ppvDevice)\
    (pID3D12DeviceChild)->GetDevice(riid, ppvDevice)

#define My_ID3D12RootSignature_QueryInterface(pID3D12RootSignature, riid, ppvObj)\
    (pID3D12RootSignature)->QueryInterface(riid, ppvObj)
#define My_ID3D12RootSignature_AddRef(pID3D12RootSignature)\
    (pID3D12RootSignature)->AddRef()
#define My_ID3D12RootSignature_Release(pID3D12RootSignature)\
    (pID3D12RootSignature)->Release()

#define My_ID3D12RootSignatureDeserializer_QueryInterface(pID3D12RootSignatureDeserializer, riid, ppvObj)\
    (pID3D12RootSignatureDeserializer)->QueryInterface(riid, ppvObj)
#define My_ID3D12RootSignatureDeserializer_AddRef(pID3D12RootSignatureDeserializer)\
    (pID3D12RootSignatureDeserializer)->AddRef()
#define My_ID3D12RootSignatureDeserializer_Release(pID3D12RootSignatureDeserializer)\
    (pID3D12RootSignatureDeserializer)->Release()
#define My_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(pID3D12RootSignatureDeserializer)\
    (pID3D12RootSignatureDeserializer)->GetRootSignatureDesc()

#define My_ID3D12Pageable_QueryInterface(pID3D12Pageable, riid, ppvObj)\
    (pID3D12Pageable)->QueryInterface(riid, ppvObj)
#define My_ID3D12Pageable_AddRef(pID3D12Pageable)\
    (pID3D12Pageable)->AddRef()
#define My_ID3D12Pageable_Release(pID3D12Pageable)\
    (pID3D12Pageable)->Release()

#define My_ID3D12Heap_QueryInterface(pID3D12Heap, riid, ppvObj)\
    (pID3D12Heap)->QueryInterface(riid, ppvObj)
#define My_ID3D12Heap_AddRef(pID3D12Heap)\
    (pID3D12Heap)->AddRef()
#define My_ID3D12Heap_Release(pID3D12Heap)\
    (pID3D12Heap)->Release()
#define My_ID3D12Heap_GetDesc(pID3D12Heap)\
    (pID3D12Heap)->GetDesc()

#define My_ID3D12Resource_QueryInterface(pID3D12Resource, riid, ppvObj)\
    (pID3D12Resource)->QueryInterface(riid, ppvObj)
#define My_ID3D12Resource_AddRef(pID3D12Resource)\
    (pID3D12Resource)->AddRef()
#define My_ID3D12Resource_Release(pID3D12Resource)\
    (pID3D12Resource)->Release()
#define My_ID3D12Resource_Map(pID3D12Resource, Subresource, pReadRange, ppData)\
    (pID3D12Resource)->Map(Subresource, pReadRange, ppData)
#define My_ID3D12Resource_Unmap(pID3D12Resource, Subresource, pWrittenRange)\
    (pID3D12Resource)->Unmap(Subresource, pWrittenRange)
#define My_ID3D12Resource_GetDesc(pID3D12Resource)\
    (pID3D12Resource)->GetDesc()
#define My_ID3D12Resource_GetGPUVirtualAddress(pID3D12Resource)\
    (pID3D12Resource)->GetGPUVirtualAddress()
#define My_ID3D12Resource_WriteToSubresource(pID3D12Resource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch)\
    (pID3D12Resource)->WriteToSubresource(DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch)
#define My_ID3D12Resource_ReadFromSubresource(pID3D12Resource, pDstData, DstRowPitch, DstDepthPitch, SrcSubresource, pSrcBox)\
    (pID3D12Resource)->ReadFromSubresource(pDstData, DstRowPitch, DstDepthPitch, SrcSubresource, pSrcBox)
#define My_ID3D12Resource_GetHeapProperties(pID3D12Resource, pHeapProperties, pHeapFlags)\
    (pID3D12Resource)->GetHeapProperties(pHeapProperties, pHeapFlags)

#define My_ID3D12CommandAllocator_QueryInterface(pID3D12CommandAllocator, riid, ppvObj)\
    (pID3D12CommandAllocator)->QueryInterface(riid, ppvObj)
#define My_ID3D12CommandAllocator_AddRef(pID3D12CommandAllocator)\
    (pID3D12CommandAllocator)->AddRef()
#define My_ID3D12CommandAllocator_Release(pID3D12CommandAllocator)\
    (pID3D12CommandAllocator)->Release()
#define My_ID3D12CommandAllocator_Reset(pID3D12CommandAllocator)\
    (pID3D12CommandAllocator)->Reset()

#define My_ID3D12Fence_QueryInterface(pID3D12Fence, riid, ppvObj)\
    (pID3D12Fence)->QueryInterface(riid, ppvObj)
#define My_ID3D12Fence_AddRef(pID3D12Fence)\
    (pID3D12Fence)->AddRef()
#define My_ID3D12Fence_Release(pID3D12Fence)\
    (pID3D12Fence)->Release()
#define My_ID3D12Fence_GetCompletedValue(pID3D12Fence)\
    (pID3D12Fence)->GetCompletedValue()
#define My_ID3D12Fence_SetEventOnCompletion(pID3D12Fence, Value, hEvent)\
    (pID3D12Fence)->SetEventOnCompletion(Value, hEvent)
#define My_ID3D12Fence_Signal(pID3D12Fence, Value)\
    (pID3D12Fence)->Signal(Value)

#define My_ID3D12PipelineState_QueryInterface(pID3D12PipelineState, riid, ppvObj)\
    (pID3D12PipelineState)->QueryInterface(riid, ppvObj)
#define My_ID3D12PipelineState_AddRef(pID3D12PipelineState)\
    (pID3D12PipelineState)->AddRef()
#define My_ID3D12PipelineState_Release(pID3D12PipelineState)\
    (pID3D12PipelineState)->Release()
#define My_ID3D12PipelineState_GetCachedBlob(pID3D12PipelineState, ppBlob)\
    (pID3D12PipelineState)->GetCachedBlob(ppBlob)

#define My_ID3D12DescriptorHeap_QueryInterface(pID3D12DescriptorHeap, riid, ppvObj)\
    (pID3D12DescriptorHeap)->QueryInterface(riid, ppvObj)
#define My_ID3D12DescriptorHeap_AddRef(pID3D12DescriptorHeap)\
    (pID3D12DescriptorHeap)->AddRef()
#define My_ID3D12DescriptorHeap_Release(pID3D12DescriptorHeap)\
    (pID3D12DescriptorHeap)->Release()
#define My_ID3D12DescriptorHeap_GetDesc(pID3D12DescriptorHeap)\
    (pID3D12DescriptorHeap)->GetDesc()
#define My_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(pID3D12DescriptorHeap)\
    (pID3D12DescriptorHeap)->GetCPUDescriptorHandleForHeapStart()
#define My_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(pID3D12DescriptorHeap)\
    (pID3D12DescriptorHeap)->GetGPUDescriptorHandleForHeapStart()

#define My_ID3D12QueryHeap_QueryInterface(pID3D12QueryHeap, riid, ppvObj)\
    (pID3D12QueryHeap)->QueryInterface(riid, ppvObj)
#define My_ID3D12QueryHeap_AddRef(pID3D12QueryHeap)\
    (pID3D12QueryHeap)->AddRef()
#define My_ID3D12QueryHeap_Release(pID3D12QueryHeap)\
    (pID3D12QueryHeap)->Release()

#define My_ID3D12CommandSignature_QueryInterface(pID3D12CommandSignature, riid, ppvObj)\
    (pID3D12CommandSignature)->QueryInterface(riid, ppvObj)
#define My_ID3D12CommandSignature_AddRef(pID3D12CommandSignature)\
    (pID3D12CommandSignature)->AddRef()
#define My_ID3D12CommandSignature_Release(pID3D12CommandSignature)\
    (pID3D12CommandSignature)->Release()

#define My_ID3D12CommandList_QueryInterface(pID3D12CommandList, riid, ppvObj)\
    (pID3D12CommandList)->QueryInterface(riid, ppvObj)
#define My_ID3D12CommandList_AddRef(pID3D12CommandList)\
    (pID3D12CommandList)->AddRef()
#define My_ID3D12CommandList_Release(pID3D12CommandList)\
    (pID3D12CommandList)->Release()
#define My_ID3D12CommandList_GetType(pID3D12CommandList)\
    (pID3D12CommandList)->GetType()

#define My_ID3D12GraphicsCommandList_QueryInterface(pID3D12GraphicsCommandList, riid, ppvObj)\
    (pID3D12GraphicsCommandList)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList_AddRef(pID3D12GraphicsCommandList)\
    (pID3D12GraphicsCommandList)->AddRef()
#define My_ID3D12GraphicsCommandList_Release(pID3D12GraphicsCommandList)\
    (pID3D12GraphicsCommandList)->Release()
#define My_ID3D12GraphicsCommandList_Close(pID3D12GraphicsCommandList)\
    (pID3D12GraphicsCommandList)->Close()
#define My_ID3D12GraphicsCommandList_Reset(pID3D12GraphicsCommandList, pAllocator, pInitialState)\
    (pID3D12GraphicsCommandList)->Reset(pAllocator, pInitialState)
#define My_ID3D12GraphicsCommandList_ClearState(pID3D12GraphicsCommandList, pPipelineState)\
    (pID3D12GraphicsCommandList)->ClearState(pPipelineState)
#define My_ID3D12GraphicsCommandList_DrawInstanced(pID3D12GraphicsCommandList, VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation)\
    (pID3D12GraphicsCommandList)->DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation)
#define My_ID3D12GraphicsCommandList_DrawIndexedInstanced(pID3D12GraphicsCommandList, IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation)\
    (pID3D12GraphicsCommandList)->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation)
#define My_ID3D12GraphicsCommandList_Dispatch(pID3D12GraphicsCommandList, ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ)\
    (pID3D12GraphicsCommandList)->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ)
#define My_ID3D12GraphicsCommandList_CopyBufferRegion(pID3D12GraphicsCommandList, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, NumBytes)\
    (pID3D12GraphicsCommandList)->CopyBufferRegion(pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, NumBytes)
#define My_ID3D12GraphicsCommandList_CopyTextureRegion(pID3D12GraphicsCommandList, pDst, DstX, DstY, DstZ, pSrc, pSrcBox)\
    (pID3D12GraphicsCommandList)->CopyTextureRegion(pDst, DstX, DstY, DstZ, pSrc, pSrcBox)
#define My_ID3D12GraphicsCommandList_CopyResource(pID3D12GraphicsCommandList, pDstResource, pSrcResource)\
    (pID3D12GraphicsCommandList)->CopyResource(pDstResource, pSrcResource)
#define My_ID3D12GraphicsCommandList_CopyTiles(pID3D12GraphicsCommandList, pTiledResource, pTileRegionStartCoordinate, pTileRegionSize, pBuffer, BufferStartOffsetInBytes, Flags)\
    (pID3D12GraphicsCommandList)->CopyTiles(pTiledResource, pTileRegionStartCoordinate, pTileRegionSize, pBuffer, BufferStartOffsetInBytes, Flags)
#define My_ID3D12GraphicsCommandList_ResolveSubresource(pID3D12GraphicsCommandList, pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format)\
    (pID3D12GraphicsCommandList)->ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format)
#define My_ID3D12GraphicsCommandList_IASetPrimitiveTopology(pID3D12GraphicsCommandList, PrimitiveTopology)\
    (pID3D12GraphicsCommandList)->IASetPrimitiveTopology(PrimitiveTopology)
#define My_ID3D12GraphicsCommandList_RSSetViewports(pID3D12GraphicsCommandList, NumViewports, pViewports)\
    (pID3D12GraphicsCommandList)->RSSetViewports(NumViewports, pViewports)
#define My_ID3D12GraphicsCommandList_RSSetScissorRects(pID3D12GraphicsCommandList, NumRects, pRects)\
    (pID3D12GraphicsCommandList)->RSSetScissorRects(NumRects, pRects)
#define My_ID3D12GraphicsCommandList_OMSetBlendFactor(pID3D12GraphicsCommandList, BlendFactor)\
    (pID3D12GraphicsCommandList)->OMSetBlendFactor(BlendFactor)
#define My_ID3D12GraphicsCommandList_OMSetStencilRef(pID3D12GraphicsCommandList, StencilRef)\
    (pID3D12GraphicsCommandList)->OMSetStencilRef(StencilRef)
#define My_ID3D12GraphicsCommandList_SetPipelineState(pID3D12GraphicsCommandList, pPipelineState)\
    (pID3D12GraphicsCommandList)->SetPipelineState(pPipelineState)
#define My_ID3D12GraphicsCommandList_ResourceBarrier(pID3D12GraphicsCommandList, NumBarriers, pBarriers)\
    (pID3D12GraphicsCommandList)->ResourceBarrier(NumBarriers, pBarriers)
#define My_ID3D12GraphicsCommandList_ExecuteBundle(pID3D12GraphicsCommandList, pCommandList)\
    (pID3D12GraphicsCommandList)->ExecuteBundle(pCommandList)
#define My_ID3D12GraphicsCommandList_SetDescriptorHeaps(pID3D12GraphicsCommandList, NumDescriptorHeaps, ppDescriptorHeaps)\
    (pID3D12GraphicsCommandList)->SetDescriptorHeaps(NumDescriptorHeaps, ppDescriptorHeaps)
#define My_ID3D12GraphicsCommandList_SetComputeRootSignature(pID3D12GraphicsCommandList, pRootSignature)\
    (pID3D12GraphicsCommandList)->SetComputeRootSignature(pRootSignature)
#define My_ID3D12GraphicsCommandList_SetGraphicsRootSignature(pID3D12GraphicsCommandList, pRootSignature)\
    (pID3D12GraphicsCommandList)->SetGraphicsRootSignature(pRootSignature)
#define My_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(pID3D12GraphicsCommandList, RootParameterIndex, BaseDescriptor)\
    (pID3D12GraphicsCommandList)->SetComputeRootDescriptorTable(RootParameterIndex, BaseDescriptor)
#define My_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(pID3D12GraphicsCommandList, RootParameterIndex, BaseDescriptor)\
    (pID3D12GraphicsCommandList)->SetGraphicsRootDescriptorTable(RootParameterIndex, BaseDescriptor)
#define My_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(pID3D12GraphicsCommandList, RootParameterIndex, SrcData, DestOffsetIn32BitValues)\
    (pID3D12GraphicsCommandList)->SetComputeRoot32BitConstant(RootParameterIndex, SrcData, DestOffsetIn32BitValues)
#define My_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(pID3D12GraphicsCommandList, RootParameterIndex, SrcData, DestOffsetIn32BitValues)\
    (pID3D12GraphicsCommandList)->SetGraphicsRoot32BitConstant(RootParameterIndex, SrcData, DestOffsetIn32BitValues)
#define My_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(pID3D12GraphicsCommandList, RootParameterIndex, Num32BitValuesToSet, pSrcData, DestOffsetIn32BitValues)\
    (pID3D12GraphicsCommandList)->SetComputeRoot32BitConstants(RootParameterIndex, Num32BitValuesToSet, pSrcData, DestOffsetIn32BitValues)
#define My_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(pID3D12GraphicsCommandList, RootParameterIndex, Num32BitValuesToSet, pSrcData, DestOffsetIn32BitValues)\
    (pID3D12GraphicsCommandList)->SetGraphicsRoot32BitConstants(RootParameterIndex, Num32BitValuesToSet, pSrcData, DestOffsetIn32BitValues)
#define My_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(pID3D12GraphicsCommandList, RootParameterIndex, BufferLocation)\
    (pID3D12GraphicsCommandList)->SetComputeRootConstantBufferView(RootParameterIndex, BufferLocation)
#define My_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(pID3D12GraphicsCommandList, RootParameterIndex, BufferLocation)\
    (pID3D12GraphicsCommandList)->SetGraphicsRootConstantBufferView(RootParameterIndex, BufferLocation)
#define My_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(pID3D12GraphicsCommandList, RootParameterIndex, BufferLocation)\
    (pID3D12GraphicsCommandList)->SetComputeRootShaderResourceView(RootParameterIndex, BufferLocation)
#define My_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(pID3D12GraphicsCommandList, RootParameterIndex, BufferLocation)\
    (pID3D12GraphicsCommandList)->SetGraphicsRootShaderResourceView(RootParameterIndex, BufferLocation)
#define My_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(pID3D12GraphicsCommandList, RootParameterIndex, BufferLocation)\
    (pID3D12GraphicsCommandList)->SetComputeRootUnorderedAccessView(RootParameterIndex, BufferLocation)
#define My_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(pID3D12GraphicsCommandList, RootParameterIndex, BufferLocation)\
    (pID3D12GraphicsCommandList)->SetGraphicsRootUnorderedAccessView(RootParameterIndex, BufferLocation)
#define My_ID3D12GraphicsCommandList_IASetIndexBuffer(pID3D12GraphicsCommandList, pView)\
    (pID3D12GraphicsCommandList)->IASetIndexBuffer(pView)
#define My_ID3D12GraphicsCommandList_IASetVertexBuffers(pID3D12GraphicsCommandList, StartSlot, NumViews, pViews)\
    (pID3D12GraphicsCommandList)->IASetVertexBuffers(StartSlot, NumViews, pViews)
#define My_ID3D12GraphicsCommandList_SOSetTargets(pID3D12GraphicsCommandList, StartSlot, NumViews, pViews)\
    (pID3D12GraphicsCommandList)->SOSetTargets(StartSlot, NumViews, pViews)
#define My_ID3D12GraphicsCommandList_OMSetRenderTargets(pID3D12GraphicsCommandList, NumRenderTargetDescriptors, pRenderTargetDescriptors, RTsSingleHandleToDescriptorRange, pDepthStencilDescriptor)\
    (pID3D12GraphicsCommandList)->OMSetRenderTargets(NumRenderTargetDescriptors, pRenderTargetDescriptors, RTsSingleHandleToDescriptorRange, pDepthStencilDescriptor)
#define My_ID3D12GraphicsCommandList_ClearDepthStencilView(pID3D12GraphicsCommandList, DepthStencilView, ClearFlags, Depth, Stencil, NumRects, pRects)\
    (pID3D12GraphicsCommandList)->ClearDepthStencilView(DepthStencilView, ClearFlags, Depth, Stencil, NumRects, pRects)
#define My_ID3D12GraphicsCommandList_ClearRenderTargetView(pID3D12GraphicsCommandList, RenderTargetView, ColorRGBA, NumRects, pRects)\
    (pID3D12GraphicsCommandList)->ClearRenderTargetView(RenderTargetView, ColorRGBA, NumRects, pRects)
#define My_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(pID3D12GraphicsCommandList, ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects)\
    (pID3D12GraphicsCommandList)->ClearUnorderedAccessViewUint(ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects)
#define My_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(pID3D12GraphicsCommandList, ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects)\
    (pID3D12GraphicsCommandList)->ClearUnorderedAccessViewFloat(ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects)
#define My_ID3D12GraphicsCommandList_DiscardResource(pID3D12GraphicsCommandList, pResource, pRegion)\
    (pID3D12GraphicsCommandList)->DiscardResource(pResource, pRegion)
#define My_ID3D12GraphicsCommandList_BeginQuery(pID3D12GraphicsCommandList, pQueryHeap, Type, Index)\
    (pID3D12GraphicsCommandList)->BeginQuery(pQueryHeap, Type, Index)
#define My_ID3D12GraphicsCommandList_EndQuery(pID3D12GraphicsCommandList, pQueryHeap, Type, Index)\
    (pID3D12GraphicsCommandList)->EndQuery(pQueryHeap, Type, Index)
#define My_ID3D12GraphicsCommandList_ResolveQueryData(pID3D12GraphicsCommandList, pQueryHeap, Type, StartIndex, NumQueries, pDestinationBuffer, AlignedDestinationBufferOffset)\
    (pID3D12GraphicsCommandList)->ResolveQueryData(pQueryHeap, Type, StartIndex, NumQueries, pDestinationBuffer, AlignedDestinationBufferOffset)
#define My_ID3D12GraphicsCommandList_SetPredication(pID3D12GraphicsCommandList, pBuffer, AlignedBufferOffset, Operation)\
    (pID3D12GraphicsCommandList)->SetPredication(pBuffer, AlignedBufferOffset, Operation)
#define My_ID3D12GraphicsCommandList_SetMarker(pID3D12GraphicsCommandList, Metadata, pData, Size)\
    (pID3D12GraphicsCommandList)->SetMarker(Metadata, pData, Size)
#define My_ID3D12GraphicsCommandList_BeginEvent(pID3D12GraphicsCommandList, Metadata, pData, Size)\
    (pID3D12GraphicsCommandList)->BeginEvent(Metadata, pData, Size)
#define My_ID3D12GraphicsCommandList_EndEvent(pID3D12GraphicsCommandList)\
    (pID3D12GraphicsCommandList)->EndEvent()
#define My_ID3D12GraphicsCommandList_ExecuteIndirect(pID3D12GraphicsCommandList, pCommandSignature, MaxCommandCount, pArgumentBuffer, ArgumentBufferOffset, pCountBuffer, CountBufferOffset)\
    (pID3D12GraphicsCommandList)->ExecuteIndirect(pCommandSignature, MaxCommandCount, pArgumentBuffer, ArgumentBufferOffset, pCountBuffer, CountBufferOffset)

#define My_ID3D12CommandQueue_QueryInterface(pID3D12CommandQueue, riid, ppvObj)\
    (pID3D12CommandQueue)->QueryInterface(riid, ppvObj)
#define My_ID3D12CommandQueue_AddRef(pID3D12CommandQueue)\
    (pID3D12CommandQueue)->AddRef()
#define My_ID3D12CommandQueue_Release(pID3D12CommandQueue)\
    (pID3D12CommandQueue)->Release()
#define My_ID3D12CommandQueue_UpdateTileMappings(pID3D12CommandQueue, pResource, NumResourceRegions, pResourceRegionStartCoordinates, pResourceRegionSizes, pHeap, NumRanges, pRangeFlags, pHeapRangeStartOffsets, pRangeTileCounts, Flags)\
    (pID3D12CommandQueue)->UpdateTileMappings(pResource, NumResourceRegions, pResourceRegionStartCoordinates, pResourceRegionSizes, pHeap, NumRanges, pRangeFlags, pHeapRangeStartOffsets, pRangeTileCounts, Flags)
#define My_ID3D12CommandQueue_CopyTileMappings(pID3D12CommandQueue, pDstResource, pDstRegionStartCoordinate, pSrcResource, pSrcRegionStartCoordinate, pRegionSize, Flags)\
    (pID3D12CommandQueue)->CopyTileMappings(pDstResource, pDstRegionStartCoordinate, pSrcResource, pSrcRegionStartCoordinate, pRegionSize, Flags)
#define My_ID3D12CommandQueue_ExecuteCommandLists(pID3D12CommandQueue, NumCommandLists, ppCommandLists)\
    (pID3D12CommandQueue)->ExecuteCommandLists(NumCommandLists, ppCommandLists)
#define My_ID3D12CommandQueue_SetMarker(pID3D12CommandQueue, Metadata, pData, Size)\
    (pID3D12CommandQueue)->SetMarker(Metadata, pData, Size)
#define My_ID3D12CommandQueue_BeginEvent(pID3D12CommandQueue, Metadata, pData, Size)\
    (pID3D12CommandQueue)->BeginEvent(Metadata, pData, Size)
#define My_ID3D12CommandQueue_EndEvent(pID3D12CommandQueue)\
    (pID3D12CommandQueue)->EndEvent()
#define My_ID3D12CommandQueue_Signal(pID3D12CommandQueue, pFence, Value)\
    (pID3D12CommandQueue)->Signal(pFence, Value)
#define My_ID3D12CommandQueue_Wait(pID3D12CommandQueue, pFence, Value)\
    (pID3D12CommandQueue)->Wait(pFence, Value)
#define My_ID3D12CommandQueue_GetTimestampFrequency(pID3D12CommandQueue, pFrequency)\
    (pID3D12CommandQueue)->GetTimestampFrequency(pFrequency)
#define My_ID3D12CommandQueue_GetClockCalibration(pID3D12CommandQueue, pGpuTimestamp, pCpuTimestamp)\
    (pID3D12CommandQueue)->GetClockCalibration(pGpuTimestamp, pCpuTimestamp)
#define My_ID3D12CommandQueue_GetDesc(pID3D12CommandQueue)\
    (pID3D12CommandQueue)->GetDesc()

#define My_ID3D12Device_QueryInterface(pID3D12Device, riid, ppvObj)\
    (pID3D12Device)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device_AddRef(pID3D12Device)\
    (pID3D12Device)->AddRef()
#define My_ID3D12Device_Release(pID3D12Device)\
    (pID3D12Device)->Release()
#define My_ID3D12Device_GetNodeCount(pID3D12Device)\
    (pID3D12Device)->GetNodeCount()
#define My_ID3D12Device_CreateCommandQueue(pID3D12Device, pDesc, riid, ppCommandQueue)\
    (pID3D12Device)->CreateCommandQueue(pDesc, riid, ppCommandQueue)
#define My_ID3D12Device_CreateCommandAllocator(pID3D12Device, type, riid, ppCommandAllocator)\
    (pID3D12Device)->CreateCommandAllocator(type, riid, ppCommandAllocator)
#define My_ID3D12Device_CreateGraphicsPipelineState(pID3D12Device, pDesc, riid, ppPipelineState)\
    (pID3D12Device)->CreateGraphicsPipelineState(pDesc, riid, ppPipelineState)
#define My_ID3D12Device_CreateComputePipelineState(pID3D12Device, pDesc, riid, ppPipelineState)\
    (pID3D12Device)->CreateComputePipelineState(pDesc, riid, ppPipelineState)
#define My_ID3D12Device_CreateCommandList(pID3D12Device, nodeMask, type, pCommandAllocator, pInitialState, riid, ppCommandList)\
    (pID3D12Device)->CreateCommandList(nodeMask, type, pCommandAllocator, pInitialState, riid, ppCommandList)
#define My_ID3D12Device_CheckFeatureSupport(pID3D12Device, Feature, pFeatureSupportData, FeatureSupportDataSize)\
    (pID3D12Device)->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize)
#define My_ID3D12Device_CreateDescriptorHeap(pID3D12Device, pDescriptorHeapDesc, riid, ppvHeap)\
    (pID3D12Device)->CreateDescriptorHeap(pDescriptorHeapDesc, riid, ppvHeap)
#define My_ID3D12Device_GetDescriptorHandleIncrementSize(pID3D12Device, DescriptorHeapType)\
    (pID3D12Device)->GetDescriptorHandleIncrementSize(DescriptorHeapType)
#define My_ID3D12Device_CreateRootSignature(pID3D12Device, nodeMask, pBlobWithRootSignature, blobLengthInBytes, riid, ppvRootSignature)\
    (pID3D12Device)->CreateRootSignature(nodeMask, pBlobWithRootSignature, blobLengthInBytes, riid, ppvRootSignature)
#define My_ID3D12Device_CreateConstantBufferView(pID3D12Device, pDesc, DestDescriptor)\
    (pID3D12Device)->CreateConstantBufferView(pDesc, DestDescriptor)
#define My_ID3D12Device_CreateShaderResourceView(pID3D12Device, pResource, pDesc, DestDescriptor)\
    (pID3D12Device)->CreateShaderResourceView(pResource, pDesc, DestDescriptor)
#define My_ID3D12Device_CreateUnorderedAccessView(pID3D12Device, pResource, pCounterResource, pDesc, DestDescriptor)\
    (pID3D12Device)->CreateUnorderedAccessView(pResource, pCounterResource, pDesc, DestDescriptor)
#define My_ID3D12Device_CreateRenderTargetView(pID3D12Device, pResource, pDesc, DestDescriptor)\
    (pID3D12Device)->CreateRenderTargetView(pResource, pDesc, DestDescriptor)
#define My_ID3D12Device_CreateDepthStencilView(pID3D12Device, pResource, pDesc, DestDescriptor)\
    (pID3D12Device)->CreateDepthStencilView(pResource, pDesc, DestDescriptor)
#define My_ID3D12Device_CreateSampler(pID3D12Device, pDesc, DestDescriptor)\
    (pID3D12Device)->CreateSampler(pDesc, DestDescriptor)
#define My_ID3D12Device_CopyDescriptors(pID3D12Device, NumDestDescriptorRanges, pDestDescriptorRangeStarts, pDestDescriptorRangeSizes, NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, pSrcDescriptorRangeSizes, DescriptorHeapsType)\
    (pID3D12Device)->CopyDescriptors(NumDestDescriptorRanges, pDestDescriptorRangeStarts, pDestDescriptorRangeSizes, NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, pSrcDescriptorRangeSizes, DescriptorHeapsType)
#define My_ID3D12Device_CopyDescriptorsSimple(pID3D12Device, NumDescriptors, DestDescriptorRangeStart, SrcDescriptorRangeStart, DescriptorHeapsType)\
    (pID3D12Device)->CopyDescriptorsSimple(NumDescriptors, DestDescriptorRangeStart, SrcDescriptorRangeStart, DescriptorHeapsType)
#define My_ID3D12Device_GetResourceAllocationInfo(pID3D12Device, visibleMask, numResourceDescs, pResourceDescs)\
    (pID3D12Device)->GetResourceAllocationInfo(visibleMask, numResourceDescs, pResourceDescs)
#define My_ID3D12Device_GetCustomHeapProperties(pID3D12Device, nodeMask, heapType)\
    (pID3D12Device)->GetCustomHeapProperties(nodeMask, heapType)
#define My_ID3D12Device_CreateCommittedResource(pID3D12Device, pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, riidResource, ppvResource)\
    (pID3D12Device)->CreateCommittedResource(pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, riidResource, ppvResource)
#define My_ID3D12Device_CreateHeap(pID3D12Device, pDesc, riid, ppvHeap)\
    (pID3D12Device)->CreateHeap(pDesc, riid, ppvHeap)
#define My_ID3D12Device_CreatePlacedResource(pID3D12Device, pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource)\
    (pID3D12Device)->CreatePlacedResource(pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource)
#define My_ID3D12Device_CreateReservedResource(pID3D12Device, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource)\
    (pID3D12Device)->CreateReservedResource(pDesc, InitialState, pOptimizedClearValue, riid, ppvResource)
#define My_ID3D12Device_CreateSharedHandle(pID3D12Device, pObject, pAttributes, Access, Name, pHandle)\
    (pID3D12Device)->CreateSharedHandle(pObject, pAttributes, Access, Name, pHandle)
#define My_ID3D12Device_OpenSharedHandle(pID3D12Device, NTHandle, riid, ppvObj)\
    (pID3D12Device)->OpenSharedHandle(NTHandle, riid, ppvObj)
#define My_ID3D12Device_OpenSharedHandleByName(pID3D12Device, Name, Access, pNTHandle)\
    (pID3D12Device)->OpenSharedHandleByName(Name, Access, pNTHandle)
#define My_ID3D12Device_MakeResident(pID3D12Device, NumObjects, ppObjects)\
    (pID3D12Device)->MakeResident(NumObjects, ppObjects)
#define My_ID3D12Device_Evict(pID3D12Device, NumObjects, ppObjects)\
    (pID3D12Device)->Evict(NumObjects, ppObjects)
#define My_ID3D12Device_CreateFence(pID3D12Device, InitialValue, Flags, riid, ppFence)\
    (pID3D12Device)->CreateFence(InitialValue, Flags, riid, ppFence)
#define My_ID3D12Device_GetDeviceRemovedReason(pID3D12Device)\
    (pID3D12Device)->GetDeviceRemovedReason()
#define My_ID3D12Device_GetCopyableFootprints(pID3D12Device, pResourceDesc, FirstSubresource, NumSubresources, BaseOffset, pLayouts, pNumRows, pRowSizeInBytes, pTotalBytes)\
    (pID3D12Device)->GetCopyableFootprints(pResourceDesc, FirstSubresource, NumSubresources, BaseOffset, pLayouts, pNumRows, pRowSizeInBytes, pTotalBytes)
#define My_ID3D12Device_CreateQueryHeap(pID3D12Device, pDesc, riid, ppvHeap)\
    (pID3D12Device)->CreateQueryHeap(pDesc, riid, ppvHeap)
#define My_ID3D12Device_SetStablePowerState(pID3D12Device, Enable)\
    (pID3D12Device)->SetStablePowerState(Enable)
#define My_ID3D12Device_CreateCommandSignature(pID3D12Device, pDesc, pRootSignature, riid, ppvCommandSignature)\
    (pID3D12Device)->CreateCommandSignature(pDesc, pRootSignature, riid, ppvCommandSignature)
#define My_ID3D12Device_GetResourceTiling(pID3D12Device, pTiledResource, pNumTilesForEntireResource, pPackedMipDesc, pStandardTileShapeForNonPackedMips, pNumSubresourceTilings, FirstSubresourceTilingToGet, pSubresourceTilingsForNonPackedMips)\
    (pID3D12Device)->GetResourceTiling(pTiledResource, pNumTilesForEntireResource, pPackedMipDesc, pStandardTileShapeForNonPackedMips, pNumSubresourceTilings, FirstSubresourceTilingToGet, pSubresourceTilingsForNonPackedMips)
#define My_ID3D12Device_GetAdapterLuid(pID3D12Device)\
    (pID3D12Device)->GetAdapterLuid()

#define My_D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob)\
    D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob)
#define My_D3D12CreateVersionedRootSignatureDeserializer(pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer)\
    D3D12CreateVersionedRootSignatureDeserializer(pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer)

#define My_ID3D12VersionedRootSignatureDeserializer_QueryInterface(pID3D12VersionedRootSignatureDeserializer, riid, ppvObj)\
    (pID3D12VersionedRootSignatureDeserializer)->QueryInterface(riid, ppvObj)
#define My_ID3D12VersionedRootSignatureDeserializer_AddRef(pID3D12VersionedRootSignatureDeserializer)\
    (pID3D12VersionedRootSignatureDeserializer)->AddRef()
#define My_ID3D12VersionedRootSignatureDeserializer_Release(pID3D12VersionedRootSignatureDeserializer)\
    (pID3D12VersionedRootSignatureDeserializer)->Release()
#define My_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(pID3D12VersionedRootSignatureDeserializer, convertToVersion, ppDesc)\
    (pID3D12VersionedRootSignatureDeserializer)->GetRootSignatureDescAtVersion(convertToVersion, ppDesc)
#define My_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(pID3D12VersionedRootSignatureDeserializer)\
    (pID3D12VersionedRootSignatureDeserializer)->GetUnconvertedRootSignatureDesc()

#define My_ID3D12PipelineLibrary_QueryInterface(pID3D12PipelineLibrary, riid, ppvObj)\
    (pID3D12PipelineLibrary)->QueryInterface(riid, ppvObj)
#define My_ID3D12PipelineLibrary_AddRef(pID3D12PipelineLibrary)\
    (pID3D12PipelineLibrary)->AddRef()
#define My_ID3D12PipelineLibrary_Release(pID3D12PipelineLibrary)\
    (pID3D12PipelineLibrary)->Release()
#define My_ID3D12PipelineLibrary_StorePipeline(pID3D12PipelineLibrary, pName, pPipeline)\
    (pID3D12PipelineLibrary)->StorePipeline(pName, pPipeline)
#define My_ID3D12PipelineLibrary_LoadGraphicsPipeline(pID3D12PipelineLibrary, pName, pDesc, riid, ppPipelineState)\
    (pID3D12PipelineLibrary)->LoadGraphicsPipeline(pName, pDesc, riid, ppPipelineState)
#define My_ID3D12PipelineLibrary_LoadComputePipeline(pID3D12PipelineLibrary, pName, pDesc, riid, ppPipelineState)\
    (pID3D12PipelineLibrary)->LoadComputePipeline(pName, pDesc, riid, ppPipelineState)
#define My_ID3D12PipelineLibrary_GetSerializedSize(pID3D12PipelineLibrary)\
    (pID3D12PipelineLibrary)->GetSerializedSize()
#define My_ID3D12PipelineLibrary_Serialize(pID3D12PipelineLibrary, pData, DataSizeInBytes)\
    (pID3D12PipelineLibrary)->Serialize(pData, DataSizeInBytes)

#define My_ID3D12Device1_QueryInterface(pID3D12Device1, riid, ppvObj)\
    (pID3D12Device1)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device1_AddRef(pID3D12Device1)\
    (pID3D12Device1)->AddRef()
#define My_ID3D12Device1_Release(pID3D12Device1)\
    (pID3D12Device1)->Release()
#define My_ID3D12Device1_CreatePipelineLibrary(pID3D12Device1, pLibraryBlob, BlobLength, riid, ppPipelineLibrary)\
    (pID3D12Device1)->CreatePipelineLibrary(pLibraryBlob, BlobLength, riid, ppPipelineLibrary)
#define My_ID3D12Device1_SetEventOnMultipleFenceCompletion(pID3D12Device1, ppFences, pFenceValues, NumFences, Flags, hEvent)\
    (pID3D12Device1)->SetEventOnMultipleFenceCompletion(ppFences, pFenceValues, NumFences, Flags, hEvent)
#define My_ID3D12Device1_SetResidencyPriority(pID3D12Device1, NumObjects, ppObjects, pPriorities)\
    (pID3D12Device1)->SetResidencyPriority(NumObjects, ppObjects, pPriorities)

#define My_D3D12EnableExperimentalFeatures(NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes)\
    D3D12EnableExperimentalFeatures(NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes)

#define My_ID3D12GraphicsCommandList1_QueryInterface(pID3D12GraphicsCommandList1, riid, ppvObj)\
    (pID3D12GraphicsCommandList1)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList1_AddRef(pID3D12GraphicsCommandList1)\
    (pID3D12GraphicsCommandList1)->AddRef()
#define My_ID3D12GraphicsCommandList1_Release(pID3D12GraphicsCommandList1)\
    (pID3D12GraphicsCommandList1)->Release()
#define My_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(pID3D12GraphicsCommandList1, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, ppDependentResources, pDependentSubresourceRanges)\
    (pID3D12GraphicsCommandList1)->AtomicCopyBufferUINT(pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, ppDependentResources, pDependentSubresourceRanges)
#define My_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(pID3D12GraphicsCommandList1, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, ppDependentResources, pDependentSubresourceRanges)\
    (pID3D12GraphicsCommandList1)->AtomicCopyBufferUINT64(pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, ppDependentResources, pDependentSubresourceRanges)
#define My_ID3D12GraphicsCommandList1_OMSetDepthBounds(pID3D12GraphicsCommandList1, Min, Max)\
    (pID3D12GraphicsCommandList1)->OMSetDepthBounds(Min, Max)
#define My_ID3D12GraphicsCommandList1_SetSamplePositions(pID3D12GraphicsCommandList1, NumSamplesPerPixel, NumPixels, pSamplePositions)\
    (pID3D12GraphicsCommandList1)->SetSamplePositions(NumSamplesPerPixel, NumPixels, pSamplePositions)
#define My_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(pID3D12GraphicsCommandList1, pDstResource, DstSubresource, DstX, DstY, pSrcResource, SrcSubresource, pSrcRect, Format, ResolveMode)\
    (pID3D12GraphicsCommandList1)->ResolveSubresourceRegion(pDstResource, DstSubresource, DstX, DstY, pSrcResource, SrcSubresource, pSrcRect, Format, ResolveMode)
#define My_ID3D12GraphicsCommandList1_SetViewInstanceMask(pID3D12GraphicsCommandList1, Mask)\
    (pID3D12GraphicsCommandList1)->SetViewInstanceMask(Mask)

#define My_ID3D12PipelineLibrary1_QueryInterface(pID3D12PipelineLibrary1, riid, ppvObj)\
    (pID3D12PipelineLibrary1)->QueryInterface(riid, ppvObj)
#define My_ID3D12PipelineLibrary1_AddRef(pID3D12PipelineLibrary1)\
    (pID3D12PipelineLibrary1)->AddRef()
#define My_ID3D12PipelineLibrary1_Release(pID3D12PipelineLibrary1)\
    (pID3D12PipelineLibrary1)->Release()
#define My_ID3D12PipelineLibrary1_LoadPipeline(pID3D12PipelineLibrary1, pName, pDesc, riid, ppPipelineState)\
    (pID3D12PipelineLibrary1)->LoadPipeline(pName, pDesc, riid, ppPipelineState)

#define My_ID3D12Device2_QueryInterface(pID3D12Device2, riid, ppvObj)\
    (pID3D12Device2)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device2_AddRef(pID3D12Device2)\
    (pID3D12Device2)->AddRef()
#define My_ID3D12Device2_Release(pID3D12Device2)\
    (pID3D12Device2)->Release()
#define My_ID3D12Device2_CreatePipelineState(pID3D12Device2, pDesc, riid, ppPipelineState)\
    (pID3D12Device2)->CreatePipelineState(pDesc, riid, ppPipelineState)

#define My_ID3D12Tools_QueryInterface(pID3D12Tools, riid, ppvObj)\
    (pID3D12Tools)->QueryInterface(riid, ppvObj)
#define My_ID3D12Tools_AddRef(pID3D12Tools)\
    (pID3D12Tools)->AddRef()
#define My_ID3D12Tools_Release(pID3D12Tools)\
    (pID3D12Tools)->Release()
#define My_ID3D12Tools_EnableShaderInstrumentation(pID3D12Tools, bEnable)\
    (pID3D12Tools)->EnableShaderInstrumentation(bEnable)
#define My_ID3D12Tools_ShaderInstrumentationEnabled(pID3D12Tools)\
    (pID3D12Tools)->ShaderInstrumentationEnabled()

#define My_ID3D12Fence1_QueryInterface(pID3D12Fence1, riid, ppvObj)\
    (pID3D12Fence1)->QueryInterface(riid, ppvObj)
#define My_ID3D12Fence1_AddRef(pID3D12Fence1)\
    (pID3D12Fence1)->AddRef()
#define My_ID3D12Fence1_Release(pID3D12Fence1)\
    (pID3D12Fence1)->Release()
#define My_ID3D12Fence1_GetCreationFlags(pID3D12Fence1)\
    (pID3D12Fence1)->GetCreationFlags()

#define My_ID3D12GraphicsCommandList2_QueryInterface(pID3D12GraphicsCommandList2, riid, ppvObj)\
    (pID3D12GraphicsCommandList2)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList2_AddRef(pID3D12GraphicsCommandList2)\
    (pID3D12GraphicsCommandList2)->AddRef()
#define My_ID3D12GraphicsCommandList2_Release(pID3D12GraphicsCommandList2)\
    (pID3D12GraphicsCommandList2)->Release()
#define My_ID3D12GraphicsCommandList2_WriteBufferImmediate(pID3D12GraphicsCommandList2, Count, pParams, pModes)\
    (pID3D12GraphicsCommandList2)->WriteBufferImmediate(Count, pParams, pModes)

#define My_ID3D12Device3_QueryInterface(pID3D12Device3, riid, ppvObj)\
    (pID3D12Device3)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device3_AddRef(pID3D12Device3)\
    (pID3D12Device3)->AddRef()
#define My_ID3D12Device3_Release(pID3D12Device3)\
    (pID3D12Device3)->Release()
#define My_ID3D12Device3_OpenExistingHeapFromAddress(pID3D12Device3, pAddress, riid, ppvHeap)\
    (pID3D12Device3)->OpenExistingHeapFromAddress(pAddress, riid, ppvHeap)
#define My_ID3D12Device3_OpenExistingHeapFromFileMapping(pID3D12Device3, hFileMapping, riid, ppvHeap)\
    (pID3D12Device3)->OpenExistingHeapFromFileMapping(hFileMapping, riid, ppvHeap)
#define My_ID3D12Device3_EnqueueMakeResident(pID3D12Device3, Flags, NumObjects, ppObjects, pFenceToSignal, FenceValueToSignal)\
    (pID3D12Device3)->EnqueueMakeResident(Flags, NumObjects, ppObjects, pFenceToSignal, FenceValueToSignal)

#define My_ID3D12ProtectedSession_QueryInterface(pID3D12ProtectedSession, riid, ppvObj)\
    (pID3D12ProtectedSession)->QueryInterface(riid, ppvObj)
#define My_ID3D12ProtectedSession_AddRef(pID3D12ProtectedSession)\
    (pID3D12ProtectedSession)->AddRef()
#define My_ID3D12ProtectedSession_Release(pID3D12ProtectedSession)\
    (pID3D12ProtectedSession)->Release()
#define My_ID3D12ProtectedSession_GetStatusFence(pID3D12ProtectedSession, riid, ppFence)\
    (pID3D12ProtectedSession)->GetStatusFence(riid, ppFence)
#define My_ID3D12ProtectedSession_GetSessionStatus(pID3D12ProtectedSession)\
    (pID3D12ProtectedSession)->GetSessionStatus()

#define My_ID3D12ProtectedResourceSession_QueryInterface(pID3D12ProtectedResourceSession, riid, ppvObj)\
    (pID3D12ProtectedResourceSession)->QueryInterface(riid, ppvObj)
#define My_ID3D12ProtectedResourceSession_AddRef(pID3D12ProtectedResourceSession)\
    (pID3D12ProtectedResourceSession)->AddRef()
#define My_ID3D12ProtectedResourceSession_Release(pID3D12ProtectedResourceSession)\
    (pID3D12ProtectedResourceSession)->Release()
#define My_ID3D12ProtectedResourceSession_GetDesc(pID3D12ProtectedResourceSession)\
    (pID3D12ProtectedResourceSession)->GetDesc()

#define My_ID3D12Device4_QueryInterface(pID3D12Device4, riid, ppvObj)\
    (pID3D12Device4)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device4_AddRef(pID3D12Device4)\
    (pID3D12Device4)->AddRef()
#define My_ID3D12Device4_Release(pID3D12Device4)\
    (pID3D12Device4)->Release()
#define My_ID3D12Device4_CreateCommandList1(pID3D12Device4, nodeMask, type, flags, riid, ppCommandList)\
    (pID3D12Device4)->CreateCommandList1(nodeMask, type, flags, riid, ppCommandList)
#define My_ID3D12Device4_CreateProtectedResourceSession(pID3D12Device4, pDesc, riid, ppSession)\
    (pID3D12Device4)->CreateProtectedResourceSession(pDesc, riid, ppSession)
#define My_ID3D12Device4_CreateCommittedResource1(pID3D12Device4, pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, pProtectedSession, riidResource, ppvResource)\
    (pID3D12Device4)->CreateCommittedResource1(pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, pProtectedSession, riidResource, ppvResource)
#define My_ID3D12Device4_CreateHeap1(pID3D12Device4, pDesc, pProtectedSession, riid, ppvHeap)\
    (pID3D12Device4)->CreateHeap1(pDesc, pProtectedSession, riid, ppvHeap)
#define My_ID3D12Device4_CreateReservedResource1(pID3D12Device4, pDesc, InitialState, pOptimizedClearValue, pProtectedSession, riid, ppvResource)\
    (pID3D12Device4)->CreateReservedResource1(pDesc, InitialState, pOptimizedClearValue, pProtectedSession, riid, ppvResource)
#define My_ID3D12Device4_GetResourceAllocationInfo1(pID3D12Device4, visibleMask, numResourceDescs, pResourceDescs, pResourceAllocationInfo1)\
    (pID3D12Device4)->GetResourceAllocationInfo1(visibleMask, numResourceDescs, pResourceDescs, pResourceAllocationInfo1)

#define My_ID3D12Resource1_QueryInterface(pID3D12Resource1, riid, ppvObj)\
    (pID3D12Resource1)->QueryInterface(riid, ppvObj)
#define My_ID3D12Resource1_AddRef(pID3D12Resource1)\
    (pID3D12Resource1)->AddRef()
#define My_ID3D12Resource1_Release(pID3D12Resource1)\
    (pID3D12Resource1)->Release()
#define My_ID3D12Resource1_GetProtectedResourceSession(pID3D12Resource1, riid, ppProtectedSession)\
    (pID3D12Resource1)->GetProtectedResourceSession(riid, ppProtectedSession)

#define My_ID3D12Heap1_QueryInterface(pID3D12Heap1, riid, ppvObj)\
    (pID3D12Heap1)->QueryInterface(riid, ppvObj)
#define My_ID3D12Heap1_AddRef(pID3D12Heap1)\
    (pID3D12Heap1)->AddRef()
#define My_ID3D12Heap1_Release(pID3D12Heap1)\
    (pID3D12Heap1)->Release()
#define My_ID3D12Heap1_GetProtectedResourceSession(pID3D12Heap1, riid, ppProtectedSession)\
    (pID3D12Heap1)->GetProtectedResourceSession(riid, ppProtectedSession)

#define My_ID3D12GraphicsCommandList3_QueryInterface(pID3D12GraphicsCommandList3, riid, ppvObj)\
    (pID3D12GraphicsCommandList3)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList3_AddRef(pID3D12GraphicsCommandList3)\
    (pID3D12GraphicsCommandList3)->AddRef()
#define My_ID3D12GraphicsCommandList3_Release(pID3D12GraphicsCommandList3)\
    (pID3D12GraphicsCommandList3)->Release()
#define My_ID3D12GraphicsCommandList3_SetProtectedResourceSession(pID3D12GraphicsCommandList3, pProtectedResourceSession)\
    (pID3D12GraphicsCommandList3)->SetProtectedResourceSession(pProtectedResourceSession)

#define My_ID3D12LifetimeOwner_QueryInterface(pID3D12LifetimeOwner, riid, ppvObj)\
    (pID3D12LifetimeOwner)->QueryInterface(riid, ppvObj)
#define My_ID3D12LifetimeOwner_AddRef(pID3D12LifetimeOwner)\
    (pID3D12LifetimeOwner)->AddRef()
#define My_ID3D12LifetimeOwner_Release(pID3D12LifetimeOwner)\
    (pID3D12LifetimeOwner)->Release()
#define My_ID3D12LifetimeOwner_LifetimeStateUpdated(pID3D12LifetimeOwner, NewState)\
    (pID3D12LifetimeOwner)->LifetimeStateUpdated(NewState)

#define My_ID3D12SwapChainAssistant_QueryInterface(pID3D12SwapChainAssistant, riid, ppvObj)\
    (pID3D12SwapChainAssistant)->QueryInterface(riid, ppvObj)
#define My_ID3D12SwapChainAssistant_AddRef(pID3D12SwapChainAssistant)\
    (pID3D12SwapChainAssistant)->AddRef()
#define My_ID3D12SwapChainAssistant_Release(pID3D12SwapChainAssistant)\
    (pID3D12SwapChainAssistant)->Release()
#define My_ID3D12SwapChainAssistant_GetLUID(pID3D12SwapChainAssistant)\
    (pID3D12SwapChainAssistant)->GetLUID()
#define My_ID3D12SwapChainAssistant_GetSwapChainObject(pID3D12SwapChainAssistant, riid, ppv)\
    (pID3D12SwapChainAssistant)->GetSwapChainObject(riid, ppv)
#define My_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(pID3D12SwapChainAssistant, riidResource, ppvResource, riidQueue, ppvQueue)\
    (pID3D12SwapChainAssistant)->GetCurrentResourceAndCommandQueue(riidResource, ppvResource, riidQueue, ppvQueue)
#define My_ID3D12SwapChainAssistant_InsertImplicitSync(pID3D12SwapChainAssistant)\
    (pID3D12SwapChainAssistant)->InsertImplicitSync()

#define My_ID3D12LifetimeTracker_QueryInterface(pID3D12LifetimeTracker, riid, ppvObj)\
    (pID3D12LifetimeTracker)->QueryInterface(riid, ppvObj)
#define My_ID3D12LifetimeTracker_AddRef(pID3D12LifetimeTracker)\
    (pID3D12LifetimeTracker)->AddRef()
#define My_ID3D12LifetimeTracker_Release(pID3D12LifetimeTracker)\
    (pID3D12LifetimeTracker)->Release()
#define My_ID3D12LifetimeTracker_DestroyOwnedObject(pID3D12LifetimeTracker, pObject)\
    (pID3D12LifetimeTracker)->DestroyOwnedObject(pObject)

#define My_ID3D12StateObject_QueryInterface(pID3D12StateObject, riid, ppvObj)\
    (pID3D12StateObject)->QueryInterface(riid, ppvObj)
#define My_ID3D12StateObject_AddRef(pID3D12StateObject)\
    (pID3D12StateObject)->AddRef()
#define My_ID3D12StateObject_Release(pID3D12StateObject)\
    (pID3D12StateObject)->Release()

#define My_ID3D12StateObjectProperties_QueryInterface(pID3D12StateObjectProperties, riid, ppvObj)\
    (pID3D12StateObjectProperties)->QueryInterface(riid, ppvObj)
#define My_ID3D12StateObjectProperties_AddRef(pID3D12StateObjectProperties)\
    (pID3D12StateObjectProperties)->AddRef()
#define My_ID3D12StateObjectProperties_Release(pID3D12StateObjectProperties)\
    (pID3D12StateObjectProperties)->Release()
#define My_ID3D12StateObjectProperties_GetShaderIdentifier(pID3D12StateObjectProperties, pExportName)\
    (pID3D12StateObjectProperties)->GetShaderIdentifier(pExportName)
#define My_ID3D12StateObjectProperties_GetShaderStackSize(pID3D12StateObjectProperties, pExportName)\
    (pID3D12StateObjectProperties)->GetShaderStackSize(pExportName)
#define My_ID3D12StateObjectProperties_GetPipelineStackSize(pID3D12StateObjectProperties)\
    (pID3D12StateObjectProperties)->GetPipelineStackSize()
#define My_ID3D12StateObjectProperties_SetPipelineStackSize(pID3D12StateObjectProperties, PipelineStackSizeInBytes)\
    (pID3D12StateObjectProperties)->SetPipelineStackSize(PipelineStackSizeInBytes)

#define My_ID3D12Device5_QueryInterface(pID3D12Device5, riid, ppvObj)\
    (pID3D12Device5)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device5_AddRef(pID3D12Device5)\
    (pID3D12Device5)->AddRef()
#define My_ID3D12Device5_Release(pID3D12Device5)\
    (pID3D12Device5)->Release()
#define My_ID3D12Device5_CreateLifetimeTracker(pID3D12Device5, pOwner, riid, ppvTracker)\
    (pID3D12Device5)->CreateLifetimeTracker(pOwner, riid, ppvTracker)
#define My_ID3D12Device5_RemoveDevice(pID3D12Device5)\
    (pID3D12Device5)->RemoveDevice()
#define My_ID3D12Device5_EnumerateMetaCommands(pID3D12Device5, pNumMetaCommands, pDescs)\
    (pID3D12Device5)->EnumerateMetaCommands(pNumMetaCommands, pDescs)
#define My_ID3D12Device5_EnumerateMetaCommandParameters(pID3D12Device5, CommandId, Stage, pTotalStructureSizeInBytes, pParameterCount, pParameterDescs)\
    (pID3D12Device5)->EnumerateMetaCommandParameters(CommandId, Stage, pTotalStructureSizeInBytes, pParameterCount, pParameterDescs)
#define My_ID3D12Device5_CreateMetaCommand(pID3D12Device5, CommandId, NodeMask, pCreationParametersData, CreationParametersDataSizeInBytes, riid, ppMetaCommand)\
    (pID3D12Device5)->CreateMetaCommand(CommandId, NodeMask, pCreationParametersData, CreationParametersDataSizeInBytes, riid, ppMetaCommand)
#define My_ID3D12Device5_CreateStateObject(pID3D12Device5, pDesc, riid, ppStateObject)\
    (pID3D12Device5)->CreateStateObject(pDesc, riid, ppStateObject)
#define My_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(pID3D12Device5, pDesc, pInfo)\
    (pID3D12Device5)->GetRaytracingAccelerationStructurePrebuildInfo(pDesc, pInfo)
#define My_ID3D12Device5_CheckDriverMatchingIdentifier(pID3D12Device5, SerializedDataType, pIdentifierToCheck)\
    (pID3D12Device5)->CheckDriverMatchingIdentifier(SerializedDataType, pIdentifierToCheck)

#define My_ID3D12MetaCommand_QueryInterface(pID3D12MetaCommand, riid, ppvObj)\
    (pID3D12MetaCommand)->QueryInterface(riid, ppvObj)
#define My_ID3D12MetaCommand_AddRef(pID3D12MetaCommand)\
    (pID3D12MetaCommand)->AddRef()
#define My_ID3D12MetaCommand_Release(pID3D12MetaCommand)\
    (pID3D12MetaCommand)->Release()
#define My_ID3D12MetaCommand_GetRequiredParameterResourceSize(pID3D12MetaCommand, Stage, ParameterIndex)\
    (pID3D12MetaCommand)->GetRequiredParameterResourceSize(Stage, ParameterIndex)

#define My_ID3D12GraphicsCommandList4_QueryInterface(pID3D12GraphicsCommandList4, riid, ppvObj)\
    (pID3D12GraphicsCommandList4)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList4_AddRef(pID3D12GraphicsCommandList4)\
    (pID3D12GraphicsCommandList4)->AddRef()
#define My_ID3D12GraphicsCommandList4_Release(pID3D12GraphicsCommandList4)\
    (pID3D12GraphicsCommandList4)->Release()
#define My_ID3D12GraphicsCommandList4_BeginRenderPass(pID3D12GraphicsCommandList4, NumRenderTargets, pRenderTargets, pDepthStencil, Flags)\
    (pID3D12GraphicsCommandList4)->BeginRenderPass(NumRenderTargets, pRenderTargets, pDepthStencil, Flags)
#define My_ID3D12GraphicsCommandList4_EndRenderPass(pID3D12GraphicsCommandList4)\
    (pID3D12GraphicsCommandList4)->EndRenderPass()
#define My_ID3D12GraphicsCommandList4_InitializeMetaCommand(pID3D12GraphicsCommandList4, pMetaCommand, pInitializationParametersData, InitializationParametersDataSizeInBytes)\
    (pID3D12GraphicsCommandList4)->InitializeMetaCommand(pMetaCommand, pInitializationParametersData, InitializationParametersDataSizeInBytes)
#define My_ID3D12GraphicsCommandList4_ExecuteMetaCommand(pID3D12GraphicsCommandList4, pMetaCommand, pExecutionParametersData, ExecutionParametersDataSizeInBytes)\
    (pID3D12GraphicsCommandList4)->ExecuteMetaCommand(pMetaCommand, pExecutionParametersData, ExecutionParametersDataSizeInBytes)
#define My_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(pID3D12GraphicsCommandList4, pDesc, NumPostbuildInfoDescs, pPostbuildInfoDescs)\
    (pID3D12GraphicsCommandList4)->BuildRaytracingAccelerationStructure(pDesc, NumPostbuildInfoDescs, pPostbuildInfoDescs)
#define My_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(pID3D12GraphicsCommandList4, pDesc, NumSourceAccelerationStructures, pSourceAccelerationStructureData)\
    (pID3D12GraphicsCommandList4)->EmitRaytracingAccelerationStructurePostbuildInfo(pDesc, NumSourceAccelerationStructures, pSourceAccelerationStructureData)
#define My_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(pID3D12GraphicsCommandList4, DestAccelerationStructureData, SourceAccelerationStructureData, Mode)\
    (pID3D12GraphicsCommandList4)->CopyRaytracingAccelerationStructure(DestAccelerationStructureData, SourceAccelerationStructureData, Mode)
#define My_ID3D12GraphicsCommandList4_SetPipelineState1(pID3D12GraphicsCommandList4, pStateObject)\
    (pID3D12GraphicsCommandList4)->SetPipelineState1(pStateObject)
#define My_ID3D12GraphicsCommandList4_DispatchRays(pID3D12GraphicsCommandList4, pDesc)\
    (pID3D12GraphicsCommandList4)->DispatchRays(pDesc)

#define My_ID3D12DeviceRemovedExtendedDataSettings_QueryInterface(pID3D12DeviceRemovedExtendedDataSettings, riid, ppvObj)\
    (pID3D12DeviceRemovedExtendedDataSettings)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceRemovedExtendedDataSettings_AddRef(pID3D12DeviceRemovedExtendedDataSettings)\
    (pID3D12DeviceRemovedExtendedDataSettings)->AddRef()
#define My_ID3D12DeviceRemovedExtendedDataSettings_Release(pID3D12DeviceRemovedExtendedDataSettings)\
    (pID3D12DeviceRemovedExtendedDataSettings)->Release()
#define My_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(pID3D12DeviceRemovedExtendedDataSettings, Enablement)\
    (pID3D12DeviceRemovedExtendedDataSettings)->SetAutoBreadcrumbsEnablement(Enablement)
#define My_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(pID3D12DeviceRemovedExtendedDataSettings, Enablement)\
    (pID3D12DeviceRemovedExtendedDataSettings)->SetPageFaultEnablement(Enablement)
#define My_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(pID3D12DeviceRemovedExtendedDataSettings, Enablement)\
    (pID3D12DeviceRemovedExtendedDataSettings)->SetWatsonDumpEnablement(Enablement)

#define My_ID3D12DeviceRemovedExtendedData_QueryInterface(pID3D12DeviceRemovedExtendedData, riid, ppvObj)\
    (pID3D12DeviceRemovedExtendedData)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceRemovedExtendedData_AddRef(pID3D12DeviceRemovedExtendedData)\
    (pID3D12DeviceRemovedExtendedData)->AddRef()
#define My_ID3D12DeviceRemovedExtendedData_Release(pID3D12DeviceRemovedExtendedData)\
    (pID3D12DeviceRemovedExtendedData)->Release()
#define My_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(pID3D12DeviceRemovedExtendedData, pOutput)\
    (pID3D12DeviceRemovedExtendedData)->GetAutoBreadcrumbsOutput(pOutput)
#define My_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(pID3D12DeviceRemovedExtendedData, pOutput)\
    (pID3D12DeviceRemovedExtendedData)->GetPageFaultAllocationOutput(pOutput)

#define My_ID3D12Device6_QueryInterface(pID3D12Device6, riid, ppvObj)\
    (pID3D12Device6)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device6_AddRef(pID3D12Device6)\
    (pID3D12Device6)->AddRef()
#define My_ID3D12Device6_Release(pID3D12Device6)\
    (pID3D12Device6)->Release()
#define My_ID3D12Device6_SetBackgroundProcessingMode(pID3D12Device6, Mode, MeasurementsAction, hEventToSignalUponCompletion, pbFurtherMeasurementsDesired)\
    (pID3D12Device6)->SetBackgroundProcessingMode(Mode, MeasurementsAction, hEventToSignalUponCompletion, pbFurtherMeasurementsDesired)

#define My_ID3D12GraphicsCommandList5_QueryInterface(pID3D12GraphicsCommandList5, riid, ppvObj)\
    (pID3D12GraphicsCommandList5)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList5_AddRef(pID3D12GraphicsCommandList5)\
    (pID3D12GraphicsCommandList5)->AddRef()
#define My_ID3D12GraphicsCommandList5_Release(pID3D12GraphicsCommandList5)\
    (pID3D12GraphicsCommandList5)->Release()
#define My_ID3D12GraphicsCommandList5_RSSetShadingRate(pID3D12GraphicsCommandList5, baseShadingRate, combiners)\
    (pID3D12GraphicsCommandList5)->RSSetShadingRate(baseShadingRate, combiners)
#define My_ID3D12GraphicsCommandList5_RSSetShadingRateImage(pID3D12GraphicsCommandList5, shadingRateImage)\
    (pID3D12GraphicsCommandList5)->RSSetShadingRateImage(shadingRateImage)

#define My_ID3D12DeviceRemovedExtendedDataSettings1_QueryInterface(pID3D12DeviceRemovedExtendedDataSettings1, riid, ppvObj)\
    (pID3D12DeviceRemovedExtendedDataSettings1)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceRemovedExtendedDataSettings1_AddRef(pID3D12DeviceRemovedExtendedDataSettings1)\
    (pID3D12DeviceRemovedExtendedDataSettings1)->AddRef()
#define My_ID3D12DeviceRemovedExtendedDataSettings1_Release(pID3D12DeviceRemovedExtendedDataSettings1)\
    (pID3D12DeviceRemovedExtendedDataSettings1)->Release()
#define My_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(pID3D12DeviceRemovedExtendedDataSettings1, Enablement)\
    (pID3D12DeviceRemovedExtendedDataSettings1)->SetBreadcrumbContextEnablement(Enablement)

#define My_ID3D12DeviceRemovedExtendedData1_QueryInterface(pID3D12DeviceRemovedExtendedData1, riid, ppvObj)\
    (pID3D12DeviceRemovedExtendedData1)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceRemovedExtendedData1_AddRef(pID3D12DeviceRemovedExtendedData1)\
    (pID3D12DeviceRemovedExtendedData1)->AddRef()
#define My_ID3D12DeviceRemovedExtendedData1_Release(pID3D12DeviceRemovedExtendedData1)\
    (pID3D12DeviceRemovedExtendedData1)->Release()
#define My_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(pID3D12DeviceRemovedExtendedData1, pOutput)\
    (pID3D12DeviceRemovedExtendedData1)->GetAutoBreadcrumbsOutput1(pOutput)
#define My_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(pID3D12DeviceRemovedExtendedData1, pOutput)\
    (pID3D12DeviceRemovedExtendedData1)->GetPageFaultAllocationOutput1(pOutput)

#define My_ID3D12ProtectedResourceSession1_QueryInterface(pID3D12ProtectedResourceSession1, riid, ppvObj)\
    (pID3D12ProtectedResourceSession1)->QueryInterface(riid, ppvObj)
#define My_ID3D12ProtectedResourceSession1_AddRef(pID3D12ProtectedResourceSession1)\
    (pID3D12ProtectedResourceSession1)->AddRef()
#define My_ID3D12ProtectedResourceSession1_Release(pID3D12ProtectedResourceSession1)\
    (pID3D12ProtectedResourceSession1)->Release()
#define My_ID3D12ProtectedResourceSession1_GetDesc1(pID3D12ProtectedResourceSession1)\
    (pID3D12ProtectedResourceSession1)->GetDesc1()

#define My_ID3D12Device7_QueryInterface(pID3D12Device7, riid, ppvObj)\
    (pID3D12Device7)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device7_AddRef(pID3D12Device7)\
    (pID3D12Device7)->AddRef()
#define My_ID3D12Device7_Release(pID3D12Device7)\
    (pID3D12Device7)->Release()
#define My_ID3D12Device7_AddToStateObject(pID3D12Device7, pAddition, pStateObjectToGrowFrom, riid, ppNewStateObject)\
    (pID3D12Device7)->AddToStateObject(pAddition, pStateObjectToGrowFrom, riid, ppNewStateObject)
#define My_ID3D12Device7_CreateProtectedResourceSession1(pID3D12Device7, pDesc, riid, ppSession)\
    (pID3D12Device7)->CreateProtectedResourceSession1(pDesc, riid, ppSession)

#define My_ID3D12Device8_QueryInterface(pID3D12Device8, riid, ppvObj)\
    (pID3D12Device8)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device8_AddRef(pID3D12Device8)\
    (pID3D12Device8)->AddRef()
#define My_ID3D12Device8_Release(pID3D12Device8)\
    (pID3D12Device8)->Release()
#define My_ID3D12Device8_GetResourceAllocationInfo2(pID3D12Device8, visibleMask, numResourceDescs, pResourceDescs, pResourceAllocationInfo1)\
    (pID3D12Device8)->GetResourceAllocationInfo2(visibleMask, numResourceDescs, pResourceDescs, pResourceAllocationInfo1)
#define My_ID3D12Device8_CreateCommittedResource2(pID3D12Device8, pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, pProtectedSession, riidResource, ppvResource)\
    (pID3D12Device8)->CreateCommittedResource2(pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, pProtectedSession, riidResource, ppvResource)
#define My_ID3D12Device8_CreatePlacedResource1(pID3D12Device8, pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource)\
    (pID3D12Device8)->CreatePlacedResource1(pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource)
#define My_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(pID3D12Device8, pTargetedResource, pFeedbackResource, DestDescriptor)\
    (pID3D12Device8)->CreateSamplerFeedbackUnorderedAccessView(pTargetedResource, pFeedbackResource, DestDescriptor)
#define My_ID3D12Device8_GetCopyableFootprints1(pID3D12Device8, pResourceDesc, FirstSubresource, NumSubresources, BaseOffset, pLayouts, pNumRows, pRowSizeInBytes, pTotalBytes)\
    (pID3D12Device8)->GetCopyableFootprints1(pResourceDesc, FirstSubresource, NumSubresources, BaseOffset, pLayouts, pNumRows, pRowSizeInBytes, pTotalBytes)

#define My_ID3D12Resource2_QueryInterface(pID3D12Resource2, riid, ppvObj)\
    (pID3D12Resource2)->QueryInterface(riid, ppvObj)
#define My_ID3D12Resource2_AddRef(pID3D12Resource2)\
    (pID3D12Resource2)->AddRef()
#define My_ID3D12Resource2_Release(pID3D12Resource2)\
    (pID3D12Resource2)->Release()
#define My_ID3D12Resource2_GetDesc1(pID3D12Resource2)\
    (pID3D12Resource2)->GetDesc1()

#define My_ID3D12GraphicsCommandList6_QueryInterface(pID3D12GraphicsCommandList6, riid, ppvObj)\
    (pID3D12GraphicsCommandList6)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList6_AddRef(pID3D12GraphicsCommandList6)\
    (pID3D12GraphicsCommandList6)->AddRef()
#define My_ID3D12GraphicsCommandList6_Release(pID3D12GraphicsCommandList6)\
    (pID3D12GraphicsCommandList6)->Release()
#define My_ID3D12GraphicsCommandList6_DispatchMesh(pID3D12GraphicsCommandList6, ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ)\
    (pID3D12GraphicsCommandList6)->DispatchMesh(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ)

#define My_D3D12GetInterface(rclsid, riid, ppvDebug)\
    D3D12GetInterface(rclsid, riid, ppvDebug)

#define My_ID3D12ShaderCacheSession_QueryInterface(pID3D12ShaderCacheSession, riid, ppvObj)\
    (pID3D12ShaderCacheSession)->QueryInterface(riid, ppvObj)
#define My_ID3D12ShaderCacheSession_AddRef(pID3D12ShaderCacheSession)\
    (pID3D12ShaderCacheSession)->AddRef()
#define My_ID3D12ShaderCacheSession_Release(pID3D12ShaderCacheSession)\
    (pID3D12ShaderCacheSession)->Release()
#define My_ID3D12ShaderCacheSession_FindValue(pID3D12ShaderCacheSession, pKey, KeySize, pValue, pValueSize)\
    (pID3D12ShaderCacheSession)->FindValue(pKey, KeySize, pValue, pValueSize)
#define My_ID3D12ShaderCacheSession_StoreValue(pID3D12ShaderCacheSession, pKey, KeySize, pValue, ValueSize)\
    (pID3D12ShaderCacheSession)->StoreValue(pKey, KeySize, pValue, ValueSize)
#define My_ID3D12ShaderCacheSession_SetDeleteOnDestroy(pID3D12ShaderCacheSession)\
    (pID3D12ShaderCacheSession)->SetDeleteOnDestroy()
#define My_ID3D12ShaderCacheSession_GetDesc(pID3D12ShaderCacheSession)\
    (pID3D12ShaderCacheSession)->GetDesc()

#define My_ID3D12Device9_QueryInterface(pID3D12Device9, riid, ppvObj)\
    (pID3D12Device9)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device9_AddRef(pID3D12Device9)\
    (pID3D12Device9)->AddRef()
#define My_ID3D12Device9_Release(pID3D12Device9)\
    (pID3D12Device9)->Release()
#define My_ID3D12Device9_CreateShaderCacheSession(pID3D12Device9, pDesc, riid, ppvSession)\
    (pID3D12Device9)->CreateShaderCacheSession(pDesc, riid, ppvSession)
#define My_ID3D12Device9_ShaderCacheControl(pID3D12Device9, Kinds, Control)\
    (pID3D12Device9)->ShaderCacheControl(Kinds, Control)
#define My_ID3D12Device9_CreateCommandQueue1(pID3D12Device9, pDesc, CreatorID, riid, ppCommandQueue)\
    (pID3D12Device9)->CreateCommandQueue1(pDesc, CreatorID, riid, ppCommandQueue)

#define My_ID3D12SDKConfiguration_QueryInterface(pID3D12SDKConfiguration, riid, ppvObj)\
    (pID3D12SDKConfiguration)->QueryInterface(riid, ppvObj)
#define My_ID3D12SDKConfiguration_AddRef(pID3D12SDKConfiguration)\
    (pID3D12SDKConfiguration)->AddRef()
#define My_ID3D12SDKConfiguration_Release(pID3D12SDKConfiguration)\
    (pID3D12SDKConfiguration)->Release()
#define My_ID3D12SDKConfiguration_SetSDKVersion(pID3D12SDKConfiguration, SDKVersion, SDKPath)\
    (pID3D12SDKConfiguration)->SetSDKVersion(SDKVersion, SDKPath)

#define My_ID3D12DeviceRemovedExtendedData2_QueryInterface(pID3D12DeviceRemovedExtendedData2, riid, ppvObj)\
    (pID3D12DeviceRemovedExtendedData2)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceRemovedExtendedData2_AddRef(pID3D12DeviceRemovedExtendedData2)\
    (pID3D12DeviceRemovedExtendedData2)->AddRef()
#define My_ID3D12DeviceRemovedExtendedData2_Release(pID3D12DeviceRemovedExtendedData2)\
    (pID3D12DeviceRemovedExtendedData2)->Release()
#define My_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(pID3D12DeviceRemovedExtendedData2, pOutput)\
    (pID3D12DeviceRemovedExtendedData2)->GetPageFaultAllocationOutput2(pOutput)
#define My_ID3D12DeviceRemovedExtendedData2_GetDeviceState(pID3D12DeviceRemovedExtendedData2)\
    (pID3D12DeviceRemovedExtendedData2)->GetDeviceState()

#define My_ID3D12Device10_QueryInterface(pID3D12Device10, riid, ppvObj)\
    (pID3D12Device10)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device10_AddRef(pID3D12Device10)\
    (pID3D12Device10)->AddRef()
#define My_ID3D12Device10_Release(pID3D12Device10)\
    (pID3D12Device10)->Release()
#define My_ID3D12Device10_CreateCommittedResource3(pID3D12Device10, pHeapProperties, HeapFlags, pDesc, InitialLayout, pOptimizedClearValue, pProtectedSession, NumCastableFormats, pCastableFormats, riidResource, ppvResource)\
    (pID3D12Device10)->CreateCommittedResource3(pHeapProperties, HeapFlags, pDesc, InitialLayout, pOptimizedClearValue, pProtectedSession, NumCastableFormats, pCastableFormats, riidResource, ppvResource)
#define My_ID3D12Device10_CreatePlacedResource2(pID3D12Device10, pHeap, HeapOffset, pDesc, InitialLayout, pOptimizedClearValue, NumCastableFormats, pCastableFormats, riid, ppvResource)\
    (pID3D12Device10)->CreatePlacedResource2(pHeap, HeapOffset, pDesc, InitialLayout, pOptimizedClearValue, NumCastableFormats, pCastableFormats, riid, ppvResource)
#define My_ID3D12Device10_CreateReservedResource2(pID3D12Device10, pDesc, InitialLayout, pOptimizedClearValue, pProtectedSession, NumCastableFormats, pCastableFormats, riid, ppvResource)\
    (pID3D12Device10)->CreateReservedResource2(pDesc, InitialLayout, pOptimizedClearValue, pProtectedSession, NumCastableFormats, pCastableFormats, riid, ppvResource)

#define My_ID3D12VirtualizationGuestDevice_QueryInterface(pID3D12VirtualizationGuestDevice, riid, ppvObj)\
    (pID3D12VirtualizationGuestDevice)->QueryInterface(riid, ppvObj)
#define My_ID3D12VirtualizationGuestDevice_AddRef(pID3D12VirtualizationGuestDevice)\
    (pID3D12VirtualizationGuestDevice)->AddRef()
#define My_ID3D12VirtualizationGuestDevice_Release(pID3D12VirtualizationGuestDevice)\
    (pID3D12VirtualizationGuestDevice)->Release()
#define My_ID3D12VirtualizationGuestDevice_ShareWithHost(pID3D12VirtualizationGuestDevice, pObject, pHandle)\
    (pID3D12VirtualizationGuestDevice)->ShareWithHost(pObject, pHandle)
#define My_ID3D12VirtualizationGuestDevice_CreateFenceFd(pID3D12VirtualizationGuestDevice, pFence, FenceValue, pFenceFd)\
    (pID3D12VirtualizationGuestDevice)->CreateFenceFd(pFence, FenceValue, pFenceFd)

#define My_ID3D12GraphicsCommandList7_QueryInterface(pID3D12GraphicsCommandList7, riid, ppvObj)\
    (pID3D12GraphicsCommandList7)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList7_AddRef(pID3D12GraphicsCommandList7)\
    (pID3D12GraphicsCommandList7)->AddRef()
#define My_ID3D12GraphicsCommandList7_Release(pID3D12GraphicsCommandList7)\
    (pID3D12GraphicsCommandList7)->Release()
#define My_ID3D12GraphicsCommandList7_Barrier(pID3D12GraphicsCommandList7, NumBarrierGroups, pBarrierGroups)\
    (pID3D12GraphicsCommandList7)->Barrier(NumBarrierGroups, pBarrierGroups)

#define My_ID3D12GraphicsCommandList8_QueryInterface(pID3D12GraphicsCommandList8, riid, ppvObj)\
    (pID3D12GraphicsCommandList8)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList8_AddRef(pID3D12GraphicsCommandList8)\
    (pID3D12GraphicsCommandList8)->AddRef()
#define My_ID3D12GraphicsCommandList8_Release(pID3D12GraphicsCommandList8)\
    (pID3D12GraphicsCommandList8)->Release()
#define My_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(pID3D12GraphicsCommandList8, FrontStencilRef, BackStencilRef)\
    (pID3D12GraphicsCommandList8)->OMSetFrontAndBackStencilRef(FrontStencilRef, BackStencilRef)

#define My_ID3D12DeviceRemovedExtendedDataSettings2_QueryInterface(pID3D12DeviceRemovedExtendedDataSettings2, riid, ppvObj)\
    (pID3D12DeviceRemovedExtendedDataSettings2)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceRemovedExtendedDataSettings2_AddRef(pID3D12DeviceRemovedExtendedDataSettings2)\
    (pID3D12DeviceRemovedExtendedDataSettings2)->AddRef()
#define My_ID3D12DeviceRemovedExtendedDataSettings2_Release(pID3D12DeviceRemovedExtendedDataSettings2)\
    (pID3D12DeviceRemovedExtendedDataSettings2)->Release()
#define My_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(pID3D12DeviceRemovedExtendedDataSettings2, MarkersOnly)\
    (pID3D12DeviceRemovedExtendedDataSettings2)->UseMarkersOnlyAutoBreadcrumbs(MarkersOnly)

#define My_ID3D12Device11_QueryInterface(pID3D12Device11, riid, ppvObj)\
    (pID3D12Device11)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device11_AddRef(pID3D12Device11)\
    (pID3D12Device11)->AddRef()
#define My_ID3D12Device11_Release(pID3D12Device11)\
    (pID3D12Device11)->Release()
#define My_ID3D12Device11_CreateSampler2(pID3D12Device11, pDesc, DestDescriptor)\
    (pID3D12Device11)->CreateSampler2(pDesc, DestDescriptor)

#define My_ID3D12SDKConfiguration1_QueryInterface(pID3D12SDKConfiguration1, riid, ppvObj)\
    (pID3D12SDKConfiguration1)->QueryInterface(riid, ppvObj)
#define My_ID3D12SDKConfiguration1_AddRef(pID3D12SDKConfiguration1)\
    (pID3D12SDKConfiguration1)->AddRef()
#define My_ID3D12SDKConfiguration1_Release(pID3D12SDKConfiguration1)\
    (pID3D12SDKConfiguration1)->Release()
#define My_ID3D12SDKConfiguration1_CreateDeviceFactory(pID3D12SDKConfiguration1, SDKVersion, SDKPath, riid, ppvFactory)\
    (pID3D12SDKConfiguration1)->CreateDeviceFactory(SDKVersion, SDKPath, riid, ppvFactory)
#define My_ID3D12SDKConfiguration1_FreeUnusedSDKs(pID3D12SDKConfiguration1)\
    (pID3D12SDKConfiguration1)->FreeUnusedSDKs()

#define My_ID3D12DeviceFactory_QueryInterface(pID3D12DeviceFactory, riid, ppvObj)\
    (pID3D12DeviceFactory)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceFactory_AddRef(pID3D12DeviceFactory)\
    (pID3D12DeviceFactory)->AddRef()
#define My_ID3D12DeviceFactory_Release(pID3D12DeviceFactory)\
    (pID3D12DeviceFactory)->Release()
#define My_ID3D12DeviceFactory_InitializeFromGlobalState(pID3D12DeviceFactory)\
    (pID3D12DeviceFactory)->InitializeFromGlobalState()
#define My_ID3D12DeviceFactory_ApplyToGlobalState(pID3D12DeviceFactory)\
    (pID3D12DeviceFactory)->ApplyToGlobalState()
#define My_ID3D12DeviceFactory_SetFlags(pID3D12DeviceFactory, flags)\
    (pID3D12DeviceFactory)->SetFlags(flags)
#define My_ID3D12DeviceFactory_GetFlags(pID3D12DeviceFactory)\
    (pID3D12DeviceFactory)->GetFlags()
#define My_ID3D12DeviceFactory_GetConfigurationInterface(pID3D12DeviceFactory, clsid, iid, ppv)\
    (pID3D12DeviceFactory)->GetConfigurationInterface(clsid, iid, ppv)
#define My_ID3D12DeviceFactory_EnableExperimentalFeatures(pID3D12DeviceFactory, NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes)\
    (pID3D12DeviceFactory)->EnableExperimentalFeatures(NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes)
#define My_ID3D12DeviceFactory_CreateDevice(pID3D12DeviceFactory, adapter, FeatureLevel, riid, ppvDevice)\
    (pID3D12DeviceFactory)->CreateDevice(adapter, FeatureLevel, riid, ppvDevice)

#define My_ID3D12DeviceConfiguration_QueryInterface(pID3D12DeviceConfiguration, riid, ppvObj)\
    (pID3D12DeviceConfiguration)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceConfiguration_AddRef(pID3D12DeviceConfiguration)\
    (pID3D12DeviceConfiguration)->AddRef()
#define My_ID3D12DeviceConfiguration_Release(pID3D12DeviceConfiguration)\
    (pID3D12DeviceConfiguration)->Release()
#define My_ID3D12DeviceConfiguration_GetDesc(pID3D12DeviceConfiguration)\
    (pID3D12DeviceConfiguration)->GetDesc()
#define My_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(pID3D12DeviceConfiguration, pGuids, NumGuids)\
    (pID3D12DeviceConfiguration)->GetEnabledExperimentalFeatures(pGuids, NumGuids)
#define My_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(pID3D12DeviceConfiguration, pDesc, ppResult, ppError)\
    (pID3D12DeviceConfiguration)->SerializeVersionedRootSignature(pDesc, ppResult, ppError)
#define My_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(pID3D12DeviceConfiguration, pBlob, Size, riid, ppvDeserializer)\
    (pID3D12DeviceConfiguration)->CreateVersionedRootSignatureDeserializer(pBlob, Size, riid, ppvDeserializer)

#define My_ID3D12GraphicsCommandList9_QueryInterface(pID3D12GraphicsCommandList9, riid, ppvObj)\
    (pID3D12GraphicsCommandList9)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandList9_AddRef(pID3D12GraphicsCommandList9)\
    (pID3D12GraphicsCommandList9)->AddRef()
#define My_ID3D12GraphicsCommandList9_Release(pID3D12GraphicsCommandList9)\
    (pID3D12GraphicsCommandList9)->Release()
#define My_ID3D12GraphicsCommandList9_RSSetDepthBias(pID3D12GraphicsCommandList9, DepthBias, DepthBiasClamp, SlopeScaledDepthBias)\
    (pID3D12GraphicsCommandList9)->RSSetDepthBias(DepthBias, DepthBiasClamp, SlopeScaledDepthBias)
#define My_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(pID3D12GraphicsCommandList9, IBStripCutValue)\
    (pID3D12GraphicsCommandList9)->IASetIndexBufferStripCutValue(IBStripCutValue)

#define My_ID3D12StateObjectProperties1_QueryInterface(pID3D12StateObjectProperties1, riid, ppvObj)\
    (pID3D12StateObjectProperties1)->QueryInterface(riid, ppvObj)
#define My_ID3D12StateObjectProperties1_AddRef(pID3D12StateObjectProperties1)\
    (pID3D12StateObjectProperties1)->AddRef()
#define My_ID3D12StateObjectProperties1_Release(pID3D12StateObjectProperties1)\
    (pID3D12StateObjectProperties1)->Release()
#define My_ID3D12StateObjectProperties1_GetProgramIdentifier(pID3D12StateObjectProperties1, pProgramName)\
    (pID3D12StateObjectProperties1)->GetProgramIdentifier(pProgramName)

#define My_ID3D12WorkGraphProperties_QueryInterface(pID3D12WorkGraphProperties, riid, ppvObj)\
    (pID3D12WorkGraphProperties)->QueryInterface(riid, ppvObj)
#define My_ID3D12WorkGraphProperties_AddRef(pID3D12WorkGraphProperties)\
    (pID3D12WorkGraphProperties)->AddRef()
#define My_ID3D12WorkGraphProperties_Release(pID3D12WorkGraphProperties)\
    (pID3D12WorkGraphProperties)->Release()
#define My_ID3D12WorkGraphProperties_GetNumWorkGraphs(pID3D12WorkGraphProperties)\
    (pID3D12WorkGraphProperties)->GetNumWorkGraphs()
#define My_ID3D12WorkGraphProperties_GetProgramName(pID3D12WorkGraphProperties, WorkGraphIndex)\
    (pID3D12WorkGraphProperties)->GetProgramName(WorkGraphIndex)
#define My_ID3D12WorkGraphProperties_GetWorkGraphIndex(pID3D12WorkGraphProperties, pProgramName)\
    (pID3D12WorkGraphProperties)->GetWorkGraphIndex(pProgramName)
#define My_ID3D12WorkGraphProperties_GetNumNodes(pID3D12WorkGraphProperties, WorkGraphIndex)\
    (pID3D12WorkGraphProperties)->GetNumNodes(WorkGraphIndex)
#define My_ID3D12WorkGraphProperties_GetNodeID(pID3D12WorkGraphProperties, WorkGraphIndex, NodeIndex)\
    (pID3D12WorkGraphProperties)->GetNodeID(WorkGraphIndex, NodeIndex)
#define My_ID3D12WorkGraphProperties_GetNodeIndex(pID3D12WorkGraphProperties, WorkGraphIndex, NodeID)\
    (pID3D12WorkGraphProperties)->GetNodeIndex(WorkGraphIndex, NodeID)
#define My_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex(pID3D12WorkGraphProperties, WorkGraphIndex, NodeIndex)\
    (pID3D12WorkGraphProperties)->GetNodeLocalRootArgumentsTableIndex(WorkGraphIndex, NodeIndex)
#define My_ID3D12WorkGraphProperties_GetNumEntrypoints(pID3D12WorkGraphProperties, WorkGraphIndex)\
    (pID3D12WorkGraphProperties)->GetNumEntrypoints(WorkGraphIndex)
#define My_ID3D12WorkGraphProperties_GetEntrypointID(pID3D12WorkGraphProperties, WorkGraphIndex, EntrypointIndex)\
    (pID3D12WorkGraphProperties)->GetEntrypointID(WorkGraphIndex, EntrypointIndex)
#define My_ID3D12WorkGraphProperties_GetEntrypointIndex(pID3D12WorkGraphProperties, WorkGraphIndex, NodeID)\
    (pID3D12WorkGraphProperties)->GetEntrypointIndex(WorkGraphIndex, NodeID)
#define My_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes(pID3D12WorkGraphProperties, WorkGraphIndex, EntrypointIndex)\
    (pID3D12WorkGraphProperties)->GetEntrypointRecordSizeInBytes(WorkGraphIndex, EntrypointIndex)
#define My_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements(pID3D12WorkGraphProperties, WorkGraphIndex, pWorkGraphMemoryRequirements)\
    (pID3D12WorkGraphProperties)->GetWorkGraphMemoryRequirements(WorkGraphIndex, pWorkGraphMemoryRequirements)

#define My_ID3D12Device12_QueryInterface(pID3D12Device12, riid, ppvObj)\
    (pID3D12Device12)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device12_AddRef(pID3D12Device12)\
    (pID3D12Device12)->AddRef()
#define My_ID3D12Device12_Release(pID3D12Device12)\
    (pID3D12Device12)->Release()
#define My_ID3D12Device12_GetResourceAllocationInfo3(pID3D12Device12, visibleMask, numResourceDescs, pResourceDescs, pNumCastableFormats, ppCastableFormats, pResourceAllocationInfo1)\
    (pID3D12Device12)->GetResourceAllocationInfo3(visibleMask, numResourceDescs, pResourceDescs, pNumCastableFormats, ppCastableFormats, pResourceAllocationInfo1)

#define My_ID3D12Device13_QueryInterface(pID3D12Device13, riid, ppvObj)\
    (pID3D12Device13)->QueryInterface(riid, ppvObj)
#define My_ID3D12Device13_AddRef(pID3D12Device13)\
    (pID3D12Device13)->AddRef()
#define My_ID3D12Device13_Release(pID3D12Device13)\
    (pID3D12Device13)->Release()
#define My_ID3D12Device13_OpenExistingHeapFromAddress1(pID3D12Device13, pAddress, size, riid, ppvHeap)\
    (pID3D12Device13)->OpenExistingHeapFromAddress1(pAddress, size, riid, ppvHeap)

#define My_ID3D12DeviceExperimental_QueryInterface(pID3D12DeviceExperimental, riid, ppvObj)\
    (pID3D12DeviceExperimental)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceExperimental_AddRef(pID3D12DeviceExperimental)\
    (pID3D12DeviceExperimental)->AddRef()
#define My_ID3D12DeviceExperimental_Release(pID3D12DeviceExperimental)\
    (pID3D12DeviceExperimental)->Release()
#define My_ID3D12DeviceExperimental_CreateRootSignatureFromSubobjectInLibrary(pID3D12DeviceExperimental, nodeMask, pLibraryBlob, blobLengthInBytes, subobjectName, riid, ppvRootSignature)\
    (pID3D12DeviceExperimental)->CreateRootSignatureFromSubobjectInLibrary(nodeMask, pLibraryBlob, blobLengthInBytes, subobjectName, riid, ppvRootSignature)

#define My_ID3D12DeviceConfiguration1_QueryInterface(pID3D12DeviceConfiguration1, riid, ppvObj)\
    (pID3D12DeviceConfiguration1)->QueryInterface(riid, ppvObj)
#define My_ID3D12DeviceConfiguration1_AddRef(pID3D12DeviceConfiguration1)\
    (pID3D12DeviceConfiguration1)->AddRef()
#define My_ID3D12DeviceConfiguration1_Release(pID3D12DeviceConfiguration1)\
    (pID3D12DeviceConfiguration1)->Release()
#define My_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(pID3D12DeviceConfiguration1, pLibraryBlob, Size, RootSignatureSubobjectName, riid, ppvDeserializer)\
    (pID3D12DeviceConfiguration1)->CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(pLibraryBlob, Size, RootSignatureSubobjectName, riid, ppvDeserializer)

#define My_ID3D12GraphicsCommandListExperimental_QueryInterface(pID3D12GraphicsCommandListExperimental, riid, ppvObj)\
    (pID3D12GraphicsCommandListExperimental)->QueryInterface(riid, ppvObj)
#define My_ID3D12GraphicsCommandListExperimental_AddRef(pID3D12GraphicsCommandListExperimental)\
    (pID3D12GraphicsCommandListExperimental)->AddRef()
#define My_ID3D12GraphicsCommandListExperimental_Release(pID3D12GraphicsCommandListExperimental)\
    (pID3D12GraphicsCommandListExperimental)->Release()
#define My_ID3D12GraphicsCommandListExperimental_SetProgram(pID3D12GraphicsCommandListExperimental, pDesc)\
    (pID3D12GraphicsCommandListExperimental)->SetProgram(pDesc)
#define My_ID3D12GraphicsCommandListExperimental_DispatchGraph(pID3D12GraphicsCommandListExperimental, pDesc)\
    (pID3D12GraphicsCommandListExperimental)->DispatchGraph(pDesc)

#define My_CreateDXGIFactory(riid, ppFactory)\
    CreateDXGIFactory(riid, ppFactory)

#define My_IDXGIObject_QueryInterface(pIDXGIObject, riid, ppvObj)\
    (pIDXGIObject)->QueryInterface(riid, ppvObj)
#define My_IDXGIObject_AddRef(pIDXGIObject)\
    (pIDXGIObject)->AddRef()
#define My_IDXGIObject_Release(pIDXGIObject)\
    (pIDXGIObject)->Release()
#define My_IDXGIObject_SetPrivateData(pIDXGIObject, Name, DataSize, pData)\
    (pIDXGIObject)->SetPrivateData(Name, DataSize, pData)
#define My_IDXGIObject_SetPrivateDataInterface(pIDXGIObject, Name, pUnknown)\
    (pIDXGIObject)->SetPrivateDataInterface(Name, pUnknown)
#define My_IDXGIObject_GetPrivateData(pIDXGIObject, Name, pDataSize, pData)\
    (pIDXGIObject)->GetPrivateData(Name, pDataSize, pData)
#define My_IDXGIObject_GetParent(pIDXGIObject, riid, ppParent)\
    (pIDXGIObject)->GetParent(riid, ppParent)

#define My_IDXGIDeviceSubObject_QueryInterface(pIDXGIDeviceSubObject, riid, ppvObj)\
    (pIDXGIDeviceSubObject)->QueryInterface(riid, ppvObj)
#define My_IDXGIDeviceSubObject_AddRef(pIDXGIDeviceSubObject)\
    (pIDXGIDeviceSubObject)->AddRef()
#define My_IDXGIDeviceSubObject_Release(pIDXGIDeviceSubObject)\
    (pIDXGIDeviceSubObject)->Release()
#define My_IDXGIDeviceSubObject_GetDevice(pIDXGIDeviceSubObject, riid, ppDevice)\
    (pIDXGIDeviceSubObject)->GetDevice(riid, ppDevice)

#define My_IDXGIResource_QueryInterface(pIDXGIResource, riid, ppvObj)\
    (pIDXGIResource)->QueryInterface(riid, ppvObj)
#define My_IDXGIResource_AddRef(pIDXGIResource)\
    (pIDXGIResource)->AddRef()
#define My_IDXGIResource_Release(pIDXGIResource)\
    (pIDXGIResource)->Release()
#define My_IDXGIResource_GetSharedHandle(pIDXGIResource, pSharedHandle)\
    (pIDXGIResource)->GetSharedHandle(pSharedHandle)
#define My_IDXGIResource_GetUsage(pIDXGIResource, pUsage)\
    (pIDXGIResource)->GetUsage(pUsage)
#define My_IDXGIResource_SetEvictionPriority(pIDXGIResource, EvictionPriority)\
    (pIDXGIResource)->SetEvictionPriority(EvictionPriority)
#define My_IDXGIResource_GetEvictionPriority(pIDXGIResource, pEvictionPriority)\
    (pIDXGIResource)->GetEvictionPriority(pEvictionPriority)

#define My_IDXGISurface_QueryInterface(pIDXGISurface, riid, ppvObj)\
    (pIDXGISurface)->QueryInterface(riid, ppvObj)
#define My_IDXGISurface_AddRef(pIDXGISurface)\
    (pIDXGISurface)->AddRef()
#define My_IDXGISurface_Release(pIDXGISurface)\
    (pIDXGISurface)->Release()
#define My_IDXGISurface_GetDesc(pIDXGISurface, pDesc)\
    (pIDXGISurface)->GetDesc(pDesc)
#define My_IDXGISurface_Map(pIDXGISurface, pLockedRect, MapFlags)\
    (pIDXGISurface)->Map(pLockedRect, MapFlags)
#define My_IDXGISurface_Unmap(pIDXGISurface)\
    (pIDXGISurface)->Unmap()

#define My_IDXGIAdapter_QueryInterface(pIDXGIAdapter, riid, ppvObj)\
    (pIDXGIAdapter)->QueryInterface(riid, ppvObj)
#define My_IDXGIAdapter_AddRef(pIDXGIAdapter)\
    (pIDXGIAdapter)->AddRef()
#define My_IDXGIAdapter_Release(pIDXGIAdapter)\
    (pIDXGIAdapter)->Release()
#define My_IDXGIAdapter_EnumOutputs(pIDXGIAdapter, Output, ppOutput)\
    (pIDXGIAdapter)->EnumOutputs(Output, ppOutput)
#define My_IDXGIAdapter_GetDesc(pIDXGIAdapter, pDesc)\
    (pIDXGIAdapter)->GetDesc(pDesc)
#define My_IDXGIAdapter_CheckInterfaceSupport(pIDXGIAdapter, InterfaceName, pUMDVersion)\
    (pIDXGIAdapter)->CheckInterfaceSupport(InterfaceName, pUMDVersion)

#define My_IDXGIOutput_QueryInterface(pIDXGIOutput, riid, ppvObj)\
    (pIDXGIOutput)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutput_AddRef(pIDXGIOutput)\
    (pIDXGIOutput)->AddRef()
#define My_IDXGIOutput_Release(pIDXGIOutput)\
    (pIDXGIOutput)->Release()
#define My_IDXGIOutput_GetDesc(pIDXGIOutput, pDesc)\
    (pIDXGIOutput)->GetDesc(pDesc)
#define My_IDXGIOutput_GetDisplayModeList(pIDXGIOutput, EnumFormat, Flags, pNumModes, pDesc)\
    (pIDXGIOutput)->GetDisplayModeList(EnumFormat, Flags, pNumModes, pDesc)
#define My_IDXGIOutput_FindClosestMatchingMode(pIDXGIOutput, pModeToMatch, pClosestMatch, pConcernedDevice)\
    (pIDXGIOutput)->FindClosestMatchingMode(pModeToMatch, pClosestMatch, pConcernedDevice)
#define My_IDXGIOutput_WaitForVBlank(pIDXGIOutput)\
    (pIDXGIOutput)->WaitForVBlank()
#define My_IDXGIOutput_TakeOwnership(pIDXGIOutput, pDevice, Exclusive)\
    (pIDXGIOutput)->TakeOwnership(pDevice, Exclusive)
#define My_IDXGIOutput_ReleaseOwnership(pIDXGIOutput)\
    (pIDXGIOutput)->ReleaseOwnership()
#define My_IDXGIOutput_GetGammaControlCapabilities(pIDXGIOutput, pGammaCaps)\
    (pIDXGIOutput)->GetGammaControlCapabilities(pGammaCaps)
#define My_IDXGIOutput_SetGammaControl(pIDXGIOutput, pArray)\
    (pIDXGIOutput)->SetGammaControl(pArray)
#define My_IDXGIOutput_GetGammaControl(pIDXGIOutput, pArray)\
    (pIDXGIOutput)->GetGammaControl(pArray)
#define My_IDXGIOutput_SetDisplaySurface(pIDXGIOutput, pScanoutSurface)\
    (pIDXGIOutput)->SetDisplaySurface(pScanoutSurface)
#define My_IDXGIOutput_GetDisplaySurfaceData(pIDXGIOutput, pDestination)\
    (pIDXGIOutput)->GetDisplaySurfaceData(pDestination)
#define My_IDXGIOutput_GetFrameStatistics(pIDXGIOutput, pStats)\
    (pIDXGIOutput)->GetFrameStatistics(pStats)

#define My_IDXGISwapChain_QueryInterface(pIDXGISwapChain, riid, ppvObj)\
    (pIDXGISwapChain)->QueryInterface(riid, ppvObj)
#define My_IDXGISwapChain_AddRef(pIDXGISwapChain)\
    (pIDXGISwapChain)->AddRef()
#define My_IDXGISwapChain_Release(pIDXGISwapChain)\
    (pIDXGISwapChain)->Release()
#define My_IDXGISwapChain_Present(pIDXGISwapChain, SyncInterval, Flags)\
    (pIDXGISwapChain)->Present(SyncInterval, Flags)
#define My_IDXGISwapChain_GetBuffer(pIDXGISwapChain, Buffer, riid, ppSurface)\
    (pIDXGISwapChain)->GetBuffer(Buffer, riid, ppSurface)
#define My_IDXGISwapChain_SetFullscreenState(pIDXGISwapChain, Fullscreen, pTarget)\
    (pIDXGISwapChain)->SetFullscreenState(Fullscreen, pTarget)
#define My_IDXGISwapChain_GetFullscreenState(pIDXGISwapChain, pFullscreen, ppTarget)\
    (pIDXGISwapChain)->GetFullscreenState(pFullscreen, ppTarget)
#define My_IDXGISwapChain_GetDesc(pIDXGISwapChain, pDesc)\
    (pIDXGISwapChain)->GetDesc(pDesc)
#define My_IDXGISwapChain_ResizeBuffers(pIDXGISwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags)\
    (pIDXGISwapChain)->ResizeBuffers(BufferCount, Width, Height, NewFormat, SwapChainFlags)
#define My_IDXGISwapChain_ResizeTarget(pIDXGISwapChain, pNewTargetParameters)\
    (pIDXGISwapChain)->ResizeTarget(pNewTargetParameters)
#define My_IDXGISwapChain_GetContainingOutput(pIDXGISwapChain, ppOutput)\
    (pIDXGISwapChain)->GetContainingOutput(ppOutput)
#define My_IDXGISwapChain_GetFrameStatistics(pIDXGISwapChain, pStats)\
    (pIDXGISwapChain)->GetFrameStatistics(pStats)
#define My_IDXGISwapChain_GetLastPresentCount(pIDXGISwapChain, pLastPresentCount)\
    (pIDXGISwapChain)->GetLastPresentCount(pLastPresentCount)

#define My_IDXGIFactory_QueryInterface(pIDXGIFactory, riid, ppvObj)\
    (pIDXGIFactory)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory_AddRef(pIDXGIFactory)\
    (pIDXGIFactory)->AddRef()
#define My_IDXGIFactory_Release(pIDXGIFactory)\
    (pIDXGIFactory)->Release()
#define My_IDXGIFactory_EnumAdapters(pIDXGIFactory, Adapter, ppAdapter)\
    (pIDXGIFactory)->EnumAdapters(Adapter, ppAdapter)
#define My_IDXGIFactory_MakeWindowAssociation(pIDXGIFactory, WindowHandle, Flags)\
    (pIDXGIFactory)->MakeWindowAssociation(WindowHandle, Flags)
#define My_IDXGIFactory_GetWindowAssociation(pIDXGIFactory, pWindowHandle)\
    (pIDXGIFactory)->GetWindowAssociation(pWindowHandle)
#define My_IDXGIFactory_CreateSwapChain(pIDXGIFactory, pDevice, pDesc, ppSwapChain)\
    (pIDXGIFactory)->CreateSwapChain(pDevice, pDesc, ppSwapChain)
#define My_IDXGIFactory_CreateSoftwareAdapter(pIDXGIFactory, Module, ppAdapter)\
    (pIDXGIFactory)->CreateSoftwareAdapter(Module, ppAdapter)

#define My_IDXGIDevice_QueryInterface(pIDXGIDevice, riid, ppvObj)\
    (pIDXGIDevice)->QueryInterface(riid, ppvObj)
#define My_IDXGIDevice_AddRef(pIDXGIDevice)\
    (pIDXGIDevice)->AddRef()
#define My_IDXGIDevice_Release(pIDXGIDevice)\
    (pIDXGIDevice)->Release()
#define My_IDXGIDevice_GetAdapter(pIDXGIDevice, pAdapter)\
    (pIDXGIDevice)->GetAdapter(pAdapter)
#define My_IDXGIDevice_CreateSurface(pIDXGIDevice, pDesc, NumSurfaces, Usage, pSharedResource, ppSurface)\
    (pIDXGIDevice)->CreateSurface(pDesc, NumSurfaces, Usage, pSharedResource, ppSurface)
#define My_IDXGIDevice_QueryResourceResidency(pIDXGIDevice, ppResources, pResidencyStatus, NumResources)\
    (pIDXGIDevice)->QueryResourceResidency(ppResources, pResidencyStatus, NumResources)
#define My_IDXGIDevice_SetGPUThreadPriority(pIDXGIDevice, Priority)\
    (pIDXGIDevice)->SetGPUThreadPriority(Priority)
#define My_IDXGIDevice_GetGPUThreadPriority(pIDXGIDevice, pPriority)\
    (pIDXGIDevice)->GetGPUThreadPriority(pPriority)

#define My_CreateDXGIFactory1(riid, ppFactory)\
    CreateDXGIFactory1(riid, ppFactory)

#define My_IDXGIKeyedMutex_QueryInterface(pIDXGIKeyedMutex, riid, ppvObj)\
    (pIDXGIKeyedMutex)->QueryInterface(riid, ppvObj)
#define My_IDXGIKeyedMutex_AddRef(pIDXGIKeyedMutex)\
    (pIDXGIKeyedMutex)->AddRef()
#define My_IDXGIKeyedMutex_Release(pIDXGIKeyedMutex)\
    (pIDXGIKeyedMutex)->Release()
#define My_IDXGIKeyedMutex_AcquireSync(pIDXGIKeyedMutex, Key, dwMilliseconds)\
    (pIDXGIKeyedMutex)->AcquireSync(Key, dwMilliseconds)
#define My_IDXGIKeyedMutex_ReleaseSync(pIDXGIKeyedMutex, Key)\
    (pIDXGIKeyedMutex)->ReleaseSync(Key)

#define My_IDXGISurface1_QueryInterface(pIDXGISurface1, riid, ppvObj)\
    (pIDXGISurface1)->QueryInterface(riid, ppvObj)
#define My_IDXGISurface1_AddRef(pIDXGISurface1)\
    (pIDXGISurface1)->AddRef()
#define My_IDXGISurface1_Release(pIDXGISurface1)\
    (pIDXGISurface1)->Release()
#define My_IDXGISurface1_GetDC(pIDXGISurface1, Discard, phdc)\
    (pIDXGISurface1)->GetDC(Discard, phdc)
#define My_IDXGISurface1_ReleaseDC(pIDXGISurface1, pDirtyRect)\
    (pIDXGISurface1)->ReleaseDC(pDirtyRect)

#define My_IDXGIFactory1_QueryInterface(pIDXGIFactory1, riid, ppvObj)\
    (pIDXGIFactory1)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory1_AddRef(pIDXGIFactory1)\
    (pIDXGIFactory1)->AddRef()
#define My_IDXGIFactory1_Release(pIDXGIFactory1)\
    (pIDXGIFactory1)->Release()
#define My_IDXGIFactory1_EnumAdapters1(pIDXGIFactory1, Adapter, ppAdapter)\
    (pIDXGIFactory1)->EnumAdapters1(Adapter, ppAdapter)
#define My_IDXGIFactory1_IsCurrent(pIDXGIFactory1)\
    (pIDXGIFactory1)->IsCurrent()

#define My_IDXGIAdapter1_QueryInterface(pIDXGIAdapter1, riid, ppvObj)\
    (pIDXGIAdapter1)->QueryInterface(riid, ppvObj)
#define My_IDXGIAdapter1_AddRef(pIDXGIAdapter1)\
    (pIDXGIAdapter1)->AddRef()
#define My_IDXGIAdapter1_Release(pIDXGIAdapter1)\
    (pIDXGIAdapter1)->Release()
#define My_IDXGIAdapter1_GetDesc1(pIDXGIAdapter1, pDesc)\
    (pIDXGIAdapter1)->GetDesc1(pDesc)

#define My_IDXGIDevice1_QueryInterface(pIDXGIDevice1, riid, ppvObj)\
    (pIDXGIDevice1)->QueryInterface(riid, ppvObj)
#define My_IDXGIDevice1_AddRef(pIDXGIDevice1)\
    (pIDXGIDevice1)->AddRef()
#define My_IDXGIDevice1_Release(pIDXGIDevice1)\
    (pIDXGIDevice1)->Release()
#define My_IDXGIDevice1_SetMaximumFrameLatency(pIDXGIDevice1, MaxLatency)\
    (pIDXGIDevice1)->SetMaximumFrameLatency(MaxLatency)
#define My_IDXGIDevice1_GetMaximumFrameLatency(pIDXGIDevice1, pMaxLatency)\
    (pIDXGIDevice1)->GetMaximumFrameLatency(pMaxLatency)

#define My_IDXGIDisplayControl_QueryInterface(pIDXGIDisplayControl, riid, ppvObj)\
    (pIDXGIDisplayControl)->QueryInterface(riid, ppvObj)
#define My_IDXGIDisplayControl_AddRef(pIDXGIDisplayControl)\
    (pIDXGIDisplayControl)->AddRef()
#define My_IDXGIDisplayControl_Release(pIDXGIDisplayControl)\
    (pIDXGIDisplayControl)->Release()
#define My_IDXGIDisplayControl_IsStereoEnabled(pIDXGIDisplayControl)\
    (pIDXGIDisplayControl)->IsStereoEnabled()
#define My_IDXGIDisplayControl_SetStereoEnabled(pIDXGIDisplayControl, enabled)\
    (pIDXGIDisplayControl)->SetStereoEnabled(enabled)

#define My_IDXGIOutputDuplication_QueryInterface(pIDXGIOutputDuplication, riid, ppvObj)\
    (pIDXGIOutputDuplication)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutputDuplication_AddRef(pIDXGIOutputDuplication)\
    (pIDXGIOutputDuplication)->AddRef()
#define My_IDXGIOutputDuplication_Release(pIDXGIOutputDuplication)\
    (pIDXGIOutputDuplication)->Release()
#define My_IDXGIOutputDuplication_GetDesc(pIDXGIOutputDuplication, pDesc)\
    (pIDXGIOutputDuplication)->GetDesc(pDesc)
#define My_IDXGIOutputDuplication_AcquireNextFrame(pIDXGIOutputDuplication, TimeoutInMilliseconds, pFrameInfo, ppDesktopResource)\
    (pIDXGIOutputDuplication)->AcquireNextFrame(TimeoutInMilliseconds, pFrameInfo, ppDesktopResource)
#define My_IDXGIOutputDuplication_GetFrameDirtyRects(pIDXGIOutputDuplication, DirtyRectsBufferSize, pDirtyRectsBuffer, pDirtyRectsBufferSizeRequired)\
    (pIDXGIOutputDuplication)->GetFrameDirtyRects(DirtyRectsBufferSize, pDirtyRectsBuffer, pDirtyRectsBufferSizeRequired)
#define My_IDXGIOutputDuplication_GetFrameMoveRects(pIDXGIOutputDuplication, MoveRectsBufferSize, pMoveRectBuffer, pMoveRectsBufferSizeRequired)\
    (pIDXGIOutputDuplication)->GetFrameMoveRects(MoveRectsBufferSize, pMoveRectBuffer, pMoveRectsBufferSizeRequired)
#define My_IDXGIOutputDuplication_GetFramePointerShape(pIDXGIOutputDuplication, PointerShapeBufferSize, pPointerShapeBuffer, pPointerShapeBufferSizeRequired, pPointerShapeInfo)\
    (pIDXGIOutputDuplication)->GetFramePointerShape(PointerShapeBufferSize, pPointerShapeBuffer, pPointerShapeBufferSizeRequired, pPointerShapeInfo)
#define My_IDXGIOutputDuplication_MapDesktopSurface(pIDXGIOutputDuplication, pLockedRect)\
    (pIDXGIOutputDuplication)->MapDesktopSurface(pLockedRect)
#define My_IDXGIOutputDuplication_UnMapDesktopSurface(pIDXGIOutputDuplication)\
    (pIDXGIOutputDuplication)->UnMapDesktopSurface()
#define My_IDXGIOutputDuplication_ReleaseFrame(pIDXGIOutputDuplication)\
    (pIDXGIOutputDuplication)->ReleaseFrame()

#define My_IDXGISurface2_QueryInterface(pIDXGISurface2, riid, ppvObj)\
    (pIDXGISurface2)->QueryInterface(riid, ppvObj)
#define My_IDXGISurface2_AddRef(pIDXGISurface2)\
    (pIDXGISurface2)->AddRef()
#define My_IDXGISurface2_Release(pIDXGISurface2)\
    (pIDXGISurface2)->Release()
#define My_IDXGISurface2_GetResource(pIDXGISurface2, riid, ppParentResource, pSubresourceIndex)\
    (pIDXGISurface2)->GetResource(riid, ppParentResource, pSubresourceIndex)

#define My_IDXGIResource1_QueryInterface(pIDXGIResource1, riid, ppvObj)\
    (pIDXGIResource1)->QueryInterface(riid, ppvObj)
#define My_IDXGIResource1_AddRef(pIDXGIResource1)\
    (pIDXGIResource1)->AddRef()
#define My_IDXGIResource1_Release(pIDXGIResource1)\
    (pIDXGIResource1)->Release()
#define My_IDXGIResource1_CreateSubresourceSurface(pIDXGIResource1, index, ppSurface)\
    (pIDXGIResource1)->CreateSubresourceSurface(index, ppSurface)
#define My_IDXGIResource1_CreateSharedHandle(pIDXGIResource1, pAttributes, dwAccess, lpName, pHandle)\
    (pIDXGIResource1)->CreateSharedHandle(pAttributes, dwAccess, lpName, pHandle)

#define My_IDXGIDevice2_QueryInterface(pIDXGIDevice2, riid, ppvObj)\
    (pIDXGIDevice2)->QueryInterface(riid, ppvObj)
#define My_IDXGIDevice2_AddRef(pIDXGIDevice2)\
    (pIDXGIDevice2)->AddRef()
#define My_IDXGIDevice2_Release(pIDXGIDevice2)\
    (pIDXGIDevice2)->Release()
#define My_IDXGIDevice2_OfferResources(pIDXGIDevice2, NumResources, ppResources, Priority)\
    (pIDXGIDevice2)->OfferResources(NumResources, ppResources, Priority)
#define My_IDXGIDevice2_ReclaimResources(pIDXGIDevice2, NumResources, ppResources, pDiscarded)\
    (pIDXGIDevice2)->ReclaimResources(NumResources, ppResources, pDiscarded)
#define My_IDXGIDevice2_EnqueueSetEvent(pIDXGIDevice2, hEvent)\
    (pIDXGIDevice2)->EnqueueSetEvent(hEvent)

#define My_IDXGISwapChain1_QueryInterface(pIDXGISwapChain1, riid, ppvObj)\
    (pIDXGISwapChain1)->QueryInterface(riid, ppvObj)
#define My_IDXGISwapChain1_AddRef(pIDXGISwapChain1)\
    (pIDXGISwapChain1)->AddRef()
#define My_IDXGISwapChain1_Release(pIDXGISwapChain1)\
    (pIDXGISwapChain1)->Release()
#define My_IDXGISwapChain1_GetDesc1(pIDXGISwapChain1, pDesc)\
    (pIDXGISwapChain1)->GetDesc1(pDesc)
#define My_IDXGISwapChain1_GetFullscreenDesc(pIDXGISwapChain1, pDesc)\
    (pIDXGISwapChain1)->GetFullscreenDesc(pDesc)
#define My_IDXGISwapChain1_GetHwnd(pIDXGISwapChain1, pHwnd)\
    (pIDXGISwapChain1)->GetHwnd(pHwnd)
#define My_IDXGISwapChain1_GetCoreWindow(pIDXGISwapChain1, refiid, ppUnk)\
    (pIDXGISwapChain1)->GetCoreWindow(refiid, ppUnk)
#define My_IDXGISwapChain1_Present1(pIDXGISwapChain1, SyncInterval, PresentFlags, pPresentParameters)\
    (pIDXGISwapChain1)->Present1(SyncInterval, PresentFlags, pPresentParameters)
#define My_IDXGISwapChain1_IsTemporaryMonoSupported(pIDXGISwapChain1)\
    (pIDXGISwapChain1)->IsTemporaryMonoSupported()
#define My_IDXGISwapChain1_GetRestrictToOutput(pIDXGISwapChain1, ppRestrictToOutput)\
    (pIDXGISwapChain1)->GetRestrictToOutput(ppRestrictToOutput)
#define My_IDXGISwapChain1_SetBackgroundColor(pIDXGISwapChain1, pColor)\
    (pIDXGISwapChain1)->SetBackgroundColor(pColor)
#define My_IDXGISwapChain1_GetBackgroundColor(pIDXGISwapChain1, pColor)\
    (pIDXGISwapChain1)->GetBackgroundColor(pColor)
#define My_IDXGISwapChain1_SetRotation(pIDXGISwapChain1, Rotation)\
    (pIDXGISwapChain1)->SetRotation(Rotation)
#define My_IDXGISwapChain1_GetRotation(pIDXGISwapChain1, pRotation)\
    (pIDXGISwapChain1)->GetRotation(pRotation)

#define My_IDXGIFactory2_QueryInterface(pIDXGIFactory2, riid, ppvObj)\
    (pIDXGIFactory2)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory2_AddRef(pIDXGIFactory2)\
    (pIDXGIFactory2)->AddRef()
#define My_IDXGIFactory2_Release(pIDXGIFactory2)\
    (pIDXGIFactory2)->Release()
#define My_IDXGIFactory2_IsWindowedStereoEnabled(pIDXGIFactory2)\
    (pIDXGIFactory2)->IsWindowedStereoEnabled()
#define My_IDXGIFactory2_CreateSwapChainForHwnd(pIDXGIFactory2, pDevice, hWnd, pDesc, pFullscreenDesc, pRestrictToOutput, ppSwapChain)\
    (pIDXGIFactory2)->CreateSwapChainForHwnd(pDevice, hWnd, pDesc, pFullscreenDesc, pRestrictToOutput, ppSwapChain)
#define My_IDXGIFactory2_CreateSwapChainForCoreWindow(pIDXGIFactory2, pDevice, pWindow, pDesc, pRestrictToOutput, ppSwapChain)\
    (pIDXGIFactory2)->CreateSwapChainForCoreWindow(pDevice, pWindow, pDesc, pRestrictToOutput, ppSwapChain)
#define My_IDXGIFactory2_GetSharedResourceAdapterLuid(pIDXGIFactory2, hResource, pLuid)\
    (pIDXGIFactory2)->GetSharedResourceAdapterLuid(hResource, pLuid)
#define My_IDXGIFactory2_RegisterStereoStatusWindow(pIDXGIFactory2, WindowHandle, wMsg, pdwCookie)\
    (pIDXGIFactory2)->RegisterStereoStatusWindow(WindowHandle, wMsg, pdwCookie)
#define My_IDXGIFactory2_RegisterStereoStatusEvent(pIDXGIFactory2, hEvent, pdwCookie)\
    (pIDXGIFactory2)->RegisterStereoStatusEvent(hEvent, pdwCookie)
#define My_IDXGIFactory2_UnregisterStereoStatus(pIDXGIFactory2, dwCookie)\
    (pIDXGIFactory2)->UnregisterStereoStatus(dwCookie)
#define My_IDXGIFactory2_RegisterOcclusionStatusWindow(pIDXGIFactory2, WindowHandle, wMsg, pdwCookie)\
    (pIDXGIFactory2)->RegisterOcclusionStatusWindow(WindowHandle, wMsg, pdwCookie)
#define My_IDXGIFactory2_RegisterOcclusionStatusEvent(pIDXGIFactory2, hEvent, pdwCookie)\
    (pIDXGIFactory2)->RegisterOcclusionStatusEvent(hEvent, pdwCookie)
#define My_IDXGIFactory2_UnregisterOcclusionStatus(pIDXGIFactory2, dwCookie)\
    (pIDXGIFactory2)->UnregisterOcclusionStatus(dwCookie)
#define My_IDXGIFactory2_CreateSwapChainForComposition(pIDXGIFactory2, pDevice, pDesc, pRestrictToOutput, ppSwapChain)\
    (pIDXGIFactory2)->CreateSwapChainForComposition(pDevice, pDesc, pRestrictToOutput, ppSwapChain)

#define My_IDXGIAdapter2_QueryInterface(pIDXGIAdapter2, riid, ppvObj)\
    (pIDXGIAdapter2)->QueryInterface(riid, ppvObj)
#define My_IDXGIAdapter2_AddRef(pIDXGIAdapter2)\
    (pIDXGIAdapter2)->AddRef()
#define My_IDXGIAdapter2_Release(pIDXGIAdapter2)\
    (pIDXGIAdapter2)->Release()
#define My_IDXGIAdapter2_GetDesc2(pIDXGIAdapter2, pDesc)\
    (pIDXGIAdapter2)->GetDesc2(pDesc)

#define My_IDXGIOutput1_QueryInterface(pIDXGIOutput1, riid, ppvObj)\
    (pIDXGIOutput1)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutput1_AddRef(pIDXGIOutput1)\
    (pIDXGIOutput1)->AddRef()
#define My_IDXGIOutput1_Release(pIDXGIOutput1)\
    (pIDXGIOutput1)->Release()
#define My_IDXGIOutput1_GetDisplayModeList1(pIDXGIOutput1, EnumFormat, Flags, pNumModes, pDesc)\
    (pIDXGIOutput1)->GetDisplayModeList1(EnumFormat, Flags, pNumModes, pDesc)
#define My_IDXGIOutput1_FindClosestMatchingMode1(pIDXGIOutput1, pModeToMatch, pClosestMatch, pConcernedDevice)\
    (pIDXGIOutput1)->FindClosestMatchingMode1(pModeToMatch, pClosestMatch, pConcernedDevice)
#define My_IDXGIOutput1_GetDisplaySurfaceData1(pIDXGIOutput1, pDestination)\
    (pIDXGIOutput1)->GetDisplaySurfaceData1(pDestination)
#define My_IDXGIOutput1_DuplicateOutput(pIDXGIOutput1, pDevice, ppOutputDuplication)\
    (pIDXGIOutput1)->DuplicateOutput(pDevice, ppOutputDuplication)

#define My_CreateDXGIFactory2(Flags, riid, ppFactory)\
    CreateDXGIFactory2(Flags, riid, ppFactory)
#define My_DXGIGetDebugInterface1(Flags, riid, pDebug)\
    DXGIGetDebugInterface1(Flags, riid, pDebug)

#define My_IDXGIDevice3_QueryInterface(pIDXGIDevice3, riid, ppvObj)\
    (pIDXGIDevice3)->QueryInterface(riid, ppvObj)
#define My_IDXGIDevice3_AddRef(pIDXGIDevice3)\
    (pIDXGIDevice3)->AddRef()
#define My_IDXGIDevice3_Release(pIDXGIDevice3)\
    (pIDXGIDevice3)->Release()
#define My_IDXGIDevice3_Trim(pIDXGIDevice3)\
    (pIDXGIDevice3)->Trim()

#define My_IDXGISwapChain2_QueryInterface(pIDXGISwapChain2, riid, ppvObj)\
    (pIDXGISwapChain2)->QueryInterface(riid, ppvObj)
#define My_IDXGISwapChain2_AddRef(pIDXGISwapChain2)\
    (pIDXGISwapChain2)->AddRef()
#define My_IDXGISwapChain2_Release(pIDXGISwapChain2)\
    (pIDXGISwapChain2)->Release()
#define My_IDXGISwapChain2_SetSourceSize(pIDXGISwapChain2, Width, Height)\
    (pIDXGISwapChain2)->SetSourceSize(Width, Height)
#define My_IDXGISwapChain2_GetSourceSize(pIDXGISwapChain2, pWidth, pHeight)\
    (pIDXGISwapChain2)->GetSourceSize(pWidth, pHeight)
#define My_IDXGISwapChain2_SetMaximumFrameLatency(pIDXGISwapChain2, MaxLatency)\
    (pIDXGISwapChain2)->SetMaximumFrameLatency(MaxLatency)
#define My_IDXGISwapChain2_GetMaximumFrameLatency(pIDXGISwapChain2, pMaxLatency)\
    (pIDXGISwapChain2)->GetMaximumFrameLatency(pMaxLatency)
#define My_IDXGISwapChain2_GetFrameLatencyWaitableObject(pIDXGISwapChain2)\
    (pIDXGISwapChain2)->GetFrameLatencyWaitableObject()
#define My_IDXGISwapChain2_SetMatrixTransform(pIDXGISwapChain2, pMatrix)\
    (pIDXGISwapChain2)->SetMatrixTransform(pMatrix)
#define My_IDXGISwapChain2_GetMatrixTransform(pIDXGISwapChain2, pMatrix)\
    (pIDXGISwapChain2)->GetMatrixTransform(pMatrix)

#define My_IDXGIOutput2_QueryInterface(pIDXGIOutput2, riid, ppvObj)\
    (pIDXGIOutput2)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutput2_AddRef(pIDXGIOutput2)\
    (pIDXGIOutput2)->AddRef()
#define My_IDXGIOutput2_Release(pIDXGIOutput2)\
    (pIDXGIOutput2)->Release()
#define My_IDXGIOutput2_SupportsOverlays(pIDXGIOutput2)\
    (pIDXGIOutput2)->SupportsOverlays()

#define My_IDXGIFactory3_QueryInterface(pIDXGIFactory3, riid, ppvObj)\
    (pIDXGIFactory3)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory3_AddRef(pIDXGIFactory3)\
    (pIDXGIFactory3)->AddRef()
#define My_IDXGIFactory3_Release(pIDXGIFactory3)\
    (pIDXGIFactory3)->Release()
#define My_IDXGIFactory3_GetCreationFlags(pIDXGIFactory3)\
    (pIDXGIFactory3)->GetCreationFlags()

#define My_IDXGIDecodeSwapChain_QueryInterface(pIDXGIDecodeSwapChain, riid, ppvObj)\
    (pIDXGIDecodeSwapChain)->QueryInterface(riid, ppvObj)
#define My_IDXGIDecodeSwapChain_AddRef(pIDXGIDecodeSwapChain)\
    (pIDXGIDecodeSwapChain)->AddRef()
#define My_IDXGIDecodeSwapChain_Release(pIDXGIDecodeSwapChain)\
    (pIDXGIDecodeSwapChain)->Release()
#define My_IDXGIDecodeSwapChain_PresentBuffer(pIDXGIDecodeSwapChain, BufferToPresent, SyncInterval, Flags)\
    (pIDXGIDecodeSwapChain)->PresentBuffer(BufferToPresent, SyncInterval, Flags)
#define My_IDXGIDecodeSwapChain_SetSourceRect(pIDXGIDecodeSwapChain, pRect)\
    (pIDXGIDecodeSwapChain)->SetSourceRect(pRect)
#define My_IDXGIDecodeSwapChain_SetTargetRect(pIDXGIDecodeSwapChain, pRect)\
    (pIDXGIDecodeSwapChain)->SetTargetRect(pRect)
#define My_IDXGIDecodeSwapChain_SetDestSize(pIDXGIDecodeSwapChain, Width, Height)\
    (pIDXGIDecodeSwapChain)->SetDestSize(Width, Height)
#define My_IDXGIDecodeSwapChain_GetSourceRect(pIDXGIDecodeSwapChain, pRect)\
    (pIDXGIDecodeSwapChain)->GetSourceRect(pRect)
#define My_IDXGIDecodeSwapChain_GetTargetRect(pIDXGIDecodeSwapChain, pRect)\
    (pIDXGIDecodeSwapChain)->GetTargetRect(pRect)
#define My_IDXGIDecodeSwapChain_GetDestSize(pIDXGIDecodeSwapChain, pWidth, pHeight)\
    (pIDXGIDecodeSwapChain)->GetDestSize(pWidth, pHeight)
#define My_IDXGIDecodeSwapChain_SetColorSpace(pIDXGIDecodeSwapChain, ColorSpace)\
    (pIDXGIDecodeSwapChain)->SetColorSpace(ColorSpace)
#define My_IDXGIDecodeSwapChain_GetColorSpace(pIDXGIDecodeSwapChain)\
    (pIDXGIDecodeSwapChain)->GetColorSpace()

#define My_IDXGIFactoryMedia_QueryInterface(pIDXGIFactoryMedia, riid, ppvObj)\
    (pIDXGIFactoryMedia)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactoryMedia_AddRef(pIDXGIFactoryMedia)\
    (pIDXGIFactoryMedia)->AddRef()
#define My_IDXGIFactoryMedia_Release(pIDXGIFactoryMedia)\
    (pIDXGIFactoryMedia)->Release()
#define My_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(pIDXGIFactoryMedia, pDevice, hSurface, pDesc, pRestrictToOutput, ppSwapChain)\
    (pIDXGIFactoryMedia)->CreateSwapChainForCompositionSurfaceHandle(pDevice, hSurface, pDesc, pRestrictToOutput, ppSwapChain)
#define My_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(pIDXGIFactoryMedia, pDevice, hSurface, pDesc, pYuvDecodeBuffers, pRestrictToOutput, ppSwapChain)\
    (pIDXGIFactoryMedia)->CreateDecodeSwapChainForCompositionSurfaceHandle(pDevice, hSurface, pDesc, pYuvDecodeBuffers, pRestrictToOutput, ppSwapChain)

#define My_IDXGISwapChainMedia_QueryInterface(pIDXGISwapChainMedia, riid, ppvObj)\
    (pIDXGISwapChainMedia)->QueryInterface(riid, ppvObj)
#define My_IDXGISwapChainMedia_AddRef(pIDXGISwapChainMedia)\
    (pIDXGISwapChainMedia)->AddRef()
#define My_IDXGISwapChainMedia_Release(pIDXGISwapChainMedia)\
    (pIDXGISwapChainMedia)->Release()
#define My_IDXGISwapChainMedia_GetFrameStatisticsMedia(pIDXGISwapChainMedia, pStats)\
    (pIDXGISwapChainMedia)->GetFrameStatisticsMedia(pStats)
#define My_IDXGISwapChainMedia_SetPresentDuration(pIDXGISwapChainMedia, Duration)\
    (pIDXGISwapChainMedia)->SetPresentDuration(Duration)
#define My_IDXGISwapChainMedia_CheckPresentDurationSupport(pIDXGISwapChainMedia, DesiredPresentDuration, pClosestSmallerPresentDuration, pClosestLargerPresentDuration)\
    (pIDXGISwapChainMedia)->CheckPresentDurationSupport(DesiredPresentDuration, pClosestSmallerPresentDuration, pClosestLargerPresentDuration)

#define My_IDXGIOutput3_QueryInterface(pIDXGIOutput3, riid, ppvObj)\
    (pIDXGIOutput3)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutput3_AddRef(pIDXGIOutput3)\
    (pIDXGIOutput3)->AddRef()
#define My_IDXGIOutput3_Release(pIDXGIOutput3)\
    (pIDXGIOutput3)->Release()
#define My_IDXGIOutput3_CheckOverlaySupport(pIDXGIOutput3, EnumFormat, pConcernedDevice, pFlags)\
    (pIDXGIOutput3)->CheckOverlaySupport(EnumFormat, pConcernedDevice, pFlags)

#define My_IDXGISwapChain3_QueryInterface(pIDXGISwapChain3, riid, ppvObj)\
    (pIDXGISwapChain3)->QueryInterface(riid, ppvObj)
#define My_IDXGISwapChain3_AddRef(pIDXGISwapChain3)\
    (pIDXGISwapChain3)->AddRef()
#define My_IDXGISwapChain3_Release(pIDXGISwapChain3)\
    (pIDXGISwapChain3)->Release()
#define My_IDXGISwapChain3_GetCurrentBackBufferIndex(pIDXGISwapChain3)\
    (pIDXGISwapChain3)->GetCurrentBackBufferIndex()
#define My_IDXGISwapChain3_CheckColorSpaceSupport(pIDXGISwapChain3, ColorSpace, pColorSpaceSupport)\
    (pIDXGISwapChain3)->CheckColorSpaceSupport(ColorSpace, pColorSpaceSupport)
#define My_IDXGISwapChain3_SetColorSpace1(pIDXGISwapChain3, ColorSpace)\
    (pIDXGISwapChain3)->SetColorSpace1(ColorSpace)
#define My_IDXGISwapChain3_ResizeBuffers1(pIDXGISwapChain3, BufferCount, Width, Height, Format, SwapChainFlags, pCreationNodeMask, ppPresentQueue)\
    (pIDXGISwapChain3)->ResizeBuffers1(BufferCount, Width, Height, Format, SwapChainFlags, pCreationNodeMask, ppPresentQueue)

#define My_IDXGIOutput4_QueryInterface(pIDXGIOutput4, riid, ppvObj)\
    (pIDXGIOutput4)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutput4_AddRef(pIDXGIOutput4)\
    (pIDXGIOutput4)->AddRef()
#define My_IDXGIOutput4_Release(pIDXGIOutput4)\
    (pIDXGIOutput4)->Release()
#define My_IDXGIOutput4_CheckOverlayColorSpaceSupport(pIDXGIOutput4, Format, ColorSpace, pConcernedDevice, pFlags)\
    (pIDXGIOutput4)->CheckOverlayColorSpaceSupport(Format, ColorSpace, pConcernedDevice, pFlags)

#define My_IDXGIFactory4_QueryInterface(pIDXGIFactory4, riid, ppvObj)\
    (pIDXGIFactory4)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory4_AddRef(pIDXGIFactory4)\
    (pIDXGIFactory4)->AddRef()
#define My_IDXGIFactory4_Release(pIDXGIFactory4)\
    (pIDXGIFactory4)->Release()
#define My_IDXGIFactory4_EnumAdapterByLuid(pIDXGIFactory4, AdapterLuid, riid, ppvAdapter)\
    (pIDXGIFactory4)->EnumAdapterByLuid(AdapterLuid, riid, ppvAdapter)
#define My_IDXGIFactory4_EnumWarpAdapter(pIDXGIFactory4, riid, ppvAdapter)\
    (pIDXGIFactory4)->EnumWarpAdapter(riid, ppvAdapter)

#define My_IDXGIAdapter3_QueryInterface(pIDXGIAdapter3, riid, ppvObj)\
    (pIDXGIAdapter3)->QueryInterface(riid, ppvObj)
#define My_IDXGIAdapter3_AddRef(pIDXGIAdapter3)\
    (pIDXGIAdapter3)->AddRef()
#define My_IDXGIAdapter3_Release(pIDXGIAdapter3)\
    (pIDXGIAdapter3)->Release()
#define My_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(pIDXGIAdapter3, hEvent, pdwCookie)\
    (pIDXGIAdapter3)->RegisterHardwareContentProtectionTeardownStatusEvent(hEvent, pdwCookie)
#define My_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(pIDXGIAdapter3, dwCookie)\
    (pIDXGIAdapter3)->UnregisterHardwareContentProtectionTeardownStatus(dwCookie)
#define My_IDXGIAdapter3_QueryVideoMemoryInfo(pIDXGIAdapter3, NodeIndex, MemorySegmentGroup, pVideoMemoryInfo)\
    (pIDXGIAdapter3)->QueryVideoMemoryInfo(NodeIndex, MemorySegmentGroup, pVideoMemoryInfo)
#define My_IDXGIAdapter3_SetVideoMemoryReservation(pIDXGIAdapter3, NodeIndex, MemorySegmentGroup, Reservation)\
    (pIDXGIAdapter3)->SetVideoMemoryReservation(NodeIndex, MemorySegmentGroup, Reservation)
#define My_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(pIDXGIAdapter3, hEvent, pdwCookie)\
    (pIDXGIAdapter3)->RegisterVideoMemoryBudgetChangeNotificationEvent(hEvent, pdwCookie)
#define My_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(pIDXGIAdapter3, dwCookie)\
    (pIDXGIAdapter3)->UnregisterVideoMemoryBudgetChangeNotification(dwCookie)

#define My_IDXGIOutput5_QueryInterface(pIDXGIOutput5, riid, ppvObj)\
    (pIDXGIOutput5)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutput5_AddRef(pIDXGIOutput5)\
    (pIDXGIOutput5)->AddRef()
#define My_IDXGIOutput5_Release(pIDXGIOutput5)\
    (pIDXGIOutput5)->Release()
#define My_IDXGIOutput5_DuplicateOutput1(pIDXGIOutput5, pDevice, Flags, SupportedFormatsCount, pSupportedFormats, ppOutputDuplication)\
    (pIDXGIOutput5)->DuplicateOutput1(pDevice, Flags, SupportedFormatsCount, pSupportedFormats, ppOutputDuplication)

#define My_IDXGISwapChain4_QueryInterface(pIDXGISwapChain4, riid, ppvObj)\
    (pIDXGISwapChain4)->QueryInterface(riid, ppvObj)
#define My_IDXGISwapChain4_AddRef(pIDXGISwapChain4)\
    (pIDXGISwapChain4)->AddRef()
#define My_IDXGISwapChain4_Release(pIDXGISwapChain4)\
    (pIDXGISwapChain4)->Release()
#define My_IDXGISwapChain4_SetHDRMetaData(pIDXGISwapChain4, Type, Size, pMetaData)\
    (pIDXGISwapChain4)->SetHDRMetaData(Type, Size, pMetaData)

#define My_IDXGIDevice4_QueryInterface(pIDXGIDevice4, riid, ppvObj)\
    (pIDXGIDevice4)->QueryInterface(riid, ppvObj)
#define My_IDXGIDevice4_AddRef(pIDXGIDevice4)\
    (pIDXGIDevice4)->AddRef()
#define My_IDXGIDevice4_Release(pIDXGIDevice4)\
    (pIDXGIDevice4)->Release()
#define My_IDXGIDevice4_OfferResources1(pIDXGIDevice4, NumResources, ppResources, Priority, Flags)\
    (pIDXGIDevice4)->OfferResources1(NumResources, ppResources, Priority, Flags)
#define My_IDXGIDevice4_ReclaimResources1(pIDXGIDevice4, NumResources, ppResources, pResults)\
    (pIDXGIDevice4)->ReclaimResources1(NumResources, ppResources, pResults)

#define My_IDXGIFactory5_QueryInterface(pIDXGIFactory5, riid, ppvObj)\
    (pIDXGIFactory5)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory5_AddRef(pIDXGIFactory5)\
    (pIDXGIFactory5)->AddRef()
#define My_IDXGIFactory5_Release(pIDXGIFactory5)\
    (pIDXGIFactory5)->Release()
#define My_IDXGIFactory5_CheckFeatureSupport(pIDXGIFactory5, Feature, pFeatureSupportData, FeatureSupportDataSize)\
    (pIDXGIFactory5)->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize)

#define My_IDXGIAdapter4_QueryInterface(pIDXGIAdapter4, riid, ppvObj)\
    (pIDXGIAdapter4)->QueryInterface(riid, ppvObj)
#define My_IDXGIAdapter4_AddRef(pIDXGIAdapter4)\
    (pIDXGIAdapter4)->AddRef()
#define My_IDXGIAdapter4_Release(pIDXGIAdapter4)\
    (pIDXGIAdapter4)->Release()
#define My_IDXGIAdapter4_GetDesc3(pIDXGIAdapter4, pDesc)\
    (pIDXGIAdapter4)->GetDesc3(pDesc)

#define My_IDXGIOutput6_QueryInterface(pIDXGIOutput6, riid, ppvObj)\
    (pIDXGIOutput6)->QueryInterface(riid, ppvObj)
#define My_IDXGIOutput6_AddRef(pIDXGIOutput6)\
    (pIDXGIOutput6)->AddRef()
#define My_IDXGIOutput6_Release(pIDXGIOutput6)\
    (pIDXGIOutput6)->Release()
#define My_IDXGIOutput6_GetDesc1(pIDXGIOutput6, pDesc)\
    (pIDXGIOutput6)->GetDesc1(pDesc)
#define My_IDXGIOutput6_CheckHardwareCompositionSupport(pIDXGIOutput6, pFlags)\
    (pIDXGIOutput6)->CheckHardwareCompositionSupport(pFlags)

#define My_DXGIDeclareAdapterRemovalSupport()\
    DXGIDeclareAdapterRemovalSupport()

#define My_IDXGIFactory6_QueryInterface(pIDXGIFactory6, riid, ppvObj)\
    (pIDXGIFactory6)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory6_AddRef(pIDXGIFactory6)\
    (pIDXGIFactory6)->AddRef()
#define My_IDXGIFactory6_Release(pIDXGIFactory6)\
    (pIDXGIFactory6)->Release()
#define My_IDXGIFactory6_EnumAdapterByGpuPreference(pIDXGIFactory6, Adapter, GpuPreference, riid, ppvAdapter)\
    (pIDXGIFactory6)->EnumAdapterByGpuPreference(Adapter, GpuPreference, riid, ppvAdapter)

#define My_IDXGIFactory7_QueryInterface(pIDXGIFactory7, riid, ppvObj)\
    (pIDXGIFactory7)->QueryInterface(riid, ppvObj)
#define My_IDXGIFactory7_AddRef(pIDXGIFactory7)\
    (pIDXGIFactory7)->AddRef()
#define My_IDXGIFactory7_Release(pIDXGIFactory7)\
    (pIDXGIFactory7)->Release()
#define My_IDXGIFactory7_RegisterAdaptersChangedEvent(pIDXGIFactory7, hEvent, pdwCookie)\
    (pIDXGIFactory7)->RegisterAdaptersChangedEvent(hEvent, pdwCookie)
#define My_IDXGIFactory7_UnregisterAdaptersChangedEvent(pIDXGIFactory7, dwCookie)\
    (pIDXGIFactory7)->UnregisterAdaptersChangedEvent(dwCookie)

#define My_DXGIDisableVBlankVirtualization()\
    DXGIDisableVBlankVirtualization()


#define My_D3DPERF_BeginEvent(col, wszName)\
    D3DPERF_BeginEvent(col, wszName)
#define My_D3DPERF_EndEvent()\
    D3DPERF_EndEvent()
#define My_D3DPERF_SetMarker(col, wszName)\
    D3DPERF_SetMarker(col, wszName)
#define My_D3DPERF_SetRegion(col, wszName)\
    D3DPERF_SetRegion(col, wszName)

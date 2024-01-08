#pragma once

#include <cstdint>
#include <vector>
#include <windows.h>

#include <d3d11.h>

#include "ReadOnlyDatabase.h"

struct IDXGIAdapter;
struct IDXGISwapChain;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct DXGI_SWAP_CHAIN_DESC;
enum D3D_DRIVER_TYPE;
enum D3D_FEATURE_LEVEL;

HRESULT D3D11Replay_D3D11CreateDeviceAndSwapChain(
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
    ID3D11DeviceContext** ppImmediateContext);

//-----------------------------------------------------------------------------
// Helpers
//-----------------------------------------------------------------------------
void NvNameHelperSetObjectName(ID3D11Device* pObj, const char* pName);
void NvNameHelperSetObjectName(ID3D11DeviceChild* pObj, const char* pName);
void NvNameHelperSetObjectName(ID3D11VideoDevice* pObj, const char* pName);
void NvNameHelperSetObjectName(IDXGIObject* pObj, const char* pName);
void NvNameHelperSetObjectName(IUnknown* pObj, const char* pName);

D3D11_SUBRESOURCE_DATA* InitializeSubresourceDataD3D11(int resourceId, std::vector<uint8_t>& retvalData, Serialization::BlobProxy<uint8_t*>& dataProxy);

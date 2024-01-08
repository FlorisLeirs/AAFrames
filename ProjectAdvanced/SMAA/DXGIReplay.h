#pragma once

#include <cstdint>
#include <dxgi1_6.h>
#include <string>
#include <utility>
#include <vector>
#include <windows.h>

using DXGIReplay_MemoryStatProviderFcn = uint64_t (*)();
using DXGIReplay_MemoryStatProvider = std::pair<std::string, DXGIReplay_MemoryStatProviderFcn>;
using DXGIReplay_RegisterSwapchainFcn = void (*)(UINT numBuffers);
extern DXGIReplay_RegisterSwapchainFcn g_pRegisterSwapchainFcn;

void DXGIReplay_RegisterMemoryStatProviders(IDXGIAdapter3& adapter, std::vector<DXGIReplay_MemoryStatProvider> additionalProviders);
HRESULT DXGIReplay_SetFullscreenState(IDXGISwapChain* pSwapChain, BOOL Fullscreen, IDXGIOutput* pTarget);
HRESULT DXGIReplay_CreateSwapChain(
    IDXGIFactory* pFactory,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain);
HRESULT DXGIReplay_CreateSwapChainForHwnd(IDXGIFactory2* pFactory,
    IUnknown* pDevice,
    HWND hWnd,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);
HRESULT DXGIReplay_EnumAdapters(uint32_t adapterIndex, IDXGIFactory* pFactory, IDXGIAdapter** pAdapterInterface);
HRESULT DXGIReplay_EnumAdapters1(uint32_t adapterIndex, IDXGIFactory1* pFactory1, IDXGIAdapter1** pAdapterInterface);
HRESULT DXGIReplay_EnumAdapterByLuid(LUID adapterLuid, REFIID riid, IDXGIFactory4* pFactory4, void** pAdapterInterface);
HRESULT DXGIReplay_EnumAdapterByGpuPreference(uint32_t adapterIndex, DXGI_GPU_PREFERENCE GpuPreference, REFIID riid, IDXGIFactory6* pFactory6, void** pAdapterInterface);

void DXGIReplay_CheckPresentResult(HRESULT result, IDXGISwapChain* pSwapChain, const char* file, int line);
#define NV_CHECK_PRESENT_RESULT(_result, _pSwapChain) DXGIReplay_CheckPresentResult(_result, _pSwapChain, __FILE__, __LINE__)

void DXGIReplay_CaptureScreenShot(HWND hwnd, std::string filename = "");

namespace DxgiFormats {

static std::pair<int, int> GetMultiPixelBlockSize(DXGI_FORMAT fmt)
{
    std::pair<int, int> result = { 1, 1 };
    switch (fmt)
    {
    case DXGI_FORMAT_R1_UNORM:
        result.first = 8;
        break;
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
        result.first = 2;
        break;
    case DXGI_FORMAT_BC1_TYPELESS:
    case DXGI_FORMAT_BC1_UNORM:
    case DXGI_FORMAT_BC1_UNORM_SRGB:
    case DXGI_FORMAT_BC2_TYPELESS:
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC2_UNORM_SRGB:
    case DXGI_FORMAT_BC3_TYPELESS:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC3_UNORM_SRGB:
    case DXGI_FORMAT_BC4_TYPELESS:
    case DXGI_FORMAT_BC4_UNORM:
    case DXGI_FORMAT_BC4_SNORM:
    case DXGI_FORMAT_BC5_TYPELESS:
    case DXGI_FORMAT_BC5_UNORM:
    case DXGI_FORMAT_BC5_SNORM:
    case DXGI_FORMAT_BC6H_SF16:
    case DXGI_FORMAT_BC6H_UF16:
    case DXGI_FORMAT_BC6H_TYPELESS:
    case DXGI_FORMAT_BC7_UNORM:
    case DXGI_FORMAT_BC7_UNORM_SRGB:
    case DXGI_FORMAT_BC7_TYPELESS:
        result.first = 4;
        result.second = 4;
        break;
    default:
        break;
    }
    return result;
}

static int GetStride(DXGI_FORMAT fmt)
{
    switch (fmt)
    {
    case DXGI_FORMAT_UNKNOWN:
        return 0;
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
    case DXGI_FORMAT_R32G32B32A32_UINT:
    case DXGI_FORMAT_R32G32B32A32_SINT:
        return 16;
    case DXGI_FORMAT_R32G32B32_TYPELESS:
    case DXGI_FORMAT_R32G32B32_FLOAT:
    case DXGI_FORMAT_R32G32B32_UINT:
    case DXGI_FORMAT_R32G32B32_SINT:
        return 12;
    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R16G16B16A16_UINT:
    case DXGI_FORMAT_R16G16B16A16_SNORM:
    case DXGI_FORMAT_R16G16B16A16_SINT:
    case DXGI_FORMAT_R32G32_TYPELESS:
    case DXGI_FORMAT_R32G32_FLOAT:
    case DXGI_FORMAT_R32G32_UINT:
    case DXGI_FORMAT_R32G32_SINT:
    case DXGI_FORMAT_R32G8X24_TYPELESS:
    case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
    case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
    case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
        return 8;
    case DXGI_FORMAT_R10G10B10A2_TYPELESS:
    case DXGI_FORMAT_R10G10B10A2_UNORM:
    case DXGI_FORMAT_R10G10B10A2_UINT:
    case DXGI_FORMAT_R11G11B10_FLOAT:
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
    case DXGI_FORMAT_R8G8B8A8_UINT:
    case DXGI_FORMAT_R8G8B8A8_SNORM:
    case DXGI_FORMAT_R8G8B8A8_SINT:
    case DXGI_FORMAT_R16G16_TYPELESS:
    case DXGI_FORMAT_R16G16_FLOAT:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R16G16_UINT:
    case DXGI_FORMAT_R16G16_SNORM:
    case DXGI_FORMAT_R16G16_SINT:
    case DXGI_FORMAT_R32_TYPELESS:
    case DXGI_FORMAT_D32_FLOAT:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_R32_UINT:
    case DXGI_FORMAT_R32_SINT:
    case DXGI_FORMAT_R24G8_TYPELESS:
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
    case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
    case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
    case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
    case DXGI_FORMAT_B8G8R8A8_UNORM:
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
    case DXGI_FORMAT_B8G8R8A8_TYPELESS:
    case DXGI_FORMAT_B8G8R8X8_UNORM:
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
    case DXGI_FORMAT_B8G8R8X8_TYPELESS:
        return 4;
    case DXGI_FORMAT_R8G8_TYPELESS:
    case DXGI_FORMAT_R8G8_UNORM:
    case DXGI_FORMAT_R8G8_UINT:
    case DXGI_FORMAT_R8G8_SNORM:
    case DXGI_FORMAT_R8G8_SINT:
    case DXGI_FORMAT_R16_TYPELESS:
    case DXGI_FORMAT_R16_FLOAT:
    case DXGI_FORMAT_D16_UNORM:
    case DXGI_FORMAT_R16_UNORM:
    case DXGI_FORMAT_R16_UINT:
    case DXGI_FORMAT_R16_SNORM:
    case DXGI_FORMAT_R16_SINT:
    case DXGI_FORMAT_B5G6R5_UNORM:
    case DXGI_FORMAT_B5G5R5A1_UNORM:

        return 2;
    case DXGI_FORMAT_R8_TYPELESS:
    case DXGI_FORMAT_R8_UNORM:
    case DXGI_FORMAT_R8_UINT:
    case DXGI_FORMAT_R8_SNORM:
    case DXGI_FORMAT_R8_SINT:
    case DXGI_FORMAT_A8_UNORM:
        return 1;
    case DXGI_FORMAT_R1_UNORM:
        return 1;
    case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
        return 4;
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
        // return the stride of the block.
        return 4;
    case DXGI_FORMAT_BC1_TYPELESS:
    case DXGI_FORMAT_BC1_UNORM:
    case DXGI_FORMAT_BC1_UNORM_SRGB:
        // return the stride of the block.
        return 8;
    case DXGI_FORMAT_BC2_TYPELESS:
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC2_UNORM_SRGB:
        // return the stride of the block.
        return 16;
    case DXGI_FORMAT_BC3_TYPELESS:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC3_UNORM_SRGB:
        // return the stride of the block.
        return 16;
    case DXGI_FORMAT_BC4_TYPELESS:
    case DXGI_FORMAT_BC4_UNORM:
    case DXGI_FORMAT_BC4_SNORM:
        // return the stride of the block.
        return 8;
    case DXGI_FORMAT_BC5_TYPELESS:
    case DXGI_FORMAT_BC5_UNORM:
    case DXGI_FORMAT_BC5_SNORM:
        // return the stride of the block.
        return 16;
    case DXGI_FORMAT_BC6H_SF16:
    case DXGI_FORMAT_BC6H_UF16:
    case DXGI_FORMAT_BC6H_TYPELESS:
        // return the stride of the block.
        return 16;
    case DXGI_FORMAT_BC7_UNORM:
    case DXGI_FORMAT_BC7_UNORM_SRGB:
    case DXGI_FORMAT_BC7_TYPELESS:
        // return the stride of the block.
        return 16;

        // DX11.1
        // 32 bits
    case DXGI_FORMAT_AYUV:
    case DXGI_FORMAT_420_OPAQUE:
    case DXGI_FORMAT_YUY2:
    case DXGI_FORMAT_NV11:
        return 4;

        // 16 bits
    case DXGI_FORMAT_B4G4R4A4_UNORM:
    case DXGI_FORMAT_Y410:
    case DXGI_FORMAT_Y416:
    case DXGI_FORMAT_NV12:
    case DXGI_FORMAT_P010:
    case DXGI_FORMAT_P016:
    case DXGI_FORMAT_Y210:
    case DXGI_FORMAT_Y216:
        return 2;

        // 8 bits
    case DXGI_FORMAT_AI44:
    case DXGI_FORMAT_IA44:
    case DXGI_FORMAT_A8P8:
    case DXGI_FORMAT_P8:
        return 1;

    case DXGI_FORMAT_P208:
    case DXGI_FORMAT_V208:
    case DXGI_FORMAT_V408:
        return 1;

    default:
        return 1;
    }
}

} //namespace DxgiFormats

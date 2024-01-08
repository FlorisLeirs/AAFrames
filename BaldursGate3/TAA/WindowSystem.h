//---------------------------------------------------------------------------
// File: WindowSystem.h
//
// Distributed as part of NVIDIA Tegra Graphics Debugger serialization output.
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------

#pragma once

#include "CommonReplay.h"
#include "DllCommon.h"
#include "Helpers.h"

#if defined(_WIN32)
#include <Windows.h>
#endif

#if defined(WINAPI_EGL)
#include <EGL/egl.h>
#include <EGL/eglext.h>
#endif

class WindowSystem
{
public:
    virtual ~WindowSystem()
    {
    }

    virtual void ProcessEvents()
    {
    }

    virtual bool ShouldShutdown()
    {
        return m_shutdown;
    }
    
    virtual void CreateDisplay() = 0;
    virtual void DestroyDisplay() = 0;

    virtual void SetCreatingFullscreen(bool fullscreen) = 0;
    virtual void GetScreenSize(int& width, int& height) = 0;
    virtual void CreateNativeWindow(void* data, int width, int height) = 0;
    virtual void DestroyAllWindows() = 0;
    virtual void DestroyWindow(void* winAddr) = 0;

    void CreateNativeWindow(int width, int height)
    {
        // Store the desired window size
        m_winWidth = width;
        m_winHeight = height;

        CreateNativeWindow(nullptr, width, height);
    }

    // Get address of native display variable (Display* / xcb_connection_t* / wl_display* / NativeDisplayType)
    virtual void* GetDisplayAddr() = 0;
    // Get address of latest native window variable (Window / xcb_window_t / wl_surface* / NativeWindowType)
    virtual void* GetWindowAddr() = 0;
    // Get address of device variable (WFDDevice)
    virtual void* GetDeviceAddr()
    {
        return nullptr;
    }

    // Return size of the latest native window
    int GetNativeWindowWidth() const
    {
        return m_winWidth;
    }
    int GetNativeWindowHeight() const
    {
        return m_winHeight;
    }

#if defined(WINAPI_EGL)
    // Get address of EGL display variable (NativeDisplayType)
    virtual void* GetEGLDisplayAddr()
    {
        return GetDisplayAddr();
    }

    // Get address of EGL window variable (NativeWindowType)
    virtual void* GetEGLWindowAddr()
    {
        return GetWindowAddr();
    }

    // Get address of native window variable that can be used for 'eglCreatePlatformWindowSurfaceEXT' (void*)
    virtual void* GetEGLWindowEXTAddr()
    {
        // Note: GetEGLWindowAddr() may be overridden, so this code cannot be changed to GetWindowAddr()
        return GetEGLWindowAddr();
    }

#ifdef EGL_KHR_stream
    virtual void ConnectConsumerToStream(EGLStreamKHR stream)
    {
    }
#endif
#endif

#if defined(WINAPI_GLX)
    // Add pixmap here in order to support glX pixmap drawable
    virtual void CreatePixmap(int width, int height) = 0;
    virtual void DestroyPixmap() = 0;

    // Get address of native pixmap variable
    virtual void* GetPixmapAddr() = 0;
#endif

protected:
    WindowSystem()
        : m_shutdown(false)
    {
    }

    void Shutdown()
    {
        m_shutdown = true;
    }
    
private:
    bool m_shutdown;

    // Size of the latest native window
    int m_winWidth = 0;
    int m_winHeight = 0;
};

NV_REPLAY_EXPORT WindowSystem& WindowSystemInstance();

#if defined(_WIN32)
typedef enum PROCESS_DPI_AWARENESS
{
    PROCESS_DPI_UNAWARE = 0,
    PROCESS_SYSTEM_DPI_AWARE = 1,
    PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;

NV_REPLAY_EXPORT BOOL RegisterReplayerWindowClass(HINSTANCE hInstance, UINT style);
NV_REPLAY_EXPORT HWND CreateReplayerWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, uint32_t x, uint32_t y, uint32_t Width, uint32_t Height, DWORD Style, DWORD ExtendedStyle, PROCESS_DPI_AWARENESS DpiAwareness);
NV_REPLAY_EXPORT HMONITOR GetReplayerMonitor();
#endif

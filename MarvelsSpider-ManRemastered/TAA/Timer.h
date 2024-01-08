//-------------------------------------------------------------------------------
// File: NvTimer.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//-------------------------------------------------------------------------------

#pragma once

#include "Application.h"
#include "Helpers.h"

#include <chrono>

//------------------------------------------------------------------------------
// NvAutoTimer
//------------------------------------------------------------------------------
class NvAutoTimer
{
public:
    NvAutoTimer(const char* pText)
        : m_pText(pText)
    {
        m_start = std::chrono::high_resolution_clock::now();
    }
    ~NvAutoTimer()
    {
        auto end = std::chrono::high_resolution_clock::now();
        const float ms = std::chrono::duration_cast<std::chrono::microseconds>(end - m_start).count() / 1000.f;
        NV_MESSAGE("[%s] %0.3f ms ", m_pText, ms);
    }

private:
    const char* const m_pText;
    std::chrono::high_resolution_clock::time_point m_start;
};

//------------------------------------------------------------------------------
// NV_TIMED_EXEC
//------------------------------------------------------------------------------
#define NV_TIMED_EXEC(TEXT, WAIT_FUNC)                                  \
    if (Application::VerboseOutput()) {                                 \
        NvAutoTimer NV_ANONYMOUS_VARIABLE(__autoTimer, __LINE__)(TEXT); \
        WAIT_FUNC();                                                    \
    } else {                                                            \
        WAIT_FUNC();                                                    \
    }

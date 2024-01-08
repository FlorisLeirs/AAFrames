//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2023.4.0.0
// 
// File: ReplayProcedures.h
// 
//-----------------------------------------------------------------------------

#pragma once


#include <stdint.h>

#if defined(NV_REPLAY_LIB_SHARED)
 #if defined(_WIN32)
  #if defined(GeneratedReplay_EXPORTS)
   #define NV_GENERATED_REPLAY_API __declspec(dllexport)
  #else
   #define NV_GENERATED_REPLAY_API __declspec(dllimport)
  #endif
 #else
  #define NV_GENERATED_REPLAY_API __attribute__((visibility("default")))
 #endif
#else
 #define NV_GENERATED_REPLAY_API
#endif

extern "C"
{
    NV_GENERATED_REPLAY_API void CreateAndSetupResources();
    NV_GENERATED_REPLAY_API void ReleaseResources();
    NV_GENERATED_REPLAY_API void RunFrame(uint64_t frameIndex);
}


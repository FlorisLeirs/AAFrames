//-----------------------------------------------------------------------------
// Generated with NVIDIA Nsight Graphics 2023.4.0.0
// 
// File: Helpers.h
// 
//-----------------------------------------------------------------------------

#pragma once

#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>
#include <sstream>

#include "ReadOnlyDatabase.h"
#include "ThreadPool.h"
#include "DllCommon.h"

//-----------------------------------------------------------------------------
// Common Resources
//-----------------------------------------------------------------------------
NV_REPLAY_EXPORT extern const char* ProcessName;
NV_REPLAY_EXPORT extern double array_of_0s[256];
NV_REPLAY_EXPORT extern const int g_ResourceInitFunctionCount;

const unsigned int NUM_REPLAYER_THREADS = 1;

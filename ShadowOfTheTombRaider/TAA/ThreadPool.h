//-------------------------------------------------------------------------------
// File: ThreadPool.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//-------------------------------------------------------------------------------

#pragma once

#include "DllCommon.h"

#include <cstdint>
#include <functional>
#include <future>

#if !defined(NV_REPLAY_ON_ORIGINAL_THREAD_IDS)

#define NV_THREAD_BEGIN(_ThreadId)
#define NV_THREAD_END(_ThreadId)
#define NV_THREAD_NON_BLOCKING_BEGIN(_ThreadId)
#define NV_THREAD_NON_BLOCKING_END(_ThreadId)

#else

#define NV_THREAD_BEGIN(_ThreadId) \
    NvExecuteOnThread(_ThreadId, NV_EXECUTE_ON_THREAD_FLAGS_NONE, std::move([=]{     \
    auto& dataScopeTracker = Serialization::DataScopeTracker::Instance(); \
    ((void)0);

#define NV_THREAD_END(_ThreadId) \
    }));

#define NV_THREAD_NON_BLOCKING_BEGIN(_ThreadId) \
    NvExecuteOnThread(_ThreadId, NV_EXECUTE_ON_THREAD_FLAGS_NON_BLOCKING, std::move([=]{     \
    auto& dataScopeTracker = Serialization::DataScopeTracker::Instance(); \
    ((void)0);

#define NV_THREAD_NON_BLOCKING_END(_ThreadId) \
    }));

#endif

enum NvExecuteOnThreadFlags
{
    NV_EXECUTE_ON_THREAD_FLAGS_NONE = 0x0,
    NV_EXECUTE_ON_THREAD_FLAGS_NON_BLOCKING = 0x1,
};

#if defined(NV_REPLAY_ON_ORIGINAL_THREAD_IDS)
//------------------------------------------------------------------------------
// Executes a function on a specific worker thread
//------------------------------------------------------------------------------
NV_REPLAY_EXPORT std::future<void> NvExecuteOnThread(uint32_t threadId, NvExecuteOnThreadFlags flags, std::function<void()>&& fn);
#endif

//------------------------------------------------------------------------------
// Executes a function on a thread pool
//------------------------------------------------------------------------------
NV_REPLAY_EXPORT std::future<void> NvExecuteOnThreadPool(std::function<void()>&& fn);

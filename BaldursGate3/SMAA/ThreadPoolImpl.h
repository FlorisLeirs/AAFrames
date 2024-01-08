//-------------------------------------------------------------------------------
// File: ThreadPoolImpl.h
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//-------------------------------------------------------------------------------
#pragma once

#include "ThreadPool.h"
#include <array>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

extern size_t g_threadPoolThreadCount;

//--------------------------------------------------------------------------------------
// ThreadPool
//--------------------------------------------------------------------------------------
class ThreadPool
{
public:
    ThreadPool()
        : m_shutdown(false)
        , m_vecWorkers()
        , m_nextWorkerId()
    {
    }

    ThreadPool(size_t threadCount)
        : m_shutdown(false)
        , m_vecWorkers(threadCount)
        , m_nextWorkerId()
    {
        for (auto& spWorker : m_vecWorkers)
        {
            spWorker = createWorker();
        }
    }

    ~ThreadPool()
    {
        m_shutdown = true;
        for (auto& pWorker : m_vecWorkers)
        {
            if (!pWorker)
            {
                continue;
            }

            pWorker->cv.notify_one();
            if (pWorker->thread.joinable())
            {
                pWorker->thread.join();
            }
        }
    }

    std::future<void> RunOnThread(uint32_t i, NvExecuteOnThreadFlags flags, std::function<void()>&& fn)
    {
        // JIT create worker
        if (i >= m_vecWorkers.size())
        {
            m_vecWorkers.resize(i + 1);
        }
        if (!m_vecWorkers[i])
        {
            m_vecWorkers[i] = createWorker();
        }

        auto& worker = *m_vecWorkers[i];

        // Finish the previous work for this thread, if needed
        while (worker.m_work)
        {
            std::this_thread::yield();
        }

        // Supply work
        std::future<void> future;
        {
            std::unique_lock<std::mutex> lock(worker.m_mutex);
            worker.m_promise = std::promise<void>();
            future = worker.m_promise.get_future();
            std::swap(worker.m_work, fn);
        }

        // Notify worker
        m_vecWorkers[i]->cv.notify_one();

        if (!(flags & NvExecuteOnThreadFlags::NV_EXECUTE_ON_THREAD_FLAGS_NON_BLOCKING))
        {
            // Spin while we wait for it to finish
            while (worker.m_work)
            {
                std::this_thread::yield();
            }
        }

        return future;
    }

    std::future<void> Run(std::function<void()>&& fn)
    {
        // Get the next idle worker thread
        for (;;)
        {
            if (!m_vecWorkers[m_nextWorkerId]->m_work)
            {
                break;
            }
            m_nextWorkerId = (m_nextWorkerId + 1) % g_threadPoolThreadCount;
        }
        auto& worker = *m_vecWorkers[m_nextWorkerId];
        m_nextWorkerId = (m_nextWorkerId + 1) % g_threadPoolThreadCount;

        // Supply work
        std::future<void> future;
        {
            std::unique_lock<std::mutex> lock(worker.m_mutex);
            worker.m_promise = std::promise<void>();
            future = worker.m_promise.get_future();
            std::swap(worker.m_work, fn);
        }

        // Notify worker
        worker.cv.notify_one();
        return future;
    }

private:
    struct PerWorker
    {
        PerWorker()
            : thread()
            , cv()
            , m_work()
            , m_mutex()
            , m_promise()
        {
        }

        std::thread thread;
        std::condition_variable cv;
        std::function<void()> m_work;
        std::mutex m_mutex;
        std::promise<void> m_promise;
    };

    std::unique_ptr<PerWorker> createWorker()
    {
        PerWorker* pWorker = new PerWorker;
        pWorker->thread = std::thread([=] {
            // Loop
            while (!m_shutdown)
            {

                // Wait for work
                std::unique_lock<std::mutex> lock(pWorker->m_mutex);
                pWorker->cv.wait(lock, [=] {
                    return pWorker->m_work || m_shutdown;
                });

                // Bail if told to shutdown
                if (m_shutdown)
                {
                    return;
                }

                // Consume work and notify main thread when done
                pWorker->m_work();
                pWorker->m_work = nullptr;
                pWorker->m_promise.set_value();
            }
        });

        return std::unique_ptr<PerWorker>(pWorker);
    }

    bool m_shutdown;
    std::vector<std::unique_ptr<PerWorker>> m_vecWorkers;
    size_t m_nextWorkerId;
};

//--------------------------------------------------------------------------------------
// NvHasMultithreadedReplay
//--------------------------------------------------------------------------------------
bool NvHasMultithreadedReplay();

#if defined(NV_REPLAY_ON_ORIGINAL_THREAD_IDS)
//--------------------------------------------------------------------------------------
// NvExecuteOnThread
//--------------------------------------------------------------------------------------
std::future<void> NvExecuteOnThread(uint32_t threadId, NvExecuteOnThreadFlags flags, std::function<void()>&& fn)
{
    // Run on the master thread thread if multi-threaded replay is disabled
    if (!NvHasMultithreadedReplay())
    {
        fn();
        return {};
    }

    // Otherwise pass on to thread pool
    static ThreadPool s_pool;
    return s_pool.RunOnThread(threadId, flags, std::move(fn));
}

#endif

//------------------------------------------------------------------------------
// Executes a function on a thread pool
//------------------------------------------------------------------------------
std::future<void> NvExecuteOnThreadPool(std::function<void()>&& fn)
{
    static ThreadPool s_pool(g_threadPoolThreadCount);
    return s_pool.Run(std::move(fn));
}
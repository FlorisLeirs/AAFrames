//--------------------------------------------------------------------------------------
// File: Threading.h
//
// Distributed as part of NVIDIA Nsight serialization output.
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "CommonReplay.h"
#include "Helpers.h"

#if defined(_WIN32)
#include <Windows.h>
#else // defined(WIN32)
#include <condition_variable>
#include <memory>
#include <mutex>
#endif // defined(_WIN32)

//--------------------------------------------------------------------------------------
// NV_EXEC - Wrapper macro for functions
// -------------------------------------------------------------------------------------
#define NV_EXEC(_Function) _Function

#if defined(_WIN32)

//--------------------------------------------------------------------------------------
// NV_SIGNAL_THREAD_AND_WAIT - Signal a waiting thread to begin execution and wait
// to be signaled
// -------------------------------------------------------------------------------------
#define NV_SIGNAL_THREAD_AND_WAIT(_ThreadId)   \
    SetEvent(threadSequenceEvents[_ThreadId]); \
    WaitForSingleObject(threadSequenceEvents[threadId], INFINITE)

//--------------------------------------------------------------------------------------
// NV_SIGNAL_THREAD - Signal a waiting thread to begin execution
// -------------------------------------------------------------------------------------
#define NV_SIGNAL_THREAD(_ThreadId) \
    SetEvent(threadSequenceEvents[_ThreadId])

//--------------------------------------------------------------------------------------
// NV_WAIT - Wait untils this thread is signaled
// -------------------------------------------------------------------------------------
#define NV_WAIT_FOR_SIGNAL() \
    WaitForSingleObject(threadSequenceEvents[threadId], INFINITE)

//--------------------------------------------------------------------------------------
// NV_SIGNAL_FRAME_COMPLETE - Signal that the frame traversal has been completed
// -------------------------------------------------------------------------------------
#define NV_SIGNAL_FRAME_COMPLETE()                          \
    for (unsigned int i = 0; i < NUM_REPLAYER_THREADS; ++i) \
    {                                                       \
        if (i != threadId)                                  \
        {                                                   \
            SetEvent(threadSequenceEvents[i]);              \
        }                                                   \
    }

#else // defined(WIN32)

//--------------------------------------------------------------------------------------
// NV_SIGNAL_THREAD_AND_WAIT - Signal a waiting thread to begin execution and wait
// to be signaled
// -------------------------------------------------------------------------------------
#define NV_SIGNAL_THREAD_AND_WAIT(_ThreadId)   \
    threadSequenceEvents[_ThreadId]->Signal(); \
    threadSequenceEvents[threadId]->Wait()

//--------------------------------------------------------------------------------------
// NV_SIGNAL_FRAME_COMPLETE - Signal that the frame traversal has been completed
// -------------------------------------------------------------------------------------
#define NV_SIGNAL_FRAME_COMPLETE()                          \
    for (unsigned int i = 0; i < NUM_REPLAYER_THREADS; ++i) \
    {                                                       \
        if (i != threadId)                                  \
        {                                                   \
            threadSequenceEvents[i]->Signal();              \
        }                                                   \
    }

#endif // defined(_WIN32)

//--------------------------------------------------------------------------------------
// Function pointer types
//--------------------------------------------------------------------------------------
using ThreadInitFunc = void (*)();
using ThreadReleaseFunc = void (*)();
using RunFrameFunc = void (*)();
using ResetFrameFunc = void (*)(bool);

#if defined(_WIN32)

//--------------------------------------------------------------------------------------
// ThreadRunner - Class and derived classes used to manage the running of threads
//--------------------------------------------------------------------------------------
class ThreadRunner
{
public:
    ThreadRunner(HANDLE sequenceEvent, HANDLE doneEvent, RunFrameFunc runFrameFunc);
    virtual ~ThreadRunner()
    {
    }
    virtual void Init()
    {
    }
    virtual void Release()
    {
    }
    void RunThread();

protected:
    void SignalMainThreadAndWait() const;

private:
    virtual void PreRunThread()
    {
    }
    virtual void PostRunThread()
    {
    }
    HANDLE m_sequenceEvent;
    HANDLE m_doneEvent;
    RunFrameFunc m_runFrameFunc;
};

class BasicThreadRunner : public ThreadRunner
{
public:
    BasicThreadRunner(HANDLE sequenceEvent, HANDLE doneEvent, RunFrameFunc runFrameFunc, ResetFrameFunc resetFrameFunc);

private:
    virtual void PostRunThread() override;
    ResetFrameFunc m_resetFrameFunc;
};

//--------------------------------------------------------------------------------------
// ThreadStart - The method each replayer thread begins running
//--------------------------------------------------------------------------------------
DWORD WINAPI ThreadStart(LPVOID lpParameter);

//--------------------------------------------------------------------------------------
// CreateThreadEvents - Create Windows events used to synchronize the threads
//--------------------------------------------------------------------------------------
bool CreateThreadEvents(unsigned int numThreads, HANDLE* events);

//--------------------------------------------------------------------------------------
// CreateReplayerThreads - Create and start the replayer threads
//--------------------------------------------------------------------------------------
bool CreateReplayerThreads(ThreadRunner** threadRunners, unsigned int numThreads, HANDLE* sequenceEvents, HANDLE* doneEvents, bool& exitThreads, bool& releaseThreads);

//--------------------------------------------------------------------------------------
// ReleaseReplayerThreads - Release all of the replayer threads
//--------------------------------------------------------------------------------------
void ReleaseReplayerThreads(unsigned int numThreads, HANDLE* sequenceEvents, HANDLE* doneEvents, bool& releaseThreads);

//--------------------------------------------------------------------------------------
// ExitReplayerThreads - Exit all of the replayer threads
//--------------------------------------------------------------------------------------
void ExitReplayerThreads(unsigned int numThreads, HANDLE* sequenceEvents, HANDLE* doneEvents, bool& exitThreads);

//--------------------------------------------------------------------------------------
// RunReplayerThreads - Tell each replayer thread to run a frame and wait for
// them to complete
//--------------------------------------------------------------------------------------
void RunReplayerThreads(unsigned int numThreads, unsigned int startThread, HANDLE* doneEvents, HANDLE* sequenceEvents);

#else // defined(WIN32)

//--------------------------------------------------------------------------------------
// AutoResetEvent - Class used as a synchronization event for replayer threads,
// automatically set to an unsignaled state after being waited on
//--------------------------------------------------------------------------------------
class AutoResetEvent
{
public:
    AutoResetEvent();
    void Signal();
    void Wait();

private:
    bool m_signaled;
    std::mutex m_mutex;
    std::condition_variable m_condtionVariable;
};

//--------------------------------------------------------------------------------------
// ThreadRunner - Class and derived classes used to manage the running of threads
//--------------------------------------------------------------------------------------
class ThreadRunner : public std::enable_shared_from_this<ThreadRunner>
{
public:
    using ThreadStartFunc = void (*)(unsigned int, std::shared_ptr<ThreadRunner>);

    ThreadRunner(unsigned int threadId, RunFrameFunc runFrameFunc);
    virtual void CreateThread(ThreadStartFunc threadStartFunc, unsigned int threadId);
    virtual void Init()
    {
    }
    virtual void Release()
    {
    }
    void RunThread();

protected:
    void SignalMainThreadAndWait() const;
    unsigned int GetThreadId() const;

private:
    virtual void PreRunThread()
    {
    }
    virtual void PostRunThread()
    {
    }
    unsigned int m_threadId;
    RunFrameFunc m_runFrameFunc;
};

class BasicThreadRunner : public ThreadRunner
{
public:
    BasicThreadRunner(unsigned int threadId, RunFrameFunc runFrameFunc, ResetFrameFunc resetFrameFunc);

private:
    virtual void PostRunThread() override;
    ResetFrameFunc m_resetFrameFunc;
};

//--------------------------------------------------------------------------------------
// ThreadRunnerArray
//--------------------------------------------------------------------------------------
using ThreadRunnerArray = std::array<std::shared_ptr<ThreadRunner>, NUM_REPLAYER_THREADS>;

//--------------------------------------------------------------------------------------
// CreateThreadEvents - Create Windows events used to synchronize the threads
//--------------------------------------------------------------------------------------
bool CreateThreadEvents(EventsArray& events);

//--------------------------------------------------------------------------------------
// CreateReplayerThreads - Create and start the replayer threads
//--------------------------------------------------------------------------------------
bool CreateReplayerThreads(ThreadRunnerArray& threadRunners);

//--------------------------------------------------------------------------------------
// ReleaseReplayerThreads - Release all of the replayer threads
//--------------------------------------------------------------------------------------
void ReleaseReplayerThreads(unsigned int numThreads);

//--------------------------------------------------------------------------------------
// ExitReplayerThreads - Exit all of the replayer threads
//--------------------------------------------------------------------------------------
void ExitReplayerThreads(unsigned int numThreads);

//--------------------------------------------------------------------------------------
// RunReplayerThreads - Tell each replayer thread to run a frame and wait for
// them to complete
//--------------------------------------------------------------------------------------
void RunReplayerThreads();

#endif // defined(_WIN32)

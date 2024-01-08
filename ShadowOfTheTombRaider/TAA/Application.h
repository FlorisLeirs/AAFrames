#pragma once

#include "DllCommon.h"

#include <chrono>
#include <cstdint>
#include <functional>
#include <string>
#include <vector>

struct ApplicationMemoryStats_v1
{
    const static uint32_t CURRENT_VERSION = 1;
    const static uint32_t MAX_STATS = 16;

    uint32_t version = CURRENT_VERSION;
    uint64_t stats[MAX_STATS];
};

using ApplicationMemoryStats = ApplicationMemoryStats_v1;
using ApplicationMemoryStatsCallback = bool (*)(ApplicationMemoryStats&);

enum class CpuTimingPhase
{
    SUBMIT,
    FINISH,
    RESET,
    RESET_FINISH,

    COUNT
};

//-----------------------------------------------------------------------------
// Application
//-----------------------------------------------------------------------------
class Application
{
protected:
    NV_REPLAY_EXPORT Application();
    NV_REPLAY_EXPORT Application(const Application&);
    NV_REPLAY_EXPORT Application& operator=(const Application&);

public:
    enum AsyncResetFlags
    {
        ASYNC_RESET_NONE = 0x0,
        ASYNC_RESET_SYSMEM_BUFFERS = 0x1,
        ASYNC_RESET_SYSMEM_HEAPS = 0x2,
    };

    NV_REPLAY_EXPORT static Application& PlatformInstance();

    NV_REPLAY_EXPORT int Execute();
    NV_REPLAY_EXPORT int Execute(int argc, char** argv);
    NV_REPLAY_EXPORT static bool VerboseOutput();
    NV_REPLAY_EXPORT static bool HasForceBorderlessWindow();

#if defined(NV_REPLAY_ON_ORIGINAL_THREAD_IDS)
    NV_REPLAY_EXPORT static bool HasMultiThreadedReplay();
    NV_REPLAY_EXPORT static void EnableMultiThreadedReplay(bool enable);
#endif

    NV_REPLAY_EXPORT static bool MinimizeCPUOverheadRequested();
    NV_REPLAY_EXPORT static bool ShouldCatchAndReportSystemExceptions();

    NV_REPLAY_EXPORT static void SetFrameExecutor(std::function<bool(uint64_t)> fnExecutor);
    NV_REPLAY_EXPORT static bool ExecuteFrame(uint64_t frameIndex);

    NV_REPLAY_EXPORT static void RegisterForAsyncDataReset(AsyncResetFlags flags);
    NV_REPLAY_EXPORT static AsyncResetFlags GetAsyncDataResetFlags();
    NV_REPLAY_EXPORT static void SetAsyncDataResetter(std::function<void()> fnDataResetter);
    NV_REPLAY_EXPORT static void DoAsyncDataReset();

    NV_REPLAY_EXPORT void RegisterMemoryStats(size_t count, const char** names, ApplicationMemoryStatsCallback getStatsCallback);
    NV_REPLAY_EXPORT void TimingPhaseBegin(CpuTimingPhase phase);
    NV_REPLAY_EXPORT void TimingPhaseEnd(CpuTimingPhase phase);

    NV_REPLAY_EXPORT void Shutdown()
    {
        m_shutdown = true;
    }

protected:
    NV_REPLAY_EXPORT bool ParseCommandLine(int argc, char** argv);
    NV_REPLAY_EXPORT void OnError(const char* pMessage);

    NV_REPLAY_EXPORT virtual int ExecuteInternal(int argc, char** argv);
    NV_REPLAY_EXPORT virtual void PlatformInit();
    NV_REPLAY_EXPORT virtual void PlatformDone();
    NV_REPLAY_EXPORT virtual void OutputMessage(const std::string& message) const;
    NV_REPLAY_EXPORT virtual bool ProcessMessages() = 0;

private:
    void ExecWatchdog();

private:
    uint64_t m_repeatCount = 0;
    uint64_t m_frameIndex = 0;
    bool m_perfStats = false;
    bool m_perfStatsVerbose = false;
    bool m_forceBorderlessWindow = false;
#if defined(NV_REPLAY_ON_ORIGINAL_THREAD_IDS)
    bool m_multiThreadedReplay = true;
#endif
    bool m_dumpFrameTimes = false;
    bool m_verbose = false;
    bool m_minimizeCPUOverhead = false;
    bool m_catchAndReportSystemExceptions = true;
    bool m_watchdogThreadEnabled = false;
    bool m_watchdogThreadActive = false;
    std::function<bool(uint64_t)> m_fnFrameExecutor;

    std::vector<std::string> m_memoryStatNames;
    ApplicationMemoryStatsCallback m_fnGetMemoryStats = nullptr;

    // Timing reports
    struct Timings
    {
        using Clock = std::chrono::high_resolution_clock;
        Clock::time_point lastReport = Clock::now();

        // Number of frames seen in this report
        uint32_t numFrames = 0;

        struct Phase
        {
            Clock::time_point begin = {};
            Clock::time_point end = {};
            std::chrono::microseconds runningTotal = {};
        };

        Phase phases[int(CpuTimingPhase::COUNT)] = {};
    };
    Timings m_runningTimings;

    AsyncResetFlags m_asyncDataResetFlags = ASYNC_RESET_NONE;
    std::function<void()> m_fnDataResetter;
    bool m_shutdown = false;
};

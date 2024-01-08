#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <stdexcept>

#if defined(_WIN32)
#include <windows.h>
#endif

#include "Application.h"
#include "Helpers.h"
#include "ReadOnlyDatabase.h"

#if defined(_MSC_VER)
#define NV_REPLAY_NOINLINE __declspec(noinline)
#define NV_REPLAY_FORCEINLINE __forceinline
#elif defined(__GNUC__) || defined(__INTEGRITY)
#define NV_REPLAY_NOINLINE __attribute__((noinline))
#define NV_REPLAY_FORCEINLINE inline __attribute__((always_inline))
#else
#define NV_REPLAY_NOINLINE
#define NV_REPLAY_FORCEINLINE inline
#endif

//-----------------------------------------------------------------------------
// Global Flags
//-----------------------------------------------------------------------------
NV_REPLAY_EXPORT extern bool hasFrameReset;
NV_REPLAY_EXPORT extern bool forceDebug;
NV_REPLAY_EXPORT extern bool automated;
NV_REPLAY_EXPORT extern bool useDebugBytecode;
NV_REPLAY_EXPORT extern char errorBuf[512];
NV_REPLAY_EXPORT extern bool debuggerBreakOnError;

static const char NV_FRAME_RESET_MARKER_NAME[] = "[NSIGHT] Frame Reset";
static const wchar_t NV_FRAME_RESET_MARKER_NAME_W[] = L"[NSIGHT] Frame Reset";

#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf _snprintf
#endif

#define NV_SAFE_RELEASE(_pObject) \
    if (_pObject)                 \
    {                             \
        _pObject->Release();      \
        _pObject = NULL;          \
    }
#define NV_SAFE_DESTROY(_pObject) \
    if (_pObject)                 \
    {                             \
        _pObject->Destroy();      \
        _pObject = NULL;          \
    }

NV_REPLAY_EXPORT extern float HexToFloat(uint32_t h);
NV_REPLAY_EXPORT extern double HexToDouble(uint64_t h);
NV_REPLAY_EXPORT extern float NAN_F();
NV_REPLAY_EXPORT extern float INF_F();
NV_REPLAY_EXPORT extern double NAN_D();
NV_REPLAY_EXPORT extern double INF_D();

template <typename... T>
void ignore_unused_variable(const T&...)
{
}

#if defined(_WIN32)
NV_REPLAY_EXPORT extern HINSTANCE currentInstance;
NV_REPLAY_EXPORT extern HRESULT result;

NV_REPLAY_EXPORT extern void CheckResult(HRESULT result, const char* file, int line);
#define NV_CHECK_RESULT(_result) CheckResult(_result, __FILE__, __LINE__)

// Setting object name, default to no-op. Each API will define overload in the their replay file
void NvNameHelperSetObjectName(void* pObj, const char* pName);
#define NV_SET_OBJECT_NAME(X, NAME) NvNameHelperSetObjectName(X, NAME)
#endif

//-----------------------------------------------------------------------------
// Threading Resources
//-----------------------------------------------------------------------------
extern bool releaseReplayerThreads;
extern bool exitReplayerThreads;

#if defined(_WIN32)
extern HANDLE threadSequenceEvents[];
extern HANDLE threadDoneEvents[];
#else
class AutoResetEvent;
using EventsArray = std::array<std::shared_ptr<AutoResetEvent>, NUM_REPLAYER_THREADS>;
extern EventsArray threadSequenceEvents;
extern EventsArray threadDoneEvents;
#endif

//-------------------------------------------------------------------------------------------------
// Logging
//-------------------------------------------------------------------------------------------------
NV_REPLAY_EXPORT extern void ReportErrorWithMessage(const char* message, const char* file, int line);
NV_REPLAY_EXPORT extern void ThrowErrorWithMessage(const char* message, const char* file, int line);
NV_REPLAY_EXPORT extern void WriteMessage(const char* message);

inline void NvMessage(const char* message)
{
    WriteMessage(message);
}

template <typename... Targs>
void NvMessage(const char* format, Targs... fArgs)
{
    const int BUFFER_SIZE = 512;
    char message[BUFFER_SIZE] = { 0 };
    snprintf(message, BUFFER_SIZE - 1, format, fArgs...);
    WriteMessage(message);
}

#define NV_MESSAGE(...) NvMessage(__VA_ARGS__)

#define NV_MESSAGE_ONCE(...)         \
    do                               \
    {                                \
        static bool s_once = false;  \
        if (!s_once)                 \
        {                            \
            NV_MESSAGE(__VA_ARGS__); \
            s_once = true;           \
        }                            \
    } while (false)

#define NV_MESSAGE_VERBOSE(...)       \
    if (Application::VerboseOutput()) \
    {                                 \
        NV_MESSAGE(__VA_ARGS__);      \
    }

#define NV_THROW_IF(_Condition, _Message)                    \
    if (_Condition)                                          \
    {                                                        \
        ThrowErrorWithMessage(_Message, __FILE__, __LINE__); \
    }
#define NV_ASSERT(_Condition) assert(_Condition)

#define NV_ANONYMOUS_VARIABLE_DIRECT(_NAME, _LINE) _NAME##_LINE
#define NV_ANONYMOUS_VARIABLE(_NAME, _LINE) NV_ANONYMOUS_VARIABLE_DIRECT(_NAME, _LINE)

#define NV_DO_STRINGIZE(S) #S
#define NV_STRINGIZE(S) NV_DO_STRINGIZE(S)

//-------------------------------------------------------------------------------------------------
// Database
//-------------------------------------------------------------------------------------------------
NV_REPLAY_EXPORT void InitializeDatabase();
NV_REPLAY_EXPORT Serialization::ReadOnlyDatabase& GetDatabase();

#if !defined(DATABASE_BIN_FILE)
#define DATABASE_BIN_FILE "data.bin"
#endif

#if !defined(DO_NOT_USE_BEGIN_DATA_SCOPE)
#if defined(__arm__)
template <typename T, typename DataScopeTrackerType>
T GetResources(DataScopeTrackerType& dataScopeTracker, Serialization::DATABASE_HANDLE handle)
{
    std::shared_ptr<Serialization::BlobProxyBase> spBlobProxy = GetDatabase().ReadShared<T>(handle);
    dataScopeTracker.AddBlobProxyToCurrentDataScope(spBlobProxy);
    return (std::static_pointer_cast<Serialization::BlobProxy<T>>(spBlobProxy))->Get();
}
#define NV_GET_RESOURCE(T, handle) GetResources<T>(dataScopeTracker, handle)
#define NV_GET_RESOURCE_NOSCOPETRACKER(T, handle) NV_GET_RESOURCE(T, handle)
#define NV_GET_BYTECODE(T, handle) GetResources<T>(dataScopeTracker, handle)
#define NV_GET_RESOURCE_CHECKED(T, handle, size) GetResources<T>(dataScopeTracker, handle)
#define NV_GET_RESOURCE_CHECKED_NOSCOPETRACKER(T, handle, size) NV_GET_RESOURCE(T, handle)
#else
#define NV_GET_RESOURCE(T, handle) GetDatabase().Read<T>(handle, dataScopeTracker).Get()
#define NV_GET_RESOURCE_NOSCOPETRACKER(T, handle) GetDatabase().Read<T>(handle).Get()
#define NV_GET_BYTECODE(T, handle) GetDatabase().Read<T>(handle, dataScopeTracker).Get()
template <typename T, typename DataScopeTrackerType>
T GetResourceChecked(Serialization::DATABASE_HANDLE handle, size_t size, DataScopeTrackerType& dataScopeTracker)
{
    NV_THROW_IF(size != 0 && GetDatabase().GetSize(handle) != size, "Database size mismatch")
    return GetDatabase().Read<T>(handle, dataScopeTracker).Get();
}
#define NV_GET_RESOURCE_CHECKED(T, handle, size) GetResourceChecked<T>(handle, size, dataScopeTracker)
template <typename T>
T GetResourceChecked_NoScopeTracker(Serialization::DATABASE_HANDLE handle, size_t size)
{
    NV_THROW_IF(size != 0 && GetDatabase().GetSize(handle) != size, "Database size mismatch");
    return GetDatabase().Read<T>(handle).Get();
}
#define NV_GET_RESOURCE_CHECKED_NOSCOPETRACKER(T, handle, size) GetResourceChecked_NoScopeTracker<T>(handle, size)
#endif // defined(__arm__)
#endif // !defined(DO_NOT_USE_BEGIN_DATA_SCOPE)

#define NV_GET_RESOURCE_STATIC(T, handle, size)                \
    []() {                                                     \
        static void* s_ptr = DoGetStaticDatabaseEntry(handle); \
        return (T)s_ptr;                                       \
    }()

inline void* DoGetStaticDatabaseEntry(Serialization::DATABASE_HANDLE handle)
{
    const auto size = GetDatabase().GetSize(handle);
    if (size == 0)
    {
        return nullptr;
    }
    void* dst = malloc(size);
    NV_THROW_IF(!dst, "Failed to allocate memory for database read");
    const void* src = GetDatabase().Read<const void*>(handle).Get();
    NV_THROW_IF(!src, "Failed to read database entry");
    memcpy(dst, src, size);
    return dst;
}

NV_REPLAY_EXPORT extern void FreeCachedMemory();

//-------------------------------------------------------------------------------------------------
// The optimizer has shown to have a large compilation time impact on generated code.
// We can significantly speed up compilation time by disabling the optimizer for initialization
// code as that is not in the critical path of runtime performance.
//-------------------------------------------------------------------------------------------------
#ifdef NV_FORCE_OPTIMIZE
#define NV_REPLAY_BEGIN_FRAME()
#define NV_REPLAY_BEGIN_FRAME_SETUP()
#define NV_REPLAY_BEGIN_FRAME_RESET()
#define NV_REPLAY_BEGIN_RESOURCE_INIT()
#define NV_REPLAY_BEGIN_COMMAND_LIST()
#define NV_REPLAY_END_FRAME()
#define NV_REPLAY_END_FRAME_SETUP()
#define NV_REPLAY_END_FRAME_RESET()
#define NV_REPLAY_END_RESOURCE_INIT()
#define NV_REPLAY_END_COMMAND_LIST()
#else
#if defined(_MSC_VER)
#define NV_DISABLE_OPTIMIZATION __pragma(optimize("", off))
#define NV_ENABLE_OPTIMIZATION __pragma(optimize("", on))
#elif defined(__GNUC__) && !defined(__clang__)
#define NV_DISABLE_OPTIMIZATION \
    _Pragma("GCC push_options") \
        _Pragma("GCC optimize(0)")
#define NV_ENABLE_OPTIMIZATION _Pragma("GCC pop_options")
#else
#define NV_DISABLE_OPTIMIZATION
#define NV_ENABLE_OPTIMIZATION
#endif
#define NV_REPLAY_BEGIN_FRAME() /* Optimize */
#define NV_REPLAY_BEGIN_FRAME_SETUP() NV_DISABLE_OPTIMIZATION
#define NV_REPLAY_BEGIN_FRAME_RESET() NV_DISABLE_OPTIMIZATION
#define NV_REPLAY_BEGIN_RESOURCE_INIT() NV_DISABLE_OPTIMIZATION
#define NV_REPLAY_BEGIN_COMMAND_LIST() /* Optimize */
#define NV_REPLAY_END_FRAME() /* nothing to re-enable */
#define NV_REPLAY_END_FRAME_SETUP() NV_ENABLE_OPTIMIZATION
#define NV_REPLAY_END_FRAME_RESET() NV_ENABLE_OPTIMIZATION
#define NV_REPLAY_END_RESOURCE_INIT() NV_ENABLE_OPTIMIZATION
#define NV_REPLAY_END_COMMAND_LIST() /* nothing to re-enable */
#endif

extern size_t g_threadPoolThreadCount;

enum class NVCheckedMemcpyState
{
    PASS_0,
    PASS_1,
    DETECTED_DIFFS,
    DETECTED_NO_DIFFS
};

#define NV_MEMCPY_IN_FRAME(dst, src, size)                                \
    do                                                                    \
    {                                                                     \
        static NVCheckedMemcpyState state = NVCheckedMemcpyState::PASS_0; \
        NVCheckedMemcpy(dst, src, size, state);                           \
    } while (false)

void NVCheckedMemcpy(void* dst, const void* src, size_t size, NVCheckedMemcpyState& state);

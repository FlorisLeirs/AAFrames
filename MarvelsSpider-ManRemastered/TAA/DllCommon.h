#include <cstddef>

#if defined(NV_REPLAY_LIB_SHARED)
#if defined(_WIN32)
#if defined(ReplayExecutor_EXPORTS)
#define NV_REPLAY_EXPORT __declspec(dllexport)
#else
#define NV_REPLAY_EXPORT __declspec(dllimport)
#endif
#else
#define NV_REPLAY_EXPORT __attribute__((visibility("default")))
#endif
#else
#define NV_REPLAY_EXPORT
#endif

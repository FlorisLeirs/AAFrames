//--------------------------------------------------------------------------------------
// File: DataScope.h
//
// Distributed as part of NVIDIA Nsight serialization output.
//
// Copyright (c) NVIDIA Corporation.  All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <memory>
#include <vector>

#include "DllCommon.h"

#if defined(_MSC_VER) && _MSC_VER < 1900
#define TLS_STORAGE __declspec(thread)
#elif defined(__GNUC__)
#define TLS_STORAGE __thread
#else
#define TLS_STORAGE thread_local
#endif

#define NV_DATABASE_WARN(CONDITION, MESSAGE) assert((CONDITION) && MESSAGE)

#define DATA_SCOPE_NAME_CONCAT_HELPER(X, Y) X##Y
#define DATA_SCOPE_NAME_CONCAT(X, Y) DATA_SCOPE_NAME_CONCAT_HELPER(X, Y)

#define BEGIN_DATA_SCOPE_FUNCTION_EX(DATABASE_CLASS)                      \
    auto& dataScopeTracker = Serialization::DataScopeTracker::Instance(); \
    BEGIN_DATA_SCOPE_EX(DATABASE_CLASS)

#define BEGIN_DATA_SCOPE_EX(DATABASE_CLASS) Serialization::DataScope DATA_SCOPE_NAME_CONCAT(scope_line_no_, __LINE__)(dataScopeTracker)

namespace Serialization {

class IReadOnlyDatabase;

#if defined(__arm__)
struct BlobProxyBase
{
};
#endif // defined(__arm__)

class DataScopeTracker;

//------------------------------------------------------------------------------
// DataScope
//------------------------------------------------------------------------------
class DataScope
{
public:
    using PageId = uint64_t;
    using LockedPageHandle = void*;

    NV_REPLAY_EXPORT DataScope(DataScopeTracker& tracker);
    NV_REPLAY_EXPORT ~DataScope();
    NV_REPLAY_EXPORT void SetUsesPage(PageId pageOffset, IReadOnlyDatabase& database);

private:
    DataScopeTracker& m_Tracker;
    DataScope* m_pParent;

    const static int NUM_STATIC_IDS = 2;
    LockedPageHandle m_staticStorage[NUM_STATIC_IDS];
    std::vector<LockedPageHandle> m_dynamicStorage;

    LockedPageHandle* m_pUsedPages;
    int m_usedPageCount;
    IReadOnlyDatabase* m_pDatabase;

#if defined(__arm__)
public:
    void AddBlobProxy(std::shared_ptr<BlobProxyBase>& pBlobProxy);

private:
    std::vector<std::shared_ptr<BlobProxyBase>> m_blobProxyVec;
#endif
};

//------------------------------------------------------------------------------
// Singleton to track data usage scope.
//------------------------------------------------------------------------------
class DataScopeTracker
{
    friend class DataScope;

public:
    static NV_REPLAY_EXPORT DataScopeTracker& Instance();
    DataScopeTracker(const DataScopeTracker&) = delete;
    void operator=(const DataScopeTracker&) = delete;

    void SetUsesPage(uint64_t pageOffset, IReadOnlyDatabase& database);

#if defined(__arm__)
    void AddBlobProxyToCurrentDataScope(std::shared_ptr<BlobProxyBase>& pBlobProxy);
#endif

private:
    DataScopeTracker();
    DataScope* m_pCurrentDataScope;
};

} // namespace Serialization

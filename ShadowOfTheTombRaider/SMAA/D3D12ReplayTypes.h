#pragma once

#include "d3d12.h"
#include <array>
#include <cstdint>

// Constants
#define NV_D3D12_REPLAY_MULTIBUFFER_COUNT 3

// Get the current index for multibuffered device children
int D3D12GetMultibufferedIndex();

using D3D12DescriptorHeapStrides = std::array<UINT, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES>;
using D3D12DescriptorHeapSizes = std::array<UINT64, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES>;

template <typename T>
struct D3D12MultibufferedPOD : public std::array<T, NV_D3D12_REPLAY_MULTIBUFFER_COUNT>
{
    D3D12MultibufferedPOD()
        : m_multibufferCount(1)
    {
        this->fill({});
    }

    operator T() const
    {
        return (*this)[D3D12GetMultibufferedIndex()];
    }

    void SetActiveMultibufferCount(size_t count)
    {
        m_multibufferCount = count;
    }

    size_t GetActiveMultibufferCount() const
    {
        return m_multibufferCount;
    }

    T GetCheckedElement(size_t index) const
    {
        auto overrideIndex = index % m_multibufferCount;
        return (*this)[overrideIndex];
    }

private:
    size_t m_multibufferCount;
};

using D3D12MultibufferedCpuHandle = D3D12MultibufferedPOD<D3D12_CPU_DESCRIPTOR_HANDLE>;
using D3D12MultibufferedGpuHandle = D3D12MultibufferedPOD<D3D12_GPU_DESCRIPTOR_HANDLE>;

template <typename T>
struct NVD3D12MultiBufferedArray : public std::array<T*, NV_D3D12_REPLAY_MULTIBUFFER_COUNT>
{
    using ElementType = T;

    NVD3D12MultiBufferedArray()
        : NVD3D12MultiBufferedArray(nullptr)
    {
    }

    NVD3D12MultiBufferedArray(nullptr_t)
        : m_multibufferCount()
        , m_overrideMultibufferIndex()
        , m_overridenMultibufferIndex()
        , m_mappedData()
    {
        this->fill(nullptr);
        m_mappedData.fill(nullptr);
    }

    // Pass by copy is allowed, this is POD
    NVD3D12MultiBufferedArray(const NVD3D12MultiBufferedArray&) = default;

    operator T*() const
    {
        return (*this)[GetActiveMultibufferCurrentIndex()];
    }

    T* operator->() const
    {
        return (*this)[GetActiveMultibufferCurrentIndex()];
    }

    T** operator&()
    {
        return &(*this)[GetActiveMultibufferCurrentIndex()];
    }

    T* GetCheckedElement(size_t index) const
    {
        auto overrideIndex = index % GetActiveMultibufferCount();
        return (*this)[overrideIndex];
    }

    void Clear()
    {
        for (auto& pPointer : *this)
        {
            if (pPointer)
            {
                My_IUnknown_Release(pPointer);
                pPointer = nullptr;
            }
        }
    }

    size_t GetActiveMultibufferCount() const
    {
        if (!m_multibufferCount)
        {
            m_multibufferCount = InitActiveMultibufferCount();
        }

        return m_multibufferCount;
    }

    size_t GetActiveMultibufferCurrentIndex() const
    {
        if (m_overrideMultibufferIndex)
        {
            return m_overridenMultibufferIndex;
        }

        return D3D12GetMultibufferedIndex() % GetActiveMultibufferCount();
    }

    void OverrideMultibufferCurrentIndex(bool forceOverride, size_t index = 0) const
    {
        m_overrideMultibufferIndex = forceOverride;
        m_overridenMultibufferIndex = index;
    }

    void SuppressMultibuffering(bool suppress)
    {
        m_multibufferCount = suppress ? 1 : InitActiveMultibufferCount();
    }

    void*& GetActiveMultibufferMappedData(size_t index = UINT_MAX) const
    {
        if (index == UINT_MAX)
        {
            index = GetActiveMultibufferCurrentIndex();
        }
        return const_cast<void*&>(m_mappedData[index]);
    }

private:
    size_t InitActiveMultibufferCount() const;
    mutable size_t m_multibufferCount;
    mutable bool m_overrideMultibufferIndex;
    mutable size_t m_overridenMultibufferIndex;
    std::array<void*, NV_D3D12_REPLAY_MULTIBUFFER_COUNT> m_mappedData;
};

// Pointer -> pointer
template <typename T_Dest, typename T_Source>
T_Dest D3D12StaticCast(T_Source* pSrc)
{
    return static_cast<T_Dest>(pSrc);
}

// Null -> pointer
template <typename T_Dest>
T_Dest D3D12StaticCast(nullptr_t pSrc)
{
    return nullptr;
}

// Multibuffered -> pointer
template <typename T_Dest, typename T_Source, std::enable_if_t<std::is_pointer<T_Dest>::value, bool> = true>
const T_Dest D3D12StaticCast(const NVD3D12MultiBufferedArray<T_Source>& source)
{
    T_Source* pSrcElement = source; // Get current element
    return static_cast<T_Dest>(pSrcElement);
}

// Multibuffered -> multibuffered
template <typename T_Dest, typename T_Source, std::enable_if_t<std::is_class<T_Dest>::value, bool> = true>
const T_Dest& D3D12StaticCast(const NVD3D12MultiBufferedArray<T_Source>& source)
{
    const auto& result = reinterpret_cast<const T_Dest&>(source);

    // Perform a compile time test that the types are convertible.
    T_Source* pTest = static_cast<T_Source*>(result[0]);
    (void)pTest;

    return result;
}

// Multibuffered -> multibuffered
template <typename T_Dest, typename T_Source, std::enable_if_t<std::is_class<T_Dest>::value, bool> = true>
T_Dest& D3D12StaticCast(NVD3D12MultiBufferedArray<T_Source>& source)
{
    auto& result = reinterpret_cast<T_Dest&>(source);

    // Perform a compile time test that the types are convertible.
    T_Source* pTest = static_cast<T_Source*>(result[0]);
    (void)pTest;

    return result;
}

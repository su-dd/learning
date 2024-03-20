#include "Shared_Lock.h"

void SharedLock::lock()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cv_exclusive.wait(
        lock, [this]() -> bool
        { return (m_shared_count.load(std::memory_order_acquire) == 0) && !m_in_exclusive.load(std::memory_order_acquire); });
    m_in_exclusive.store(true, std::memory_order_relaxed);
    m_exclusive_count.fetch_add(1, std::memory_order_relaxed);
}

void SharedLock::unlock()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_exclusive_count.load(std::memory_order_acquire) > 0)
    {
        m_exclusive_count.fetch_sub(1, std::memory_order_relaxed);
    }

    if (m_exclusive_count.load(std::memory_order_acquire) == 0)
    {
        m_in_exclusive.store(false, std::memory_order_relaxed);
        m_cv_shared.notify_all();
    }
    else
    {
        m_cv_exclusive.notify_one();
    }
}

void SharedLock::shared_lock()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cv_shared.wait(lock, [this]() -> bool
                     { return !m_in_exclusive.load(std::memory_order_acquire); });
    m_shared_count.fetch_add(1, std::memory_order_relaxed);
}

void SharedLock::shared_unlock()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_shared_count.load(std::memory_order_acquire) > 0)
    {
        m_shared_count.fetch_sub(1, std::memory_order_relaxed);
    }

    if (m_shared_count.load(std::memory_order_acquire) == 0)
    {
        m_cv_exclusive.notify_one();
    }
}

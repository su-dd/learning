#include "SpinLock.h"

void SpinLock::lock()
{
    bool expected = false;
    // 这里一直循环到m_flag为false，才会设置m_flag为true
    // 一直循环就是锁住了，直到解锁
    while (!m_flag.compare_exchange_weak(expected, true, std::memory_order_acquire))
    {
        expected = false;
    }
}

bool SpinLock::try_lock()
{
    bool expected = false;
    return m_flag.compare_exchange_strong(expected, true, std::memory_order_acquire);
}

void SpinLock::unlock()
{
    m_flag.store(false, std::memory_order_release);
}

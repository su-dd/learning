#ifndef D2F04BF5_0600_4FBE_B271_93B8C6DBC6B7
#define D2F04BF5_0600_4FBE_B271_93B8C6DBC6B7
#include <atomic>
#include <mutex>
#include <condition_variable> //用于条件变量
class SharedLock
{
public:
    SharedLock() : m_shared_count(0), m_exclusive_count(0), m_in_exclusive(false) {}

    void lock();
    void unlock();

    void shared_lock();
    void shared_unlock();

private:
    std::atomic_int m_shared_count;
    std::atomic_int m_exclusive_count;
    std::atomic_bool m_in_exclusive;
    std::condition_variable m_cv_shared;
    std::condition_variable m_cv_exclusive;
    std::mutex m_mutex;
};

class SharedLockGuard
{
public:
    SharedLockGuard(SharedLock &lock) : m_lock(lock)
    {
        m_lock.shared_lock();
    }

    ~SharedLockGuard()
    {
        m_lock.shared_unlock();
    }

private:
    SharedLock &m_lock;
};

class ExclusiveLockGuard
{
public:
    ExclusiveLockGuard(SharedLock &lock) : m_lock(lock)
    {
        m_lock.lock();
    }

    ~ExclusiveLockGuard()
    {
        m_lock.unlock();
    }

private:
    SharedLock &m_lock;
};

#endif /* D2F04BF5_0600_4FBE_B271_93B8C6DBC6B7 */

#ifndef D2F04BF5_0600_4FBE_B271_93B8C6DBC6B7
#define D2F04BF5_0600_4FBE_B271_93B8C6DBC6B7
#include <mutex>
#include <condition_variable> //用于条件变量
class SharedLock
{
public:
    SharedLock() : m_count(0) {}

    void lock();
    void unlock();

    void shared_lock();
    void shared_unlock();

private:
    int m_count;
};

#endif /* D2F04BF5_0600_4FBE_B271_93B8C6DBC6B7 */

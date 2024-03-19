#ifndef D95E239D_6692_4E82_8548_0D570BFC601A
#define D95E239D_6692_4E82_8548_0D570BFC601A

#include <atomic>

class SpinLock
{
public:
    SpinLock() : m_flag(false) {}
    void lock();
    bool try_lock();
    void unlock();

private:
    std::atomic_bool m_flag;
};

#endif /* D95E239D_6692_4E82_8548_0D570BFC601A */

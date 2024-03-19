#include <iostream>
#include <thread>
#include "SpinLock.h"

void threadedFunction(SpinLock &lock)
{
    for (int i = 0; i < 10; ++i)
    {
        lock.lock();
        // critical section
        std::cout << "Thread " << std::this_thread::get_id() << " is in critical section" << std::endl;
        lock.unlock();
    }
}

int main()
{
    SpinLock lock;
    std::thread t1(threadedFunction, std::ref(lock));
    std::thread t2(threadedFunction, std::ref(lock));
    t1.join();
    t2.join();
    return 0;
}
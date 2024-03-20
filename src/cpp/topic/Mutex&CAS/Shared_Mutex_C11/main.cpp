#include <iostream>
#include <thread>
#include "Shared_Lock.h"
#include <mutex>

void read_operation(SharedLock &mtx)
{
    SharedLockGuard lock(mtx);
    // read operation
    std::cout << "thread " << std::this_thread::get_id() << " Reading data..." << std::endl;
}

void write_operation(SharedLock &mtx)
{
    ExclusiveLockGuard lock(mtx);
    // write operation
    std::cout << "thread " << std::this_thread::get_id() << " Writing data..." << std::endl;
}

int main()
{
    SharedLock mtx;

    std::thread t1(read_operation, std::ref(mtx));
    // std::thread t2(read_operation, std::ref(mtx));
    std::thread t3(write_operation, std::ref(mtx));

    t1.join();
    // t2.join();
    t3.join();

    return 0;
}
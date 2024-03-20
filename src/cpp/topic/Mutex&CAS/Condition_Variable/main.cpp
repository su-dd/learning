#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

void thread_func1(std::condition_variable &cv, std::mutex &mtx, std::atomic_bool &ready)
{
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "thread_func1: waiting ..." << std::endl;
    cv.wait(lck, [&]()
            { return ready.load(std::memory_order_relaxed); });
    std::cout << "thread_func1: waiting done." << std::endl;
}

void thread_func2(std::condition_variable &cv, std::mutex &mtx, std::atomic_bool &ready)
{
    // Wait for 1 second before notifying the condition variable
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::unique_lock<std::mutex> lck(mtx);
    bool expected = false;
    ready.compare_exchange_strong(expected, true, std::memory_order_acquire);

    std::cout << "thread_func2: notifying ..." << std::endl;
    cv.notify_one();
    std::cout << "thread_func2: notified." << std::endl;
}

void thread_func3(std::condition_variable &cv, std::mutex &mtx, std::atomic_bool &ready)
{
    // Wait for 1 second before notifying the condition variable
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    {
        std::lock_guard<std::mutex> lck(mtx);
        bool expected = false;
        ready.compare_exchange_strong(expected, true, std::memory_order_acquire);
    }
    std::cout << "thread_func3: notifying ..." << std::endl;
    cv.notify_one();
    std::cout << "thread_func3: notified." << std::endl;
}

int main()
{
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic_bool ready(false);

    std::thread t1(thread_func1, std::ref(cv), std::ref(mtx), std::ref(ready));
    // std::thread t2(thread_func2, std::ref(cv), std::ref(mtx), std::ref(ready));
    std::thread t3(thread_func3, std::ref(cv), std::ref(mtx), std::ref(ready));

    t1.join();
    // t2.join();
    t3.join();

    return 0;
}
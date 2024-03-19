#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

// 常见使用方式
void thread_func1(int id, std::mutex &mtx)
{
    for (int i = 0; i < 2; ++i)
    {
        mtx.lock();
        std::cout << "thread_func1 " << id << " acquired lock and prints " << i << std::endl;
        mtx.unlock();
    }
}

// 可以通过try_lock作为自旋锁使用
void thread_func2(int id, std::mutex &mtx)
{
    for (int i = 0; i < 2; ++i)
    {
        while (!mtx.try_lock())
        {
            // 这里可以自旋等待，直到获得锁
            std::cout << "thread_func2 " << id << " is waiting for lock..." << std::endl;
            sleep(1); // 自旋时也可以使用 sleep() 函数，usleep() 函数 做睡眠
        }
        std::cout << "thread_func2 " << id << " acquired lock and prints " << i << std::endl;
        mtx.unlock();
    }
}

// std::lock_guard 通过RAII（Resource Acquisition Is Initialization）的方式使用
void thread_func3(int id, std::mutex &mtx)
{
    for (int i = 0; i < 2; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "thread_func3 " << id << " acquired lock and prints " << i << std::endl;
    }
}

//  std::unique_lock也是RAII，但可以做一些 延迟加锁，提前释放，等灵活使用方式；但比较重
void thread_func4(int id, std::mutex &mtx)
{
    for (int i = 0; i < 2; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "thread_func4 " << id << " acquired lock and prints " << i << std::endl;
    }
}

void thread_func5(int id, std::mutex &mtx1, std::mutex &mtx2)
{
    for (int i = 0; i < 2; ++i)
    {
        std::lock(mtx1, mtx2);
        // std::adopt_lock作用是声明互斥量已在本线程锁定，std::lock_guard只是保证互斥量在作用域结束时被释放
        std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
        std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
        std::cout << "thread_func5 " << id << " acquired locks and prints " << i << std::endl;
    }
}

void thread_func6(int id, std::mutex &mtx1, std::mutex &mtx2)
{
    for (int i = 0; i < 2; ++i)
    {
        // std::defer_lock 用于延迟锁定，直到调用lock()函数时才真正锁定互斥量
        std::unique_lock<std::mutex> lock1(mtx1, std::defer_lock);
        std::unique_lock<std::mutex> lock2(mtx2, std::defer_lock);
        std::lock(lock1, lock2);
        std::cout << "thread_func6 " << id << " acquired locks and prints " << i << std::endl;
    }
}

void thread_func7(int id, std::mutex &mtx1, std::mutex &mtx2)
{
    for (int i = 0; i < 2; ++i)
    {
        if (-1 == std::try_lock(mtx1, mtx2))
        {
            std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
            std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
            std::cout << "thread_func6 " << id << " acquired locks and prints " << i << std::endl;
        }
    }
}

int main()
{
    std::mutex mtx1, mtx2;
    std::thread t1(thread_func1, 1, std::ref(mtx1));
    std::thread t2(thread_func2, 2, std::ref(mtx1));
    std::thread t3(thread_func3, 3, std::ref(mtx1));
    std::thread t4(thread_func4, 4, std::ref(mtx1));
    std::thread t5(thread_func5, 5, std::ref(mtx1), std::ref(mtx2));
    std::thread t6(thread_func6, 6, std::ref(mtx1), std::ref(mtx2));
    std::thread t7(thread_func7, 7, std::ref(mtx1), std::ref(mtx2));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();

    return 0;
}
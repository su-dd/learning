#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main()
{
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false;

    std::thread t([&]()
                  {  
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [&]() { return ready; });
        std::cout << "Thread 2: " << std::this_thread::get_id() << std::endl; });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    {
        std::unique_lock<std::mutex> lck(mtx);
        ready = true;
        cv.notify_one();
    }

    t.join();

    return 0;
}
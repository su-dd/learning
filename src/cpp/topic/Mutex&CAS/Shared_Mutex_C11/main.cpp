#include <iostream>
#include <thread>
// #include <shared_mutex> // C++17 for shared_lock and shared_mutex
#include <mutex>

// void read_operation(std::shared_mutex &mtx)
// {
//     std::shared_lock<std::shared_mutex> lock(mtx);
//     // read operation
//     std::cout << "thread " << std::this_thread::get_id() << "Reading data..." << std::endl;
// }

// void write_operation(std::shared_mutex &mtx)
// {
//     std::unique_lock<std::shared_mutex> lock(mtx);
//     // write operation
//     std::cout << "thread " << std::this_thread::get_id() << "Writing data..." << std::endl;
// }

int main()
{
    // std::shared_mutex mtx;

    return 0;
}
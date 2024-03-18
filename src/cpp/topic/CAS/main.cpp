#include <iostream>
#include "test1.h"
#include <thread>

void test()
{
    atomic_Int a(0);
    std::thread t1(test_atomicInt_add, std::ref(a));
    std::thread t2(test_atomicInt_sub, std::ref(a));

    if (t1.joinable())
    {
        t1.join();
    }

    if (t2.joinable())
    {
        t2.join();
    }
    std::cout << "Final value of a: " << a.load() << std::endl;
}

int main()
{
    test();
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
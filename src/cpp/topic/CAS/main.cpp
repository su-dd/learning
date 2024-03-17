#include <iostream>
#include <atomic>

using atomicInt = std::atomic<int>;

int main()
{
    atomicInt x(0);
    x.store(10);
    std::cout << x.load() << std::endl; // prints 10

    int oldVal, newVal = 0;
    do
    {
        oldVal = x.load();
        newVal = oldVal + 1;
    } while (!x.compare_exchange_strong(oldVal, newVal));

    std::cout << x.load() << std::endl; // prints 20
    return 0;
}
#include "test1.h"
#include <iostream>
#include <unistd.h>

void test_atomicInt_add(atomic_Int &x)
{
    for (int i = 0; i < 10; i++)
    {
        // x.fetch_add(1);
        int oldValue, newValue = 0;
        do
        {
            oldValue = x.load();
            newValue = oldValue + 1;
        } while (!x.compare_exchange_strong(oldValue, newValue));
        sleep(1);

        std::cout << "test_atomicInt_add: " << newValue << std::endl;
    }
}

void test_atomicInt_sub(atomic_Int &x)
{
    for (int i = 0; i < 10; i++)
    {
        // x.fetch_sub(1);
        int oldValue, newValue = 0;
        do
        {
            oldValue = x.load();
            newValue = oldValue - 1;
        } while (!x.compare_exchange_strong(oldValue, newValue));
        sleep(1);
        std::cout << "test_atomicInt_sub: " << newValue << std::endl;
    }
}

bool OptimisticLock::update(std::string new_data, int expected_version)
{
    if (version.compare_exchange_strong(expected_version, expected_version + 1))
    {
        data = new_data;
        return true;
    }
    return false;
}

std::string OptimisticLock::get_data() const
{
    return data;
}

int OptimisticLock::get_version() const
{
    return version.load();
}

#ifndef C12C4EA0_6242_4E49_A399_F950F08F5373
#define C12C4EA0_6242_4E49_A399_F950F08F5373
#include <atomic>
#include <string>

using atomic_Int = std::atomic<int>;
void test_atomicInt_add(atomic_Int &x);
void test_atomicInt_sub(atomic_Int &x);

class OptimisticLock
{
public:
    OptimisticLock(std::string new_data) : data(new_data), version(0) {}
    bool update(std::string new_data, int expected_version);
    std::string get_data() const;
    int get_version() const;

private:
    std::string data;
    atomic_Int version;
};

#endif /* C12C4EA0_6242_4E49_A399_F950F08F5373 */

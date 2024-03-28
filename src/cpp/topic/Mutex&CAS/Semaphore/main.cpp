#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "semaphore.h"

void worker1(sem_t *semaphore)
{
    sem_wait(semaphore);
    std::cout << "worker1 " << std::this_thread::get_id() << " acquired semaphore" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void worker2(sem_t *semaphore)
{
    std::cout << "worker2 " << std::this_thread::get_id() << " acquired semaphore" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    sem_post(semaphore);
}

int main()
{
    sem_t semaphore;
    sem_init(&semaphore, 0, 1); // initialize semaphore with value 1
    sem_wait(&semaphore);       // acquire the semaphore

    // create two threads and pass the semaphore as argument
    std::thread t1(worker1, &semaphore);
    std::thread t2(worker2, &semaphore);

    t1.join();
    t2.join();
    sem_destroy(&semaphore);
    return 0;
}
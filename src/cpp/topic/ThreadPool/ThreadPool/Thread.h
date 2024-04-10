#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include <functional>
#include "ThreadPool.h"
class ThreadInf
{
public:
    virtual ~ThreadInf() {}
    virtual void run() = 0;
};


class Thread : public ThreadInf
{
public:
    Thread(ThreadPool* threadPool);
    virtual ~Thread();

    virtual void run();

private:
    ThreadPool* m_pThreadPool;
    std::thread* m_pThread;
};

#endif // THREAD_H
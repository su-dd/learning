#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <vector>
#include <thread>
#include <condition_variable>
#include "Task.h"

class ThreadPool {
public:
    ThreadPool(int threadSize = 0);
    ~ThreadPool();
    void addTask(TaskInf* task);
    void waitUntilDone();

private:
    void setDefaultThreadSize(); // 设置默认最大线程数

private:
    std::vector<std::thread> m_threads;
    SafeTaskQueue m_tasks;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    bool m_done;
    int m_ThreadSize;    // 最大线程数

private:
	class ThreadWorker
	{
	public:
		ThreadWorker(ThreadPool* threadPool) : m_pThreadPool(threadPool) {}
		~ThreadWorker() { m_pThreadPool = nullptr; }

		void operator()()
		{
			while (true)
			{
				TaskInf* task = m_pThreadPool->m_tasks.take();
				if (nullptr != task)
				{
					task->run();
					delete task;
					task = nullptr;
				}
				else
				{

				}
			}
		}

	private:
		ThreadPool* m_pThreadPool;
	};

};

#endif // THREAD_POOL_H
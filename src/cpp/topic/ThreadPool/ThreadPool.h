#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <vector>
#include <thread>
#include <condition_variable>
#include <queue>
#include <mutex>
#include <future>
#include <functional>
#include <iostream>

template <typename T>
class SafeQueue
{
public:
	bool empty()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_oQueue.empty();
	}

	int size()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		std::cout << "Queue size is : " << m_oQueue.size() << std::endl;
		return m_oQueue.size();
	}

	void add(T &task)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		m_oQueue.emplace(task);
	}

	bool take(T &t)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_oQueue.empty())
		{
			return false;
		}
		t = m_oQueue.front(); // 移动元素到t中
		m_oQueue.pop();
		return true;
	}

private:
	std::queue<T> m_oQueue;
	std::mutex m_mutex;
};

using Task = std::function<void()>;
class ThreadPool
{
	// 线程工作者
	class ThreadWorker
	{
	public:
		ThreadWorker(ThreadPool *threadPool) : m_pThreadPool(threadPool) {}
		~ThreadWorker() { m_pThreadPool = nullptr; }

		void operator()()
		{
			std::cout << "Thread " << std::this_thread::get_id() << " ready to work." << std::endl;
			Task task;				// 定义任务函数
			bool isGetTask = false; // 定义是否获取任务的标志

			while (true)
			{
				if (m_pThreadPool->m_done && m_pThreadPool->m_tasks.empty()) // 线程池完成
				{
					break;
				}

				{
					std::unique_lock<std::mutex> lock(m_pThreadPool->m_mutex);
					if (m_pThreadPool->m_tasks.empty()) // 任务队列为空
					{
						m_pThreadPool->m_cv.wait(lock); // 等待条件变量通知
					}
					isGetTask = m_pThreadPool->m_tasks.take(task);
				}

				if (isGetTask)
				{
					std::cout << "Thread " << std::this_thread::get_id() << " get work." << std::endl;
					isGetTask = false; // 重置获取任务标志
					task();			   // 执行任务
				}
			}
		}

	private:
		ThreadPool *m_pThreadPool;
	};

public:
	ThreadPool(int threadSize = 0) : m_ThreadSize(threadSize), m_done(false)
	{
		if (m_ThreadSize <= 0)
		{
			setDefaultThreadSize();
		}
		for (int i = 0; i < m_ThreadSize; i++)
		{
			m_threads.emplace_back(std::thread(ThreadWorker(this))); // 创建线程
		}
	};
	~ThreadPool(){};

	template <typename F, typename... Args>
	auto addTask(F &&f, Args &&...args) -> std::shared_future<decltype(f(args...))> // 添加任务
	{
		// 创建任务包裹
		std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
		auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

		// 包裹任务
		Task task = [task_ptr]() -> void
		{
			(*task_ptr)();
		};
		m_tasks.add(task);
		m_cv.notify_one();			   // 通知线程池有任务
		return task_ptr->get_future(); // 返回future
	}

	void wait()
	{
		m_done = true;
		m_cv.notify_all(); // 通知，唤醒所有工作线程
		for (int i = 0; i < m_ThreadSize; i++)
		{
			if (m_threads.at(i).joinable()) // 判断线程是否在等待状态
			{
				pthread_join
					m_threads.at(i);
				m_threads.at(i).join(); // 将线程加入等待队列
			}
		}
	}

private:
	// 设置默认最大线程数
	void setDefaultThreadSize()
	{
		// 获取硬件线程数
		m_ThreadSize = std::thread::hardware_concurrency();
		// 若获取失败，则设置为1
		if (m_ThreadSize <= 0)
		{
			m_ThreadSize = 1;
		}
	}

private:
	std::vector<std::thread> m_threads; // 线程池
	SafeQueue<Task> m_tasks;			// 任务队列
	std::mutex m_mutex;
	std::condition_variable m_cv;
	bool m_done;
	int m_ThreadSize; // 最大线程数
};

#endif // THREAD_POOL_H
#include "ThreadPool.h"



ThreadPool::ThreadPool(int threadSize)
	: m_ThreadSize(threadSize)
	, m_done(false)
{
	if (0 == m_ThreadSize)
	{
		setDefaultThreadSize();
	}
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::addTask(TaskInf* task)
{
	m_done = false;
	m_tasks.add(task);
}

void ThreadPool::waitUntilDone()
{

}

void ThreadPool::setDefaultThreadSize()
{
	m_ThreadSize = 8;
}

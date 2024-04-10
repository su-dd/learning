#include "Thread.h"

Thread::Thread(ThreadPool* threadPool)
	: m_pThreadPool(threadPool)
	, m_pThread(nullptr)
{
}

Thread::~Thread()
{
	m_pThreadPool = nullptr;
	delete m_pThread;
	m_pThread = nullptr;
}

void Thread::run()
{
	m_pThread = 
}

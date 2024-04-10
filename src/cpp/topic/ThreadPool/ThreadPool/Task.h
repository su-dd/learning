#ifndef Task_h
#define Task_h
#include <queue>
#include <mutex>
#include <functional>
class TaskInf
{
public:
    virtual ~TaskInf() {}
    virtual void run() = 0;
};

class SafeTaskQueue
{
public:
    int size()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_tasks.size();
    }

    void add(TaskInf* task)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_tasks.emplace(task);
    }

    TaskInf* take()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (!m_tasks.empty())
        {
            return nullptr;
        }
        TaskInf* task = m_tasks.front();
        m_tasks.pop();
        return task;
    }
private:
    std::queue<TaskInf*> m_tasks;
    std::mutex m_mutex;
};

class Task : public TaskInf         
{
public:
    Task(std::function<void()> fun) : m_Fun(fun) {}
    void run() { m_Fun(); }
private:
    std::function<void()> m_Fun;
};

#endif // !

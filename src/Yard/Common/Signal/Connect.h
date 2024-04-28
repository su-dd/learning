#ifndef CONNECT_H
#define CONNECT_H

#include <vector>
#include <memory>
#include <functional>
#include <stdarg.h>
#include <string>
#include <map>

namespace Common_Connect {
// 槽，被调用者，需要解释参数，并执行
template<typename... Args>
class Slot
{
public:
    using OnFunc = std::function<void(Args &&...)>;

    Slot(const OnFunc& func)
        : m_func(func){}

    void exec(Args &&... args)
    {
        m_func(std::forward<Args>(args)...);
    }

    std::string getKey() { return m_sKey; }
    void setKey(std::string key) { m_sKey = key; }

private:
    OnFunc m_func = nullptr;
    std::string m_sKey;
};


// 信号，调用者 需要携带参数，并传递参数
template<typename... Args>
class Signal
{
public:
    using SlotPtr = std::shared_ptr<Slot<Args&& ...>>;
    using OnFunc = std::function<void(Args&& ...)>;

    void bind(const OnFunc& func)
    {
        m_slotVec.push_back(SlotPtr(new Slot<Args&& ...>(func)));
    }

    void operator()(Args&& ...args)
    {
        for (auto& iter : m_slotVec)
        {
            iter->exec(std::forward<Args>(args)...);
        }
    }

private:
    std::vector<SlotPtr> m_slotVec;
};

class Connect
{
public:
    Connect();

private:

};

}

#endif // CONNECT_H

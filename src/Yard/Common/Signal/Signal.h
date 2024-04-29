#ifndef CONNECT_H
#define CONNECT_H

#include <vector>
#include <memory>
#include <functional>
#include <stdarg.h>
#include <string>
#include <map>

#define emit
#define slots
#define signals public
#define connect(sender, signal, slot) ((sender)->signal.bind(slot))
namespace CommonSignal {

using OnFunc = std::function<void(Args &&...)>;
// 槽，被调用者，需要解释参数，并执行
template<typename... Args>
class Slot
{
public:
    Slot(const OnFunc& func)
        : m_func(func){}

    void exec(Args &&... args)
    {
        m_func(std::forward<Args>(args)...);
    }
private:
    OnFunc m_func = nullptr;
    std::string m_sKey;
};
using SlotPtr = std::shared_ptr<Slot<Args&& ...>>;

// 信号，调用者 需要携带参数，并传递参数
template<typename... Args>
class Signal
{
public:
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

// 基于信号槽的注册扩展
class Plugin
{
public:
    static Plugin *getInstance()
    {
        return &m_pInstance;
    }

private:
    static Plugin m_pInstance;
    std::map<std::string, SlotPtr> m_oSlotMap;
};
// 初始化静态变量
Plugin Plugin::m_pInstance;

static void registerPlugin(std::string key, const OnFunc& func)
{

}

template<typename... Args>
static void runPlugin(std::string key, Args&&...args)
{

}
}

#endif // CONNECT_H

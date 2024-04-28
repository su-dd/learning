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

// �ۣ��������ߣ���Ҫ���Ͳ�������ִ��
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
private:
    OnFunc m_func = nullptr;
    std::string m_sKey;
};


// �źţ������� ��ҪЯ�������������ݲ���
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
}

#endif // CONNECT_H

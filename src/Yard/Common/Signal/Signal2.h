#ifndef SIGNAL2_H
#define SIGNAL2_H
#include <list>

using fnptr = unsigned int;

template<typename ...A>
using gfnptr = void (*)(A...);

template<typename T, typename ...A>
using mfnptr = void (T::*)(A...);

template<class... A>
class ConnectionBase
{
public:
    ConnectionBase(fnptr func)
        :m_callfunc(func), m_block(false) {}
    virtual void run(A... args) = 0;
    template<class... A> friend class Signal;
protected:
    fnptr m_callfunc;
    bool m_block;
};

template<class T, class... A>
class Connection : public ConnectionBase<A...>
{
public:
    Connection(T* obj, mfnptr<T, A...> memfunc)
        :ConnectionBase<A...>(*reinterpret_cast<fnptr*>(&memfunc)), m_obj(obj) {}

    virtual void run(A... args)
    {
        if (!ConnectionBase<A...>::m_block)
        {
            mfnptr<T, A...> ptr = *(reinterpret_cast<mfnptr<T, A...>*>(&(ConnectionBase<A...>::m_callfunc)));
            (m_obj->*ptr)(args...);
        }
    }
    template<class... A> friend class Signal;
protected:
    T* m_obj;
};

template<class... A>
class ConnectionFunc : public ConnectionBase<A...>
{
public:
    ConnectionFunc(gfnptr<A...> func)
        :ConnectionBase<A...>(reinterpret_cast<fnptr>(func)) {}

    virtual void run(A... args)
    {
        if (!ConnectionBase<A...>::m_block)
            reinterpret_cast<gfnptr<A...>>(ConnectionBase<A...>::m_callfunc)(args...);
    }
};

template<class... A>
class Signal
{
public:
    void connect(gfnptr<A...> func)
    {
        std::shared_ptr<ConnectionFunc<A...>> f(new ConnectionFunc<A...>(func));
        m_slots.push_back(f);
    }

    template<class T>
    void connect(T* obj, mfnptr<T, A...> memfunc)
    {
        std::shared_ptr<Connection<T, A...>> mf(new Connection<T, A...>(obj, memfunc));
        m_slots.push_back(mf);
    }

    void disconnect(gfnptr<A...> func)
    {
        for (auto iter = m_slots.begin(); iter != m_slots.end();)
        {
            if (reinterpret_cast<gfnptr<A...>>((*iter)->ConnectionBase<A...>::m_callfunc) == func)
                m_slots.erase(iter++);
            else
                ++iter;
        }
    }

    template<class T>
    void disconnect(T* obj, mfnptr<T, A...> memfunc)
    {
        for (auto iter = m_slots.begin(); iter != m_slots.end();)
        {
            Connection<T, A...>* conn = reinterpret_cast<Connection<T, A...>*>(iter->get());
            if (conn->m_obj == obj and conn->m_callfunc == *(reinterpret_cast<fnptr*>(&memfunc)))
                m_slots.erase(iter++);
            else
                ++iter;
        }
    }

    void blockSignal(gfnptr<A...> func, bool block)
    {
        for (auto iter = m_slots.begin(); iter != m_slots.end(); ++iter)
        {
            ConnectionFunc<A...>* conn = reinterpret_cast<ConnectionFunc<A...>*>(iter->get());
            if (conn->m_callfunc == *(reinterpret_cast<fnptr*>(&func)))
                conn->m_block = block;
        }
    }

    template<class T>
    void blockSignal(T* obj, mfnptr<T, A...> memfunc, bool block)
    {
        for (auto iter = m_slots.begin(); iter != m_slots.end();++iter)
        {
            Connection<T, A...>* conn = reinterpret_cast<Connection<T, A...>*>(iter->get());
            if (conn->m_obj == obj and conn->m_callfunc == *(reinterpret_cast<fnptr*>(&memfunc)))
                conn->m_block = block;
        }
    }

    void emit(A... args)
    {
        for (auto connBase: m_slots)
        {
            connBase->run(args...);
        }
    }
private:
    std::list<std::shared_ptr<ConnectionBase<A...>>> m_slots;
};

#endif // SIGNAL2_H

#ifndef CareTaker_H
#define CareTaker_H
#include "Memento.h"
#include <vector>
using namespace std;
class CareTaker
{
public:
    CareTaker() {}
    ~CareTaker()
    {
        for (auto oIterator = m_oMementos.begin(); oIterator != m_oMementos.end(); ++oIterator)
        {
            delete *oIterator;
        }
        m_oMementos.clear();
    }

    void add(Memento *memento) { this->m_oMementos.push_back(memento); }
    Memento *pop()
    {
        Memento *memento = this->m_oMementos.back();
        this->m_oMementos.pop_back();
        return memento;
    }

private:
    vector<Memento *> m_oMementos;
};

#endif // !CareTaker_H

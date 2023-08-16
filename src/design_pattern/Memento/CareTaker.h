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

	void add(Memento* memento) { this->m_oMementos.push_back(memento); }
	Memento* get(int index) { return this->m_oMementos[index]; }

private:
	vector<Memento*> m_oMementos;
};

#endif // !CareTaker_H

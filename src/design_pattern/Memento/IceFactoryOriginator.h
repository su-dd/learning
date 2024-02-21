#ifndef Originator_H
#define Originator_H
#include "IceCream.h"
#include "Memento.h"
using namespace std;
// Originator 原发器：负责创建备忘录，并提供恢复备忘录的接口
// 原发器类，同时也是业务的载体
class IceFactoryOriginator
{
public:
	IceFactoryOriginator()
		: m_sflavour(""), m_sDryFruit("") {}

	void setFlavour(string flavour)
	{
		this->m_sflavour = flavour;
	}

	void setDryFruit(string dryFruit)
	{
		this->m_sDryFruit = dryFruit;
	}

	IceCream *createCream() // 业务代码
	{
		IceCream *pIceCream = new IceCream(m_sflavour, m_sDryFruit);
		return pIceCream;
	}

	Memento *createMemento()
	{
		return new Memento(m_sflavour, m_sDryFruit);
	}

	void restoreMemento(Memento *memento)
	{
		m_sflavour = memento->getFlavour();
		m_sDryFruit = memento->getDryFruit();
	}

private:
	string m_sflavour;
	string m_sDryFruit;
};

#endif // !Originator_H

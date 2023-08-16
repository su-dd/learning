#ifndef IceCreamState_H
#define IceCreamState_H

#include "State.h"
#include <iostream>
using namespace std;

class IceCreamState : public State
{
public:
	IceCreamState()
		: State()
	{}

	virtual ~IceCreamState() {}

	virtual void doPackage() override
	{
		cout << "包装为 普通冰淇淋！" << endl;
	}
};

#endif // !IceCreamState_H
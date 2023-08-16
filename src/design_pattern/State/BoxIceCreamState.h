#ifndef BoxIceCreamState_H
#define BoxIceCreamState_H

#include "State.h"
#include <iostream>
using namespace std;

class BoxIceCreamState : public State
{
public:
	BoxIceCreamState()
		: State()
	{}

	virtual ~BoxIceCreamState() {}

	virtual void doPackage() override
	{
		cout << "包装为 普通冰淇淋！" << endl;
	}
};

#endif // !BoxIceCreamState_H

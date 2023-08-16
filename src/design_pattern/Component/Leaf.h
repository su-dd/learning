#ifndef LEAF_H
#define LEAF_H
#include "Component.h"
#include <iostream>

using namespace std;

class Leaf : public Component
{
public:
	explicit Leaf(string key) : Component(key) {}
public:
	int buy(int num)
	{
		cout << m_sKey << "购买了" << num << "根雪糕！" << endl;
		return 0;
	}

	int needNum()
	{
		return 1;
	}
};


#endif // LEAF_H
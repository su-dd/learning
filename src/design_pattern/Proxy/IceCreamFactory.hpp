#ifndef IceCreamFactory_H
#define IceCreamFactory_H

#include "IceCreamFactoryIntf.h"
#include <iostream>
using namespace std;

class IceCreamFactory : public IceCreamFactoryIntf
{
public:
	IceCreamFactory() {}
	virtual ~IceCreamFactory() {}

	virtual void getIceCream()
	{
		cout << "《冰淇淋》！" << endl;
	}
};

#endif
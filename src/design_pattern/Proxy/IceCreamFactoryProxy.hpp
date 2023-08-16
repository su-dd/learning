#ifndef IceCreamFactoryProxy_H
#define IceCreamFactoryProxy_H

#include "IceCreamFactoryIntf.h"
#include "IceCreamFactory.hpp"
#include <iostream>
using namespace std;

class IceCreamFactoryProxy : public IceCreamFactoryIntf
{
public:
	IceCreamFactoryProxy() {}
	virtual ~IceCreamFactoryProxy() {}

	virtual void getIceCream()
	{
		cout << "加价" << endl;
		m_oFactory.getIceCream();
	}

private:
	IceCreamFactory m_oFactory;
};

#endif
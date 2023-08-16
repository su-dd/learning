#include <iostream>
#include "IceCreamFactoryProxy.hpp"
using namespace std;

int main()
{
	IceCreamFactoryIntf *p = new IceCreamFactoryProxy();
	p->getIceCream();

	delete p;
	return 0;
}

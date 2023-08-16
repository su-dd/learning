#ifndef IceCreamFactoryIntf_H
#define IceCreamFactoryIntf_H

class IceCreamFactoryIntf
{
public:
	virtual ~IceCreamFactoryIntf() {}

	virtual void getIceCream() = 0;
};

#endif
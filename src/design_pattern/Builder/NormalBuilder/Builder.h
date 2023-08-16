#ifndef Builder_H
#define Builder_H

#include <string>
#include "IceCreamCake.h"

class Builder
{
public:
	Builder(string cakeBillet, string IceCream)
		: m_pIceCreamCake(new IceCreamCake(cakeBillet, IceCream))
	{
	}

	virtual ~Builder() 
	{
		delete m_pIceCreamCake;
		m_pIceCreamCake = nullptr;
	}

	IceCreamCake* getProduct()
	{
		return m_pIceCreamCake;
	}

	virtual void setFruit() {}
	virtual void setChocolate() {}
	virtual void setDecoration() {}
	
protected:
	IceCreamCake* m_pIceCreamCake;
};

#endif // !Builder_H
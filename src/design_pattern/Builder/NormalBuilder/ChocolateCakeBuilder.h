#ifndef ChocolateCakeBuilder_H
#define ChocolateCakeBuilder_H

#include "Builder.h"
#include <string>

class ChocolateCakeBuilder : public Builder
{
public:
	ChocolateCakeBuilder(string cakeBillet, string IceCream)
		: Builder(cakeBillet, IceCream)
	{
	}

	virtual ~ChocolateCakeBuilder()
	{
	}

	virtual void setChocolate()override
	{
		m_pIceCreamCake->setChocolate("巧克力");
	}
};

#endif // !ChocolateCakeBuilder_H

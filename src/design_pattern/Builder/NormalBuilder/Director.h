#ifndef Director_H
#define Director_H

#include "Builder.h"

class Director
{
public:
	Director(Builder *builder)
		: m_pBuilder(builder)
	{
	}

	void makeCake()
	{
		m_pBuilder->setFruit();
		m_pBuilder->setChocolate();
		m_pBuilder->setDecoration();
	}

private:
	Builder* m_pBuilder;
};

#endif // !Director_H

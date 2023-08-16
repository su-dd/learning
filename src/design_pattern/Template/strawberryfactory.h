#ifndef STRAWBERRYFACTORY_H
#define STRAWBERRYFACTORY_H

#include "factorytemplate.h"

class StrawberryFactory : public FactoryTemplate
{
public:
    virtual ~StrawberryFactory() {}
protected:
    virtual void createIceBall(IceCream &iceCream)
    {
        iceCream.setIceBall("草莓");
    }
};
#endif // STRAWBERRYFACTORY_H

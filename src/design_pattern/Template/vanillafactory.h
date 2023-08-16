#ifndef VANILLAFACTORY_H
#define VANILLAFACTORY_H

#include "factorytemplate.h"

class VanillaFactory : public FactoryTemplate
{
public:
    virtual ~VanillaFactory() {}
protected:
    virtual void createIceBall(IceCream &iceCream)
    {
        iceCream.setIceBall("香草");
    }
};

#endif // VANILLAFACTORY_H

#ifndef FACTORYINTERFACE_H
#define FACTORYINTERFACE_H

#include "IceCreamInterface.h"
#include "ChipsInterface.h"
class FactoryInterface
{
public:
    virtual ~FactoryInterface() {}
    virtual IceCreamInterface *createIceCream() = 0;
    virtual ChipsInterface* createChips() = 0;
};



#endif // FACTORYINTERFACE_H

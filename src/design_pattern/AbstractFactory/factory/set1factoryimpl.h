#ifndef SET1FACTORYIMPL_H
#define SET1FACTORYIMPL_H

#include "factoryinterface.h"
#include "BigChipsImpl.h"
#include "StrawberryIceCreamImpl.hpp"

class Set1FactoryImpl : public FactoryInterface
{
public:
     virtual IceCreamInterface *createIceCream()
     {
         return new StrawberryIceCreamImpl();
     }

     virtual ChipsInterface* createChips()
     {
         return new BigChipsImpl();
     }
};
#endif // SET1FACTORYIMPL_H

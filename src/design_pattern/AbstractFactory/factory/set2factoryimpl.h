#ifndef SET2FACTORYIMPL_H
#define SET2FACTORYIMPL_H

#include "factoryinterface.h"
#include "LittleChipsImpl.h"
#include "VanillaIceCreamImpl.hpp"

class Set2FactoryImpl : public FactoryInterface
{
public:
     virtual IceCreamInterface *createIceCream()
     {
         return new VanillaIceCreamImpl();
     }

     virtual ChipsInterface* createChips()
     {
         return new LittleChipsImpl();
     }
};
#endif // SET2FACTORYIMPL_H

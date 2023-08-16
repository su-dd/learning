#ifndef FACTORYPRODUCER_H
#define FACTORYPRODUCER_H

#include "factoryinterface.h"
#include "set1factoryimpl.h"
#include "set2factoryimpl.h"

class FactoryProducer
{
public:
    enum Set
    {
        Set1,
        Set2
    };

public:
    FactoryInterface * createSet(Set setNum)
    {
        switch (setNum) {
        case Set1:
            return new Set1FactoryImpl();
        case Set2:
            return new Set2FactoryImpl();
        default:
            return nullptr;
        }
    }
};
#endif // FACTORYPRODUCER_H

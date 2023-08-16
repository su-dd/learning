#ifndef IceCreamDecorator_h
#define IceCreamDecorator_h

#include "IceCreamInterface.h"
#include <iostream>
class IceCreamDecorator : public IceCreamInterface
{
public:
    IceCreamDecorator(IceCreamInterface *iceCream)
        : m_pIceCream(iceCream)
    {
    }
    virtual ~IceCreamDecorator()
    {
        delete m_pIceCream;
    }

    virtual void taste() override
    {
        if (m_pIceCream)
        {
            m_pIceCream->taste();
        }
    }

private:
    IceCreamInterface *m_pIceCream;
};

#endif
#ifndef IceCreamIntf_H
#define IceCreamIntf_H
#include "BrandIntf.h"
class IceCreamIntf
{
public:
    virtual ~IceCreamIntf() {}
    virtual void taste() = 0;
    virtual void setBrand(BrandIntf *brand) = 0;
};

#endif
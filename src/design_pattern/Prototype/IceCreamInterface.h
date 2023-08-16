#ifndef IceCreamInterface_H
#define IceCreamInterface_H

// 冰淇淋接口
class IceCreamInterface
{
public:
    virtual ~IceCreamInterface() {}
    virtual void taste() = 0;
    virtual IceCreamInterface *clone() = 0;
};

#endif // IceCreamInterface_H

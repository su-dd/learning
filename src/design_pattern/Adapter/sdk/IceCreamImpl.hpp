#ifndef IceCreamImpl_H
#define IceCreamImpl_H
#include "IceCreamIntf.h"
#include "BrandIntf.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class IceCreamImpl : public IceCreamIntf
{
public:
    IceCreamImpl() : m_pBrand(nullptr) {}
    virtual ~IceCreamImpl()
    {
        delete m_pBrand;
    }

    virtual void taste() override
    {
        m_pBrand->logo();
    }

    virtual void setBrand(BrandIntf *brand) override
    {
        if (m_pBrand == brand)
            return;
        if (nullptr != m_pBrand)
            delete m_pBrand;
        m_pBrand = brand;
    }

private:
    BrandIntf *m_pBrand;
};

class StrawberryIceCreamImpl : public IceCreamImpl
{
public:
    virtual void taste() override
    {
        IceCreamImpl::taste();
        cout << "草莓冰淇淋！" << endl;
    }
};

class VanillaIceCreamImpl : public IceCreamImpl
{
public:
    virtual void taste() override
    {
        IceCreamImpl::taste();
        cout << "香草冰淇淋！" << endl;
    }
};

#endif
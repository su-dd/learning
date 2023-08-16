#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>

class IceCream
{
public:
    void taste()
    {
        std::cout << m_sflavour + "IceCream" << std::endl;
    }

protected:
    void setCone()
    {
        return;
    }

    void setIceBall(const std::string & str)
    {
        m_sflavour = str;
    }

private:
    std::string m_sflavour;

    friend class FactoryTemplate;
    friend class StrawberryFactory;
    friend class VanillaFactory;
};
#endif // ICECREAM_H

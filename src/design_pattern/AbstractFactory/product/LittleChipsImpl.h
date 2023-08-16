#ifndef LITTLECHIPSIMPL_H
#define LITTLECHIPSIMPL_H

#include "ChipsInterface.h"
#include <iostream>

class LittleChipsImpl : public ChipsInterface
{
public:
    virtual void size()
    {
        std::cout << "这个小份的薯条！" << std::endl;
    }
};

#endif // LITTLECHIPSIMPL_H

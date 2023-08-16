#ifndef IceCreamFacadeClassAdapter_H
#define IceCreamFacadeClassAdapter_H

#include "sdk/IceCreamFacade.hpp"

class IceCreamFacadeClassAdapter : public IceCreamFacade
{
public:
	IceCreamIntf* createIceCream(Taste taste)
	{
		return IceCreamFacade::createIceCream(taste, Brand::A);
	}
};

#endif // !IceCreamFacadeClassAdapter_H

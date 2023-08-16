#include <iostream>
#include "IceCreamFacadeClassAdapter.h"
#include "IceCreamFacadeObjectAdapter.h"
#include "IceCreamIntf.h"

int main(int argc, char* argv[])
{
	IceCreamIntf* pIceCream = nullptr;

	IceCreamFacadeClassAdapter oClassAdapter;
	pIceCream = oClassAdapter.createIceCream(Taste::Strawberry);
	pIceCream->taste();
	delete pIceCream;

	IceCreamFacadeObjectAdapter oObjectAdapter;
	pIceCream = oObjectAdapter.createIceCream(Taste::Vanilla);
	pIceCream->taste();
	delete pIceCream;

	return 0;
}
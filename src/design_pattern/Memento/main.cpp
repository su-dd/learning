#include <iostream>
#include "CareTaker.h"
#include "IceCream.h"
#include "IceFactoryOriginator.h"
#include "Memento.h"

using namespace std;

int main(int argc, char* argv[])
{
	IceFactoryOriginator oIceFactoryOriginator;
	IceCream* pIceCream = nullptr;
	CareTaker oCareTaker;

	// 添加备忘录
	oIceFactoryOriginator.setDryFruit(string("冻草莓"));
	oIceFactoryOriginator.setFlavour(string("草莓"));
	pIceCream = oIceFactoryOriginator.createCream();
	pIceCream->taste();
	oCareTaker.add(oIceFactoryOriginator.createMemento());
	delete pIceCream;

	oIceFactoryOriginator.setDryFruit(string("榛子"));
	oIceFactoryOriginator.setFlavour(string("香草"));
	pIceCream = oIceFactoryOriginator.createCream();
	pIceCream->taste();
	oCareTaker.add(oIceFactoryOriginator.createMemento());
	delete pIceCream;

	// 使用备忘录
	cout << "*********使用备忘录*********" << endl;

	oIceFactoryOriginator.restoreMemento(oCareTaker.get(0));
	pIceCream = oIceFactoryOriginator.createCream();
	pIceCream->taste();
	delete pIceCream;

	oIceFactoryOriginator.restoreMemento(oCareTaker.get(1));
	pIceCream = oIceFactoryOriginator.createCream();
	pIceCream->taste();
	delete pIceCream;
	
	return 0;
}
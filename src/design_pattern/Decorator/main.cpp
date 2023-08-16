// CMakeProject.cpp: 定义应用程序的入口点。

#include <iostream>
#include "StrawberryIceCreamImpl.h"
#include "NutIceCreamDecorator.h"

int main()
{
	StrawberryIceCreamImpl().taste();
	NutIceCreamDecorator(new StrawberryIceCreamImpl()).taste();
	return 0;
}

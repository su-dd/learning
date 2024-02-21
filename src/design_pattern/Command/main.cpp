#include <iostream>
#include "IceCream.h"
#include "IceFactoryReceiver.h"
#include "Command.h"
#include "Invoker.h"
#include "StrawberryCommand.h"
#include "VanillalceCommand.h"
using namespace std;

int main(int argc, char *argv[])
{
	Invoker oInvoker;						//  发生命令
	IceFactoryReceiver oIceFactoryReceiver; // 接收命令

	//  创建命令并设置接收者
	StrawberryCommand oStrawberryCommand(&oIceFactoryReceiver);

	//  设置命令并执行
	oInvoker.setCommand(&oStrawberryCommand);
	oInvoker.executeCommand();

	// 接收者执行
	IceCream oStrawberryIceCream = oIceFactoryReceiver.createCream();
	oStrawberryIceCream.taste();

	VanillalceCommand oVanillalceCommand(&oIceFactoryReceiver);
	oInvoker.setCommand(&oVanillalceCommand);
	oInvoker.executeCommand();
	IceCream oVanillalceIceCream = oIceFactoryReceiver.createCream();
	oVanillalceIceCream.taste();
	return 0;
}
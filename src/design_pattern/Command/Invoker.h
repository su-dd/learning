#ifndef Invoker_H
#define Invoker_H

/*****************************************************************************************
* 
* 发送者 （Sender）——亦称 “触发者 （Invok­er）” 负责对请求进行初始化， 
* 
* 其中必须包含一个成员变量来存储对于命令对象的引用。 
* 
* 发送者触发命令， 而不向接收者直接发送请求。
* 
* 注意， 发送者并不负责创建命令对象： 它通常会通过构造函数从客户端处获得预先生成的命令。
* 
******************************************************************************************/

#include "Command.h"
class Invoker
{
public:
	Invoker() : m_pCommand(nullptr) {}
	~Invoker() {}

	void setCommand(Command *command)
	{
		m_pCommand = command;
	}

	void executeCommand()
	{
		m_pCommand->execute();
	}

private:
	Command * m_pCommand;
};

#endif // !Invoker_H
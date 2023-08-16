#ifndef Command_H
#define Command_H
/******************************************************
* 
* 命令 （Com­mand） 接口通常仅声明一个执行命令的方法。
* 
*******************************************************/
class Command
{
public:
	~Command() {}
	virtual void execute() = 0;
};

#endif // !Command_H
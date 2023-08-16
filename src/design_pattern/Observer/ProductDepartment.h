#ifndef ProductDepartment_H
#define ProductDepartment_H
#include "AddObServer.h"
#include <iostream>
using namespace std;
class ProductDepartment : public AddObServer
{
public:
	ProductDepartment()
		: AddObServer() {}

	~ProductDepartment() {}

	virtual void doAdd(int number) override
	{
		cout << "生产部门：准备生产 " << number << " 根冰棍。" << endl;
	}
};
#endif // !ProductDepartment_H

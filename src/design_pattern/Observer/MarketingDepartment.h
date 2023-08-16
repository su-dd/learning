#ifndef MarketingDepartment_H
#define MarketingDepartment_H
#include "Subject.h"
#include "AddObServer.h"
#include <iostream>
using namespace std;
class MarketingDepartment : public Subject
{
public:
	MarketingDepartment()
		: Subject() {}

	~ MarketingDepartment() {}

	void sell(int number)
	{
		cout << "市场部买了 " << number << " 根冰棍！" << endl;
		for (auto var : m_oAddObServer)
		{
			var->doAdd(number);
		}
	}
};
#endif // !MarketingDepartment_Hc
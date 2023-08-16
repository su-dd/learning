#ifndef ERPMediator_H
#define ERPMediator_H
#include "Mediator.h"

#include "Collegue.h"
#include <list>

using namespace std;

class ERPMediator : public Mediator
{
public:
	virtual void regist(Collegue* collegue) override
	{
		m_oCollegues.push_back(collegue);
	}

	virtual void sendMessage(string message, Collegue* collegue) override
	{
		for each (auto var in m_oCollegues)
		{
			if (var != collegue)
			{
				var->getMessage(message);
			}
		}
	}

private:
	list<Collegue*> m_oCollegues;
};
#endif // !ERPMediator_H

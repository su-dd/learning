#ifndef Subject_H
#define Subject_H
#include "AddObServer.h"
#include <list>
using namespace std;
class Subject
{
public:
	Subject() {}
	~Subject() {}
	
	void addObServer(AddObServer* observer)
	{
		m_oAddObServer.push_back(observer);
	}

	void removeObServer(AddObServer* observer)
	{
		m_oAddObServer.remove(observer);
	}

protected:
	list<AddObServer*> m_oAddObServer;
};
#endif // !Subject_H
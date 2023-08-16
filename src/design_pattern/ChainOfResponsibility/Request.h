#ifndef REQUEST_H
#define REQUEST_H
#include <string>
using namespace std;
enum RequestType
{
	retaile = 0,
	dealer = 1,
	factory = 2
};

class Request
{
public:
	Request(RequestType type, string message)
		: m_Type(type)
		, m_sMessage(message)
	{

	}

	RequestType getType()
	{
		return m_Type;
	}

	string getMessage()
	{
		return m_sMessage;
	}

private:
	RequestType m_Type;
	string m_sMessage;
};


#endif // !REQUEST_H

#ifndef Context_H
#define Context_H
#include <string>
#include <map>
using namespace std;

class Context
{
public:
	void assign(string key, string value)
	{
		m_oContextMap.insert({ key, value });           
	}

	string lookup(string key)
	{
		return m_oContextMap.at(key);
	}

protected:
	map<string, string> m_oContextMap;
};

#endif // Context_H
#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Component
{
public:
	explicit Component(string key) : m_sKey(key) , m_pParent(nullptr) {}
	virtual ~Component() {}
public:
	virtual void add(string key, Component* component) {}
	virtual void remove(string key) {}
	virtual Component* getParent(){ return m_pParent; }
	virtual void setParent(Component* component) { m_pParent = component; }
	virtual Component* getChild() { return nullptr; }
	virtual void refresh() {}
public:
	virtual int buy(int num) { return 0; }
	virtual int needNum() { return 0;  }

protected:
	string m_sKey;
	Component* m_pParent;
};

#endif // COMPONENT_H
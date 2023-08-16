#ifndef State_H
#define State_H

class State
{
public:
	virtual ~State() {}

	virtual void doPackage() = 0;
};
#endif // !State_H
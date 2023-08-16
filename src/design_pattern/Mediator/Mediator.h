#ifndef Mediator_H
#define Mediator_H
#include <string>
using namespace std;
class Collegue;
class Mediator
{
public:
	virtual ~Mediator() {}
	virtual void regist(Collegue* collegue) = 0;
	virtual void sendMessage(string message, Collegue* collegue) = 0;
};

#endif // !Mediator_H

#ifndef Memento_H
#define Memento_H
using namespace std;
class Memento
{
public:
	Memento(string flavour, string dryFruit)
		: m_sflavour(flavour)
		, m_sDryFruit(dryFruit) {}
	string getFlavour() { return m_sflavour; }
	string getDryFruit() { return m_sDryFruit; }
private:
	string m_sflavour;
	string m_sDryFruit;
};

#endif // !Memento_H

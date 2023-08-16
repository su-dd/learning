#ifndef IceCream_H
#define IceCream_H
#include <iostream>
using namespace std;

class IceCream
{
public:
	IceCream(string flavour, string dryFruit)
		: m_sflavour(flavour)
		, m_sDryFruit(dryFruit)
	{
	}

	void taste()
	{
		cout << "加了" + m_sDryFruit + "的" + m_sflavour + "冰淇淋" << endl;
	}
private:
	string m_sflavour;
	string m_sDryFruit;
};

#endif // !IceCream_H

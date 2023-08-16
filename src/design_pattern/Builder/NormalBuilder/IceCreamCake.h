#ifndef IceCreamCake_H
#define IceCreamCake_H

#include <string>
#include <iostream>
using namespace std;

class IceCreamCake
{
public:
	IceCreamCake(string cakeBillet, string IceCream)
		: m_cakeBillet(cakeBillet), m_IceCream(IceCream)
		, m_fruit(""), m_chocolate(""), m_decoration("")
	{
	}
	~IceCreamCake() {}

	void taste()
	{
		if (m_fruit != "")
			cout << m_fruit << "的 ";
		if (m_chocolate != "")
			cout << m_chocolate << "的 ";
		if (m_decoration != "")
			cout << m_decoration << "的 ";
		cout << m_cakeBillet << "的 " << m_IceCream << "的 " << "蛋糕";
	}

	void setFruit(string fruit)
	{
		m_fruit = fruit;
	}

	void setChocolate(string chocolate)
	{
		m_chocolate = chocolate;
	}

	void setDecoration(string decoration)
	{
		m_decoration = decoration;
	}

private:
	string m_cakeBillet;// 必选项： 蛋糕坯层
	string m_IceCream;	// 必选项： 冰淇淋层
	string m_fruit;		// 可选项：水果装饰
	string m_chocolate;	// 可选项：巧克力碎装饰
	string m_decoration;// 可选项：冰淇淋裱花装饰
};

#endif // !IceCreamCake_H


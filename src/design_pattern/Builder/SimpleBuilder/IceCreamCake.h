#ifndef IceCreamCake_H
#define IceCreamCake_H

#include <string>
#include <iostream>
using namespace std;

class IceCreamCake
{
public:
	class Builder
	{
	public:
		Builder(string cakeBillet, string IceCream)
			: m_cakeBillet(cakeBillet), m_IceCream(IceCream)
			, m_fruit(""), m_chocolate(""), m_decoration("")
		{}
		~Builder() {}

		Builder& setFruit(string fruit)
		{
			this->m_fruit = fruit;
			return *this;
		}

		Builder& setChocolate(string chocolate)
		{
			this->m_chocolate = chocolate;
			return *this;
		}

		Builder& setDecoration(string decoration)
		{
			this->m_decoration = decoration;
			return *this;
		}

		IceCreamCake* builer()
		{
			return new IceCreamCake(this);
		}

	private:
		string m_cakeBillet;// 必选项： 蛋糕坯层
		string m_IceCream;	// 必选项： 冰淇淋层
		string m_fruit;		// 可选项：水果装饰
		string m_chocolate;	// 可选项：巧克力碎装饰
		string m_decoration;// 可选项：冰淇淋裱花装饰
		friend class IceCreamCake;
	};
public:
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
private:
	IceCreamCake(Builder* builder)
		: m_cakeBillet(""), m_IceCream(""), m_fruit(""), m_chocolate(""), m_decoration("")
	{
		this->m_cakeBillet = builder->m_cakeBillet;
		this->m_IceCream = builder->m_IceCream;
		this->m_fruit = builder->m_fruit;
		this->m_chocolate = builder->m_chocolate;
		this->m_decoration = builder->m_decoration;
	}

private:
	string m_cakeBillet;// 必选项： 蛋糕坯层
	string m_IceCream;	// 必选项： 冰淇淋层
	string m_fruit;		// 可选项：水果装饰
	string m_chocolate;	// 可选项：巧克力碎装饰
	string m_decoration;// 可选项：冰淇淋裱花装饰
};

#endif // !IceCreamCake_H


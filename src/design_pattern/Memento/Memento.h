#ifndef Memento_H
#define Memento_H
using namespace std;
// Memento 备忘录：负责存储原发器的内部状态，并提供恢复状态的接口
// 备忘录模式的优点：
// 1. 提供了一种可以恢复状态的机制，使得用户可以方便地回到某个历史的状态。
// 2. 实现了信息的封装，使得用户不需要知道对象的内部结构，也无需关心其实现细节。
// 3. 简化了原发器的设计，原发器不再需要管理其内部状态的变化，只需要提供一个备忘录来存储状态即可。
// 4. 简化了恢复状态的过程，用户无需管理复杂的状态转换逻辑。
// 5. 防止了对象被修改，因为备忘录模式只负责存储对象状态，并不涉及对象本身的修改。

class Memento
{
public:
	Memento(string flavour, string dryFruit)
		: m_sflavour(flavour), m_sDryFruit(dryFruit) {}
	string getFlavour() { return m_sflavour; }
	string getDryFruit() { return m_sDryFruit; }

private:
	string m_sflavour;
	string m_sDryFruit;
};

#endif // !Memento_H

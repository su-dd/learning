// #include <QCoreApplication>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     return a.exec();
// }
#include <functional>
#include <iostream>
#include <memory>

void f(int n1, int n2, int n3, const int& n4, int n5) {
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << std::endl;
}

int g(int n1) { return n1; }

struct Foo {
    void print_sum(int n1, int n2) { std::cout << n1 + n2 << std::endl; }
    int data = 10;
};

int main() {
    using namespace std::placeholders;  // ��� _1, _2, _3...

    // ��ʾ����������Ͱ����ô���
    int n = 7;
    // �� _1 �� _2 ���� std::placeholders ������ʾ�����ᴫ�ݸ� f1 �Ĳ�����
    auto f1 = std::bind(f, _2, 42, _1, std::cref(n), n);
    n = 10;
    f1(1, 2, 1001);  // 1 Ϊ _1 ���󶨣� 2 Ϊ _2 ���󶨣���ʹ�� 1001
        // ���е� f(2, 42, 1, n, 7) �ĵ���

    // Ƕ�� bind �ӱ��ʽ����ռλ��
    auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
    f2(10, 11, 12);  // ���е� f(12, g(12), 12, 4, 5); �ĵ���

    // ��ָ���Ա����ָ��
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
    f3(5);

    // ��ָ�����ݳ�Աָ��
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(foo) << std::endl;

    // ����ָ���������ڵ��ñ����ö���ĳ�Ա
    std::cout << f4(std::make_shared<Foo>(foo)) << std::endl;
}

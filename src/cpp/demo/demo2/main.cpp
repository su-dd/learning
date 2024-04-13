#include <functional>
#include <iostream>
#include <memory>

class parent
{
public:
    parent()
    {
        std::cout << "parent constructor" << std::endl;
        print();
    }

    virtual ~parent()
    {
        std::cout << "parent destructor" << std::endl;
        print();
    }

    virtual void print()
    {
        std::cout << "parent print" << std::endl;
    }
};

class child : public parent
{
public:
    child() : parent()
    {
        std::cout << "child constructor" << std::endl;
    }

    ~child()
    {
        std::cout << "child destructor" << std::endl;
    }

    void print()
    {
        std::cout << "child print" << std::endl;
    }
};

int main()
{
    parent *p = new child();
    delete p;
    return 0;
}

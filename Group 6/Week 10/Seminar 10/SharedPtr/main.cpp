
#include <iostream>
#include "SharedPtr.hpp"
#include "WeakPtr.hpp"
using namespace std;
class Base {
public:
    virtual void show() {
        cout << "Base\n";
    }
};
class A : public Base {
public:
    void show() override {
        cout << "Aaaaa\n";
    }
};
struct B {
    B() {
        std::cout << "B()" << std::endl;
    }

    ~B() {
        std::cout << "~B()" << std::endl;
    }
};
int main()
{
    
        SharedPtr<Base> obj(new A());
        obj->show();
        SharedPtr<Base> obj2 = obj;
        obj2->show();
        obj2.reset(new Base());
        obj2->show();
        cout << obj2.getRefCount();
   
    
}

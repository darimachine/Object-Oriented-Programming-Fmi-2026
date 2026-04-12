#include<iostream>

class Base{
public: 
    virtual void f(){
        std::cout << "base::f()\n";
    }
};

class Derived: public Base{
public: 
    virtual void f() override{
        std::cout << "derived::f()\n";
    }
};

class Derived2 : public Derived{
public:
     virtual void f() override{
        std::cout << "derived2::f()\n";
    }
};

int main(){
    Derived2 derivedObj2;

    Base* pb = &derivedObj2;
    Derived* pd = &derivedObj2;
    Derived2* pd2 = &derivedObj2;

    pb->f();
    pd->f();
}
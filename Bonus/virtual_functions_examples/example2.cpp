#include<iostream>

class Base{
public: 
    virtual void f(){
        std::cout << "base::f()\n";
    }
};

class Derived: public Base{
public: 
    void f(){
        std::cout << "derived::f()\n";
    }
};

int main(){
    Derived derivedObj;

    Base* pb = &derivedObj;
    Derived* pd = &derivedObj;

    pb->f();
    pd->f();

    Base baseObj = derivedObj;
    baseObj.f();
}

/*  
    динамично свързване
    derived::f()
    derived::f()
*/
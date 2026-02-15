#include<iostream>

class Base{
public: 
    virtual void f(){
        std::cout << "base::f()\n";
    }
};

class Derived: public Base{
public: 
    virtual void f(int value){
        std::cout << "derived::f(int)\n";
    }
};

class Derived2 : public Derived{
public:
    virtual void f(int value){
        std::cout << "derived2::f(int)\n";
    }
};

int main(){
    Derived2 derivedObj2;

    Base* pb = &derivedObj2;
    Derived* pd = &derivedObj2;
    Derived2* pd2 = &derivedObj2;

    pb->f();   
    //pd->f();
    //pd2->f();    

    pd->f(5);
    pd2->f(6);
}
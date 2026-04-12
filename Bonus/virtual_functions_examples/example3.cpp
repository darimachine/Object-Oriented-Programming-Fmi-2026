#include<iostream>

class Base{
public: 
    virtual void f(){
        std::cout << "base::f()\n";
    }
};

class Derived: public Base{
public: 
};

class Derived2 : public Derived{

};

int main(){
    Derived2 derivedObj2;

    Base* pb = &derivedObj2;
    Derived* pd = &derivedObj2;
    Derived2* pd2 = &derivedObj2;

    pb->f();   
    pd->f();
    pd2->f();    
}
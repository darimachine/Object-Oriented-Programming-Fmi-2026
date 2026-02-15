#include<iostream>
class Base{
public: 
    void f(){
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
    
    //статично свързване
    Base* pb = &derivedObj;
    Derived* pd = &derivedObj;

    pb->f();
    pd->f();
}

/*
   base::f()
   derived::f() 
*/
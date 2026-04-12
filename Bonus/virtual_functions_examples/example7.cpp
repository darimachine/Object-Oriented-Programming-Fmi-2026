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

void print(Base* base){
    base->f();
}

int main(){
    Derived d;
    print(&d);
}
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

class Derived2 : public Derived{
public:
    void f(){
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
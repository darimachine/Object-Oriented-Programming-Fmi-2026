#include<iostream>

class Printable{
public:
    virtual void getName() = 0;
};

class Base : public Printable{
public: 
    virtual void getName() {
        std::cout << "base\n";
    }
};

class Derived: public Base{
public: 
    virtual void getName() override{
        std::cout << "derived\n";
    }
};

class Derived2 : public Derived{
public:
    virtual void getName() override{
        std::cout << "derived2\n";
    }
};


void printable(Printable* pr){
    pr->getName();
}

int main(){
    Base* b = new Base();
    printable(b);
    delete b;

    Derived* d = new Derived();
    printable(d);
    delete d;

    Derived2* d2 = new Derived2();
    printable(d2);
    delete d2;
}
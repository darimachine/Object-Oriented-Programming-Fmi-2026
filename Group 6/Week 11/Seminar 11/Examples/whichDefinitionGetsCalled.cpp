#include <iostream>

class A {
public:
    void print() { std::cout << "A::print()" << std::endl; }
};

class B : public A {
public:
    void print() { std::cout << "B::print()" << std::endl; }
};

class C : public B {};

int main() {
    C c;
    c.print();
}

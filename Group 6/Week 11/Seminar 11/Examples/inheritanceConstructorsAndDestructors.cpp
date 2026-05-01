#include <iostream>

struct A {
    int n = 0;

    A() {
        std::cout << "A()" << std::endl;
    }

    A(int n) : n(n) {
        std::cout << "A(int)" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
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

struct C {
    C() {
        std::cout << "C()" << std::endl;
    }

    ~C() {
        std::cout << "~C()" << std::endl;
    }
};

class Base {
private:
    A a;

public:
    Base() {
        std::cout << "Base()" << std::endl;
    }

    Base(int n) : a(n) {
        std::cout << "Base(int)" << std::endl;
    }

    ~Base() {
        std::cout << "~Base()" << std::endl;
    }
};

class Der: public Base {
private:
    B b;
    C c;

public:
    Der() {
        std::cout << "Der()" << std::endl;
    }

    Der(int n) : Base(n) {
        std::cout << "Der(int)" << std::endl;
    }

    ~Der() {
        std::cout << "~Der()" << std::endl;
    }
};

int main() {
    Der der; // A() Base() B() C() Der()
}
// ~Der() ~C() ~B() ~Base() ~A()

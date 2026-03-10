#include <iostream>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    A(const A &other) {
        std::cout << "A(const A&)" << std::endl;
    }

    A& operator=(const A& other) {
        std::cout << "A& operator=(const A&)" << std::endl;
        return *this;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << "B()" << std::endl;
    }

    B(const B& other) {
        std::cout << "B(const B&)" << std::endl;
    }

    B& operator=(const B& other) {
        std::cout << "B& operator=(const B&)" << std::endl;
        return *this;
    }

    ~B() {
        std::cout << "~B()" << std::endl;
    }
};

class C {
    A a;
    B b;

public:
    C(const A& a, const B& b) : a(a), b(b) {
        std::cout << "C(a, b)" << std::endl;
    }

    ~C() {
        std::cout << "~C()" << std::endl;
    }
};

class D {
    A a;
    B b;

public:
    D(const A& a, const B& b) {
        this->a = a;
        this->b = b;
        std::cout << "D(a, b)" << std::endl;
    }

    ~D() {
        std::cout << "~C()" << std::endl;
    }
};

int main()
{
    A a;
    B b;
    C c(a, b); // this only calls the copy constructors of A and B, much more efficient
    D d(a, b); // this calls the default constructors of A and B and then the op= of A and B
}

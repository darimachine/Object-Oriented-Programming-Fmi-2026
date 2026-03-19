#include <iostream>
#include <ostream>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    A(const A& other) {
        std::cout << "Copy constructor of A" << std::endl;
    }

    A& operator=(const A& other) {
        std::cout << "Operator= of A" << std::endl;
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
        std::cout << "Copy constructor of B" << std::endl;
    }

    B& operator=(const B& other) {
        std::cout << "Operator= of B" << std::endl;
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
    C() {
        std::cout << "C()" << std::endl;
    }

    // Important: the copy constructor needs to explicitly call the copy constructors of A and B
    // if we don't explicitly call them in the member initializer list,
    // the copy constructor of C will call the default constructors of A and B
    // which is NOT what we want in most cases!!!
    C(const C& other): a(other.a), b(other.b) {
        std::cout << "Copy constructor of C" << std::endl;
    }

    C& operator=(const C& other) {
        // Important: the assignment operator= of C needs to explicitly call the operator= of A and B
        // if we don't explicitly call them in the body of the operator=,
        // it will just call the default constructors,
        // but we need to call the operator= on A and B as well, so that they are the same as the other.a and other.b
        this->a = other.a;
        this->b = other.b;
        std::cout << "Operator= of C" << std::endl;
        return *this; // operator= returns a reference to the current object, which is being modified
    }

    ~C() {
        std::cout << "~C()" << std::endl;
    }
};

void receiveAsCopy(C copy) {
    // this function receives C as a copy, therefore it creates a copy inside the method
    // that will call the copy constructor of C
}

void receiveAsRef(const C& ref) {
    // this one doesn't create a copy, therefore it doesn't call the copy constructor
}

int main() {
    C c1; // A() B() C()
    std::cout << "---------" << std::endl;
    C c2(c1); // cc of A, cc of B, cc of C
    std::cout << "---------" << std::endl;
    C c3 = c1; // cc of A, cc of B, cc of C
    std::cout << "---------" << std::endl;
    c3 = c2; // op= of A, op= of B, op= of C
    std::cout << "---------" << std::endl;
    receiveAsCopy(c1); // cc of A, cc of B, cc of C, ~C(), ~B(), ~A()
    std::cout << "---------" << std::endl;
    receiveAsRef(c1); // calls nothing...
}

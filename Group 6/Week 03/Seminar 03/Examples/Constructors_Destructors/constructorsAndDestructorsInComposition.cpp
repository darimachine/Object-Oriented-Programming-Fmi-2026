#include <iostream>

using std::cout;
using std::endl;

struct A {
    A() {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

struct B {
    B() {
        cout << "B()" << endl;
    }

    ~B() {
        cout << "~B()" << endl;
    }
};

struct C {
    A a;
    B b;

    C() : b(), a() {
        // the order of the member initializer list does not matter!
        // if we don't write anything in the member initializer list,
        // it will automatically call the default constructors of A and B!
        cout << "C()" << endl;
    }

    ~C() {
        cout << "~C()" << endl;
    }
};

int main() {
    C obj; // A() B() C()

    C arr[3]; // A() B() C() A() B() C() A() B() C()
}
// ~C() ~B() ~A() ~C() ~B() ~A() ~C() ~B() ~A()
// ~C() ~B() ~A()

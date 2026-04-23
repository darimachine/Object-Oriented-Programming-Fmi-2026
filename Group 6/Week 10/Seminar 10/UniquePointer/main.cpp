#include <iostream>
#include "UniquePtr.hpp"

class A {
public:

    A() {
        std::cout << "A()" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }

    void f() {
        std::cout << "A::f()" << std::endl;
    }
};

int main() {
    UniquePtr<int> ptr(new int(24));
    std::cout << *ptr << std::endl;

    UniquePtr<A> aPtr(new A());
    aPtr->f();

    //UniquePtr<int> secondPtr = ptr; // compile-time error
    UniquePtr<int> anotherPtr = std::move(ptr);
    std::cout << *anotherPtr << std::endl;
    //std::cout << *ptr << std::endl;
    if (!ptr) {
        std::cout << "ptr is nullptr";
    } else {
        std::cout << "ptr points to something";
    }
}
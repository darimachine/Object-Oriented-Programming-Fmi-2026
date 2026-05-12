#include <iostream>

class Base {
public:
    Base() {
        f();
    }

    virtual void f() const {
        std::cout << "Base::f()" << std::endl;
    }

    virtual void g() const {
        f();
    }

    virtual ~Base() {
        f();
    }
};

class Der : public Base {
public:

    void f() const override {
        std::cout << "Der::f()" << std::endl;
    }
};

int main() {
    Der d;
    // First, Base() is called.
    // Inside Base(), it calls f() → this calls Base::f(), because Der isn't constructed yet.
    // Output: Base::f()
    // Then Der's constructor runs (but it's empty here).

    d.g();
    // g() is inherited from Base and calls f() virtually.
    // Now the object is fully constructed as a Der, so virtual dispatch works.
    // Output: Der::f()

}
// ~Der() runs implicitly at end of main
// Base class ~Base() is called.
// Inside ~Base(), it calls f() → this calls Base::f(), because Der part is already destroyed.
// Output: Base::f()

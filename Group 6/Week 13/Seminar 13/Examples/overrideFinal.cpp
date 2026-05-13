#include <iostream>

class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
};

class Der : public Base {
public:
    // the final keyword means that we can't override this virtual function anymore!
    void f() override final {
        std::cout << "Der::f()" << std::endl;
    }
};

class Der2 : public Der {
public:
    // compile-time error: Der2::f() overrides final function Der::f()
    void f() override {
        std::cout << "Der2::f()" << std::endl;
    }
};

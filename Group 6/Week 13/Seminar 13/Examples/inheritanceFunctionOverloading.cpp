#include <iostream>

class Base {
public:
    virtual ~Base()  = default;

    virtual void f() {
        std::cout << "Base::f()\n";
    }
};

class Der: public Base {
public:
    void f() override {
        std::cout << "Der::f()\n";
    }

    virtual void f(int value) {
        std::cout << "Der::f(int)\n";
    }
};

class Der2 : public Der {
public:
    using Der::f;

    void f(int value) override {
        std::cout << "Der2::f(int)\n";
    }
};

int main() {
    Der2 derivedObj2;

    Base* pb = &derivedObj2;
    Der* pd = &derivedObj2;
    Der2* pd2 = &derivedObj2;

    pb->f(); // Der::f()
    pd->f(); // Der::f()
    pd2->f(); // Der::f()

    pd->f(5); // Der::f(int)
    pd2->f(6); // Der2::f(int)
}

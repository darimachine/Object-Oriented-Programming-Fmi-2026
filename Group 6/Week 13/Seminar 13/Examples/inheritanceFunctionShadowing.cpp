#include <iostream>

class Base {
public:
    virtual ~Base()  = default;

    virtual void f() const {
        std::cout << "Base::f()\n";
    }
};

class Der: public Base {
public:
    virtual void f(int value) const {
        std::cout << "Der::f(int)\n";
    }
};

class Der2 : public Der {
public:
    void f(int value) const override {
        std::cout << "Der2::f(int)\n";
    }
};

int main() {
    Der2 derivedObj2;

    Base* pb = &derivedObj2;
    Der* pd = &derivedObj2;
    Der2* pd2 = &derivedObj2;

    pb->f();
    pd->f(); // f(int) shadows f() from the base, therefore this won't be able to compile
    pd2->f(); // f(int) shadows f() from the base, therefore this won't be able to compile

    pd->f(5); // Der::f(int)
    pd2->f(6); // Der2::f(int)
}

#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "~Base()" << std::endl;
    }

    virtual void f() const {
        std::cout << "Base::f()" << std::endl;
    }

    void g() const {
        std::cout << "Base::g()" << std::endl;
    }
};

class Der : public Base {
public:
    ~Der() {
        std::cout << "~Der()" << std::endl;
    }

    void f() const override {
        std::cout << "Der::f()" << std::endl;
    }

    // this function shadows Base::g(), but is not an override of it, because Base::g() is not a virtual function
    // therefore when called from a Der it will call Der::g(),
    // but when called from a Base* it will call Base::g()
    void g() const {
        std::cout << "Der::g()" << std::endl;
    }
};

int main() {

    std::unique_ptr<Base> ptr = std::make_unique<Der>();
    ptr->f(); // Der::f()
    ptr->g(); // Base::g()

} // calls ~Base(), but since it is virtual it will call the right destructor,
//in this case ~Der() which itself will call ~Base()

#include <iostream>
#include <memory>

class Base {
public:
    void f() const {
        std::cout << "Base::f()" << std::endl;
    }
};

class Der: public Base{
public:
    void f() const {
        std::cout << "derived::f()\n";
    }
};

class Der2 : public Der{
public:
    void f() const {
        std::cout << "derived2::f()\n";
    }
};

class VirtualBase {
public:
    virtual ~VirtualBase() = default;

    virtual void f() const {
        std::cout << "VirtualBase::f()" << std::endl;
    }
};

class VirtualDer: public VirtualBase {
public:
    void f() const override {
        std::cout << "VirtualDer::f()" << std::endl;
    }
};

class VirtualDer2: public VirtualDer {
public:
    void f() const override {
        std::cout << "VirtualDer2::f()" << std::endl;
    }
};

void print(const std::unique_ptr<Base>& ptr){
    ptr->f();
}

void printVirtual(const std::unique_ptr<VirtualBase>& ptr) {
    ptr->f();
}

int main() {
    std::unique_ptr<Base> b1 = std::make_unique<Der>();
    std::unique_ptr<Base> b2 = std::make_unique<Der2>();

    print(b1);  // Base::f()
    print(b2);  // Base::f()

    std::unique_ptr<VirtualBase> vb1 = std::make_unique<VirtualDer>();
    std::unique_ptr<VirtualBase> vb2 = std::make_unique<VirtualDer2>();

    printVirtual(vb1);  // VirtualDer::f()
    printVirtual(vb2);  // VirtualDer2::f()
}

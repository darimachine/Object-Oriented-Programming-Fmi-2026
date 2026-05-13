#include <iostream>
#include <memory>

// printable is an interface (only pure virtual functions)
// we cant instantiate it
// but we can use it as a parameter type
class Printable {
public:
    virtual void print() const = 0;
};

class Base : public Printable {
public:
    virtual ~Base() = default;
    void print() const override {
        std::cout << "Base::print()" << std::endl;
    }
};

class Der1: public Base {
public:
    void print() const override {
        std::cout << "Der1::print()" << std::endl;
    }
};

class Der2 : public Der1 {
public:
    void print() const override{
        std::cout << "Der2::print()" << std::endl;
    }
};

void callPrintable(const std::unique_ptr<Printable>& printable) {
    printable->print();
}

int main() {
    std::unique_ptr<Printable> b = std::make_unique<Base>();
    callPrintable(b);

    std::unique_ptr<Printable> d = std::make_unique<Der1>();
    callPrintable(d);

    std::unique_ptr<Printable> d2 = std::make_unique<Der2>();
    callPrintable(d2);
}

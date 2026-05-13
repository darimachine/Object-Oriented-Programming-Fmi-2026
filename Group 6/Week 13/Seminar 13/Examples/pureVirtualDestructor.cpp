#include <iostream>

class AbstractBase {
public:
    virtual void f() {
        std::cout << "AbstractBase::f()" << std::endl;
    }

    virtual ~AbstractBase() = 0;
};

// we need to explicitly define the destructor even though it is pure virtual,
// since the destructor of Der will need to call it anyway and the base resources have to be cleaned up
AbstractBase::~AbstractBase() {
    std::cout << "~AbstractBase()" << std::endl;
}

class Der: public AbstractBase {};

int main() {
    // AbstractBase base; // error: can't instantiate objects from abstract class!
    Der d;
    d.f();
} //~Der() ~AbstractBase()

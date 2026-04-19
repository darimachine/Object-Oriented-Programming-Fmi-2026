#include <iostream>

class SelfPrinting {
    int n;
public:
    SelfPrinting(int n) : n(n) {}

    void printSelf() const {
        std::cout << "printing myself... " << n <<  std::endl;
    }
};

class OtherClass {
public:
    void g() const {
        //...
    }

    void k() {
        // ...
    }
};

template <typename T>
void print(const T& obj) {
    obj.printSelf();
    // printSelf() is a required function
    // the compiler expects whatever class the print function is called for, to have the printSelf() function
}

int main() {
    print(SelfPrinting(24)); // ok
    print(SelfPrinting(11)); // ok
    print(OtherClass()); // error: no member named 'printSelf' in OtherClass
}

#include <iostream>

class Example {};

template <typename T>
void f(const T& obj) {
    std::cout << "any type, same logic" << std::endl;
}

template<>
void f(const Example& e) {
    std::cout << "specific logic only for Example class" << std::endl;
}

int main() {
    f(1); // any type, same logic
    f('a'); // any type, same logic
    f(true); // any type, same logic

    Example e;
    f(e); // specific logic only for Example class
}

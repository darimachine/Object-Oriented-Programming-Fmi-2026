#include <iostream>

#include"MyString.h"

int main() {
    MyString a("apple");
    MyString b("banana");
    MyString c = a + MyString(", ") + b;

    std::cout << c << "\n"; // apple, banana
    std::cout << c.getSize() << "\n"; // 14
    std::cout << c.substr(7, 6) << "\n"; // banana

    std::cout << (a < b ? "a < b" : "a >= b") << "\n"; // a < b

    auto cmp = a <=> b;
    if (cmp < 0) std::cout << "a е по-малък\n";
}

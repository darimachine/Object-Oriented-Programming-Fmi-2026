#include <iostream>
#include "MyString.h"

int main()
{
    MyString a("apple");
    MyString b("banana");
    MyString c = a + MyString(", ") + b;

    std::cout << c << "\n";               
    std::cout << c.getSize() << "\n";     
    std::cout << c.substr(7, 6) << "\n";  

    std::cout << (a < b ? "a < b" : "a >= b") << "\n";  

    auto cmp = a <=> b;
    if (cmp < 0) std::cout << "a is smaller\n";
}


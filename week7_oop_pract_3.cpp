#include <iostream>
#include "MyString.h"


int main()
{
    MyString str("hello");

    std::cout << "Initial: " << str << std::endl;

    str.insert(3, 'Y'); 
    std::cout << "Insert char at 3: " << str << std::endl;

    str.insert(2, "ABC");
    std::cout << "Insert \"ABC\" at 2: " << str << std::endl;

    MyString add("123");
    str.insert(1, add);
    std::cout << "Insert MyString \"123\" at 1: " << str << std::endl;

    str.erase(2, 3);
    std::cout << "Erase 3 chars from index 2: " << str << std::endl;

    std::cout << "Contains 'A'? " << (str.contains('A') ? "YES" : "NO") << std::endl;

    std::cout << "Contains \"lo\"? " << (str.contains("lo") ? "YES" : "NO") << std::endl;
    std::cout << "Contains \"ABC\"? " << (str.contains("ABC") ? "YES" : "NO") << std::endl;

    MyString test("el");
    std::cout << "Contains MyString \"el\"? " << (str.contains(test) ? "YES" : "NO") << std::endl;

    return 0;
}


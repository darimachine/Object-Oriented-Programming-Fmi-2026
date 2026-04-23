#include <iostream>
#include"MyString.h"
#include<print>

int main()
{
    MyString a("apple");
    MyString b("banana");
    MyString c = a + MyString(", ") + b;

    std::cout << c << "\n";               // apple, banana
    std::cout << c.getSize() << "\n";     // 14
    std::cout << c.getSubstr(7, 6) << "\n";  // banana

    std::cout << (a < b ? "a < b" : "a >= b") << "\n";  // a < b

    auto cmp = a <=> b;
    if (cmp < 0)
    {
        std::cout << "a is less than b\n";
    }

    //Week 7
    MyString s("Hello");

    std::println("Initial string: {}", s.c_str());

    s.insert(5, '!');
    std::println("After insert char: {}", s.c_str());

    s.insert(6, " world");
    std::println("After insert string: {}", s.c_str());

    MyString s2(" C++");
    s.insert(12, s2);
    std::println("After insert MyString: {}", s.c_str());

    s.erase(5);
    std::println("After erase 1 char: {}", s.c_str());

    s.erase(12, 3);
    std::println("After erase 3 chars: {}", s.c_str());

    std::println("Contains 'H': {}", s.contains('H'));
    std::println("Contains \"Hello\": {}", s.contains("Hello"));
    std::println("Contains MyString(\"C++\"): {}", s.contains(MyString("C++")));

    MyString moved = std::move(s);
    std::println("Moved string: {}", moved.c_str());
    
    return 0;
}


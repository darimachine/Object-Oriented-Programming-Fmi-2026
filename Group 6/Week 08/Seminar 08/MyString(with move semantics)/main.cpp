#include <iostream>
#include <cassert>
#include "MyString.h"

int main() {
    // --- Конструктори ---
    MyString s1;                    // default
    MyString s2("hello");           // от C-string
    MyString s3 = s2;              // copy constructor
    MyString s4 = std::move(s3);   // move constructor

    std::cout << "s1: \"" << s1 << "\"\n";   // ""
    std::cout << "s2: \"" << s2 << "\"\n";   // "hello"
    std::cout << "s4: \"" << s4 << "\"\n";   // "hello"
    std::cout << "s3 след move: \"" << s3 << "\"\n";  // "" (празно)

    // --- operator= ---
    MyString s5;
    s5 = s2;                  // copy assignment
    std::cout << "s5: \"" << s5 << "\"\n";   // "hello"

    MyString s6;
    s6 = std::move(s5);       // move assignment
    std::cout << "s6: \"" << s6 << "\"\n";   // "hello"

    // --- length и c_str ---
    std::cout << "length: " << s2.length() << "\n";   // 5
    std::cout << "c_str:  " << s2.c_str() << "\n";   // hello

    // --- operator[] ---
    std::cout << "s2[0]: " << s2[0] << "\n";   // h
    s2[0] = 'H';
    std::cout << "s2 след s2[0]='H': " << s2 << "\n";  // Hello

    // --- operator+= ---
    MyString s7("world");
    s2 += MyString(" ");
    s2 += s7;
    std::cout << "s2 += \" world\": " << s2 << "\n";   // Hello world

    // --- operator+ ---
    MyString s8 = MyString("foo") + MyString("bar");
    std::cout << "foo + bar: " << s8 << "\n";   // foobar

    // --- Сравнение ---
    MyString a("apple");
    MyString b("banana");
    MyString c("apple");

    std::cout << "apple == apple: " << (a == c ? "true" : "false") << "\n";  // true
    std::cout << "apple == banana: " << (a == b ? "true" : "false") << "\n"; // false
    std::cout << "apple < banana:  " << (a < b ? "true" : "false") << "\n"; // true
    std::cout << "banana > apple:  " << (b > a ? "true" : "false") << "\n"; // true
    std::cout << "apple <= apple:  " << (a <= c ? "true" : "false") << "\n"; // true

    // --- operator<=> ---
    auto cmp = a <=> b;
    if (cmp < 0) std::cout << "apple е преди banana\n";   // това

    // --- Самоприсвояване ---
    MyString s9("test");
    s9 = s9;
    std::cout << "self-assign: " << s9 << "\n";   // test

    // --- operator>> ---
    std::cout << "Въведи стринг: ";
    MyString input;
    std::cin >> input;
    std::cout << "Въведено: " << input << "\n";
    std::cout << "Дължина: " << input.length() << "\n";
}
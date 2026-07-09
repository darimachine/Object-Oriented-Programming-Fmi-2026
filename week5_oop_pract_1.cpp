#include <iostream>
#include <print>
#include "Stack.h"

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    Stack copy = s;

    s.pop();

    std::println("Original top: {}",s.peek());
    std::println("Copy top: {}", copy.peek());

    return 0;
}


#include <iostream>
#include <string>
#include "Stack.hpp"

template <typename T, unsigned S>
void printStack(Stack<T, S> st) {
    while (!st.isEmpty()) {
        std::cout << st.peek() << ' ';
        st.pop();
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Stack<int, 5>:\n";
    Stack<int, 5> numbers;

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Top: " << numbers.peek() << '\n';
    std::cout << "Size: " << numbers.getSize() << '\n';
    std::cout << "Is empty: " << numbers.isEmpty() << '\n';
    std::cout << "Is full: " << numbers.isFull() << '\n';

    std::cout << "All elements (top to bottom): ";
    printStack(numbers);

    std::cout << "\nAfter one pop:\n";
    numbers.pop();
    std::cout << "Top: " << numbers.peek() << '\n';
    std::cout << "Size: " << numbers.getSize() << '\n';

    std::cout << "\nFilling the stack:\n";
    numbers.push(40);
    numbers.push(50);
    numbers.push(60);

    std::cout << "Is full: " << numbers.isFull() << '\n';
    std::cout << "Elements: ";
    printStack(numbers);

    std::cout << "\nStack<std::string, 4>:\n";
    Stack<std::string, 4> words;
    words.push("stefcho");
    words.push("se");

    std::string s = "zabavlqva";
    words.push(std::move(s));

    std::cout << "Top: " << words.peek() << '\n';
    std::cout << "Size: " << words.getSize() << '\n';

    std::cout << "All elements (top to bottom): ";
    printStack(words);

    return 0;
}

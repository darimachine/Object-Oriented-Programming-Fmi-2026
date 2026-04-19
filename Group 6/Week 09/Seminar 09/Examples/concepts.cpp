#include <iostream>
#include <concepts>
#include <string>
#include <vector>

// -----------------------------
// Example 1: built-in concept
// -----------------------------

template<std::integral T>
T add(T a, T b) {
    return a + b;
}

// -----------------------------
// Example 2: custom concept
// type must support operator<
// -----------------------------

template<typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template<Comparable T>
const T& myMin(const T& a, const T& b) {
    return (a < b) ? a : b;
}

// -----------------------------
// Example 3: custom concept
// type must have size()
// -----------------------------

template<typename T>
concept HasSize = requires(T obj) {
    { obj.size() } -> std::convertible_to<std::size_t>;
};

template<HasSize T>
void printSize(const T& obj) {
    std::cout << "Size: " << obj.size() << '\n';
}

// -----------------------------
// Example 4: custom concept
// type must have print()
// -----------------------------

template<typename T>
concept Printable = requires(T obj) {
    { obj.print() } -> std::same_as<void>;
};

template<Printable T>
void printTwice(const T& obj) {
    obj.print();
    obj.print();
}

// -----------------------------
// Example user-defined type
// -----------------------------

struct Person {
    void print() const {
        std::cout << "Person\n";
    }
};

int main() {
    std::cout << "Built-in concept std::integral:\n";
    std::cout << add(3, 4) << '\n';
    // std::cout << add(3.5, 4.2) << '\n'; // compile-time error

    std::cout << "\nCustom concept Comparable:\n";
    std::cout << myMin(10, 20) << '\n';
    std::cout << myMin(2.5, 1.2) << '\n';

    std::cout << "\nCustom concept HasSize:\n";
    std::string s = "hello";
    std::vector<int> v = {1, 2, 3, 4};
    printSize(s);
    printSize(v);

    std::cout << "\nCustom concept Printable:\n";
    Person p;
    printTwice(p);

    return 0;
}

#include <iostream>
#include <string>

// -----------------------------
// Example 1: recursive printing
// -----------------------------

void print() {
    std::cout << '\n';
}

template<typename T, typename... Args>
void print(const T& first, const Args&... rest) {
    std::cout << first << " ";
    print(rest...);
}

// -----------------------------
// Example 2: recursive sum
// -----------------------------

template<typename T>
T sumRecursive(const T& value) {
    return value;
}

template<typename T, typename... Args>
T sumRecursive(const T& first, const Args&... rest) {
    return first + sumRecursive(rest...);
}

// -----------------------------
// Example 3: fold expression
// -----------------------------

template<typename... Args>
auto sumFold(const Args&... args) {
    return (args + ...);
}

// -----------------------------
// Example 4: count arguments
// -----------------------------

template<typename... Args>
std::size_t countArgs(const Args&... args) {
    return sizeof...(args);
}

int main() {
    std::cout << "Recursive print:\n";
    print(42, 3.14, "hello", 'A');

    std::cout << "\nRecursive sum:\n";
    std::cout << sumRecursive(1, 2, 3, 4) << '\n';
    std::cout << sumRecursive(1.5, 2.5, 3.0) << '\n';

    std::cout << "\nFold expression sum:\n";
    std::cout << sumFold(10, 20, 30) << '\n';
    std::cout << sumFold(1.1, 2.2, 3.3) << '\n';

    std::cout << "\nCount arguments:\n";
    std::cout << countArgs(1, 2, 3, 4, 5) << '\n';
    std::cout << countArgs("a", 42, 3.14) << '\n';

    return 0;
}
#include <iostream>
#include "utils.cpp"

// those linking errors bellow happen because
// #include "utils.cpp" pastes the content of the utils.cpp file
// therefore there will be definitions of the sum and max functions
// both in the main.cpp file and in the utils.cpp file

int main() {
    std::cout << sum(5, 3); // linking error: duplicate symbol sum(int, int)
    std::cout << max(5, 3); // linking error: duplicate symbol max(int, int)
}

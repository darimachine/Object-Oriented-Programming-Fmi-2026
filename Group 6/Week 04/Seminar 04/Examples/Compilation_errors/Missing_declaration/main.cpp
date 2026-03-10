#include <iostream>

// we need to either declare the sum(int, int) function here
// or declare it in a header file and include that header file
// which is the better approach

int main() {
    std::cout << sum(1, 2); // compiler error
}

#include <iostream>
#include "utils.h"

// #include "utils.h" is the same as declaring the functions here
// the linker will find their definitions in utils.cpp anyway
// but having them in a header file and including it is better
// because that way if we need these functions in other files and not only this cpp file
// it helps reduce code repetition and also if we change the signature of the functions
// we won't need to change the declarations everywhere
// so from now on we will use and include header files with declarations
// when solving tasks for the OOP course

int main() {
    std::cout << sum(5, 3) << '\n'; // 8
    std::cout << max(5, 3); // 5
}

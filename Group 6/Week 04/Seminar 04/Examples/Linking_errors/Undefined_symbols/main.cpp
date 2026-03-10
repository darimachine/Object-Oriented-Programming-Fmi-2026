#include <iostream>
#include "util.h"

int main() {
    std::cout << sum(1, 2); // linker error: Undefined symbol sum(int, int)
                                // because there is no definition for the function in any of the files
}

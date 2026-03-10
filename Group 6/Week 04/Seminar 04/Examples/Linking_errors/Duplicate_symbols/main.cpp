#include <iostream>
#include "util.h"

int main() {
    std::cout << sum(1, 2); // linker error: Duplicate symbol sum(int, int)
                                // because there is more than one definition of that function
                                // across the files and linker doesn't know which one to use
}

#include <iostream>

struct Example {
    Example() {
        std::cout << "Example()" << std::endl;
    }

    Example(const Example& other) {
        std::cout << "Copy constructor of Example" << std::endl;
    }

    Example& operator=(const Example& other) {
        std::cout << "operator=" << std::endl;
        return *this;
    }

    ~Example() {
        std::cout << "~Example()" << std::endl;
    }
};

// RVO: Compiler can optimize this by constructing the return object in place.
Example createExampleRVO() {
    return Example();  // Temporary object can be optimized away.
}

// NRVO: Compiler can optimize this, but only if it detects that the same named object is always returned.
Example createExampleNRVO() {
    Example obj;  // Named object
    return obj;   // NRVO can optimize this
}

Example createWithoutOptimization(bool condition)
{
    Example obj1;
    Example obj2;
    if (condition)
    {
        return obj1;
    }
    return obj2;
}

int main() {
    Example e = createExampleRVO(); // Example(), just default constructor
    std::cout << "-----" << std::endl;
    Example e2 = createExampleNRVO(); // Example(), just default constructor
    std::cout << "-----" << std::endl;
    Example e3 = createWithoutOptimization(true); // calls default constructors and then copy constructor
    std::cout << "-----" << std::endl;
    Example e4 = createWithoutOptimization(false); // calls default constructors and then copy constructor
}

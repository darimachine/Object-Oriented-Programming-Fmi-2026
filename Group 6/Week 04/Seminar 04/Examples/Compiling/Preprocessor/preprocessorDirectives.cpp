#include <iostream>

// macros
#define START {
#define END }

int main() START
#if _DEBUG
    std::cout << "Debug mode" << std::endl;
#else
    std::cout << "Release mode" << std::endl;
#endif
END

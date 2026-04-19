#include "Example.h"

int main() {

    Example<int> e1(5); // ok
    Example<bool> e2(true); // ok
    Example<char> e3('c'); // linking error, we haven't declared a template class Example<char> in the .cpp

    // that is why we use .hpp for templates
}
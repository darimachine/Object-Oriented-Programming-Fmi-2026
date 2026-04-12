#include <iostream>

struct A {
    int n;

    A(int n) {
        // n = n; // this will compile, but it won't do nothing, since it recognizes n as the argument
        this->n = n; // this is the correct way!
    }
    // same goes for getters and setters and any member functions,
    // that receive an argument with the same name as a member
};

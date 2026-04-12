#include <iostream>

struct A {
    int n;

    void f() {
        n++;
        f();
        g();
        t();
        // we can call any member function from a non-const function
    }

    void g() const {
       // n++; // we can't modify members inside a const function
       // f(); // we can't call f() here, because it is not a const function,
       // therefore we have no guarantee that it won't modify something
       t(); // we can only call const functions from a const functions
    }

    void t() const {
       // n++; // we can't do that inside a const function
       // f(); // we can't call f() here, because it is not a const function,
            // therefore we have no guarantee that it won't modify something
       g(); // we can only call const functions 
    }

};

void func1(A& a) {
    a.f(); // we can call that, because the given object is not const
    a.g();
    a.t();
    // we can call every member function here
}

void func2(const A& a) {
    // a.f(); // we can't call that, because the given object is const
           // and we can only call const functions from const objects

    a.g();
    a.t(); // we can call the const ones
}

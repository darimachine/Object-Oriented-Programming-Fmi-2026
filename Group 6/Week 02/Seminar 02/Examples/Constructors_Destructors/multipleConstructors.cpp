#include <iostream>

using std::cout;
using std::endl;

struct A {
    int n = 0;
    char c = '0';
    double d = 0.0;

    A() = default; // this sets the members to their default values or calls their default constructors
    // same as writing an empty A() {}
    // if we don't have the default constructor, we won't be able to create arrays from A

    A(int n) {
        this->n = n;
    }

    A(int n, char c) : A(n) {
        this->c = c;
    }

    // we can also call constructors of the same class inside another constructor of the class for code reusability
    A(int n, char c, double d) : A(n, c) {
        this->d = d;
    }
};

int main() {
    A a1;
    cout << a1.n << ' ' << a1.c << ' ' << a1.d << endl; // 0 0 0.0
    A a2(5);
    cout << a2.n << ' ' << a2.c << ' ' << a2.d << endl; // 5 0 0.0
    A a3(7, 's');
    cout << a3.n << ' ' << a3.c << ' ' << a3.d << endl; // 7 s 0.0
    A a4(8, 'm', 3.14);
    cout << a4.n << ' ' << a4.c << ' ' << a4.d << endl; // 8 m 3.14
}

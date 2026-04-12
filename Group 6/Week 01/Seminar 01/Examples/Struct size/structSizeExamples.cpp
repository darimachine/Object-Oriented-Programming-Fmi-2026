#include <iostream>
using std::cout;
using std::endl;

struct A {
    char c;
    int a;
};

// | c |   |   |   | a | a | a | a |


struct B {
    int a;
    char c;
};

// | a | a | a | a | c |   |   |   |

struct C {
    char c1;
    uint32_t n;
    char c2;
};

// | c1 |   |   |   | n | n | n | n | c2 |   |   |   |


struct D {
    char c1;
    char c2;
    uint32_t n;
};

// | c1 | c2 |   |   | n | n | n | n |


struct E {
    A obj;
    char c;
};

// | A::c |   |   |   | A::a | A::a | A::a | A::a | c |   |   |   |

struct F {
    char c1;
    uint32_t arr[5];
    char c2;
    int64_t n;
};

// | c1 |   |   |   | arr[0] | arr[0] | arr[0] | arr[0] | arr[1] | arr[1] | arr[1] | arr[1] |
// | arr[2] | arr[2] | arr[2] | arr[2] | arr[3] | arr[3] | arr[3] | arr[3] |
// | arr[4] | arr[4] | arr[4] | arr[4] | c2 |   |   |   |   |   |   |   |
// | n | n | n | n | n | n | n | n |

int main() {
    cout << sizeof(A) << endl; // 8
    cout << alignof(A) << endl; // 4

    cout << sizeof(B) << endl; // 8
    cout << alignof(B) << endl; // 4

    cout << sizeof(C) << endl; // 12
    cout << alignof(C) << endl; // 4

    cout << sizeof(D) << endl; // 8
    cout << alignof(D) << endl; // 4

    cout << sizeof(E) << endl; // 12
    cout << alignof(E) << endl; // 4

    cout << sizeof(F) << endl; // 40
    cout << alignof(F) << endl; // 8
}
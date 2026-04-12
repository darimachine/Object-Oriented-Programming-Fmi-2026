#include <iostream>

using std::cout;
using std::endl;

struct A {
    A() { // the class/struct must have a default constructor when using arrays!!! Otherwise: compilation error
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl; 
    }
};

int main() {
    A obj; // A()

    A arr[3]; // A() A() A()

    A* dynamicArr = new A[3]; // A() A() A()

    delete[] dynamicArr; // ~A() ~A() ~A()
    // delete and delete[] call destructors of dynamically allocated objects
}
// ~A() ~A() ~A() ~A()  (arr and obj are erased at the end of the scope)
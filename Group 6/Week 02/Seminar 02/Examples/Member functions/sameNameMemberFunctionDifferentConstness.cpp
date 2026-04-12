#include <iostream>

using std::cout;
using std::endl;

// The compiler automatically picks which of the two functions with the same name to call, based on the constness

struct A {

    void f() {
        cout << "Not const f()" << endl;
    }

    void f() const {
        cout << "Const f()" << endl;
    }
};

void func1(A& a) {
    a.f(); // Not const f()
}

void func2(const A& a) {
    a.f(); // Const f()
}

int main() {
    A obj;
    obj.f(); // Not const f()

    const A objConst;
    objConst.f(); // Const f()

    func1(obj);
    func2(obj);
}

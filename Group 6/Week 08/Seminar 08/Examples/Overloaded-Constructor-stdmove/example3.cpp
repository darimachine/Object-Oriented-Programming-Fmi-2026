
#include <iostream>
#include <crtdbg.h>

using namespace std;
class T {
public:
    T() { cout << "T()\n"; }
    T(const T&) { cout << "copy T()\n"; }
    T(T&&) noexcept { cout << "move T()\n"; }
};
T foo() {
    T t;
    return t;
}
int main() {
    T x = foo();
    return 0;
}

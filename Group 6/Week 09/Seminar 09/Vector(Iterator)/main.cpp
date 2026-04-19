#include <iostream>
#include "Vector.hpp"

int main() {
    // --- Конструктори ---
    Vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(1);
    v.push_back(5);

    std::cout << "operator<<:\n" << v << "\n";
    std::cout << "size: " << v.getSize() << "\n";
    std::cout << "capacity: " << v.getCapacity() << "\n";

    // --- operator[] ---
    std::cout << "v[0] = " << v[0] << "\n";
    v[0] = 99;
    std::cout << "v[0] след промяна = " << v[0] << "\n";

    // --- Iterator (range-based for) ---
    std::cout << "Iterator: ";
    for (const auto& x : v)     // begin() / end()
        std::cout << x << " ";
    std::cout << "\n";

    // --- Iterator ръчно ---
    std::cout << "Iterator ръчно: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // --- ReverseIterator ---
    std::cout << "ReverseIterator: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // --- ConstIterator ---
    const Vector<int> cv = v;
    std::cout << "ConstIterator: ";
    for (auto it = cv.cbegin(); it != cv.cend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // --- Copy конструктор ---
    Vector<int> v2 = v;
    std::cout << "Copy: " << v2 << "\n";

    // --- Move конструктор ---
    Vector<int> v3 = std::move(v2);
    std::cout << "Move: " << v3 << "\n";
    std::cout << "v2 size след move: " << v2.getSize() << "\n";

    // --- operator<=> ---
    Vector<int> a, b;
    a.push_back(1); a.push_back(2);
    b.push_back(1); b.push_back(3);

    std::cout << "a < b: " << (a < b) << "\n";  // true
    std::cout << "a == b: " << (a == b) << "\n";  // false
    std::cout << "a > b: " << (a > b) << "\n";  // false
}
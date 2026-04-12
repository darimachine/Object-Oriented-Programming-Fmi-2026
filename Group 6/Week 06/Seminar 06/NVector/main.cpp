
#include <iostream>
#include "NVector.h"
int main()
{
    NVector v(4);
    std::cin >> v;          // напр. 1 2 3 4

    NVector v2(4);
    std::cin >> v2;         // напр. 4 3 2 1

    NVector result = v + v2;
    std::cout << result << "\n";                  // {5, 5, 5, 5}

    result *= 2;
    std::cout << "Scaled: " << result << "\n";    // {10, 10, 10, 10}

    if (v | v2)
        std::cout << "Перпендикулярни\n";

    if (v || v2)
        std::cout << "Успоредни\n";

    // operator bool
    NVector zero(3);
    if (!zero) std::cout << "Нулев вектор\n";
    if (v)     std::cout << "v е ненулев\n";

    // operator() с ламбда
    NVector squares = v([](int x) { return x * x; });
    std::cout << "Квадрати: " << squares << "\n";

    // operator~
    std::cout << "Размер: " << ~v << "\n";

    // Оператори за сравнение
    int arr1[3] = { 1,2,3 };
    int arr2[3] = { 1,2,4 };
    int arr3[3] = { 1,2,3 };
    NVector va(arr1, 3);
    NVector vb(arr2, 3);
    NVector vc(arr3, 3);

    std::cout << (va == vc ? "равни" : "различни") << "\n";  // равни
    std::cout << (va < vb ? "va < vb" : "va >= vb") << "\n";  // va < vb
    std::cout << (vb > va ? "vb > va" : "vb <= va") << "\n";  // vb > va

    // С operator<=>
    auto cmp = va <=> vb;
    if (cmp < 0)       std::cout << "va е лексикографски по-малък\n";
    else if (cmp == 0) std::cout << "равни\n";
    else               std::cout << "va е лексикографски по-голям\n";

}

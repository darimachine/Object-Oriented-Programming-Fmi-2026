
#include <iostream>
#include "IDGeneratorSingleton.h"
int main()
{
    // IDGeneratorSingleton gen;   ← ❌ конструкторът е private

   // Единственият начин за достъп:
    std::cout << IDGeneratorSingleton::getInstance().generate() << "\n";  // 1
    std::cout << IDGeneratorSingleton::getInstance().generate() << "\n";  // 2
    std::cout << IDGeneratorSingleton::getInstance().generate() << "\n";  // 3

    // Проверка — винаги един и същ обект:
    IDGeneratorSingleton& a = IDGeneratorSingleton::getInstance();
    IDGeneratorSingleton& b = IDGeneratorSingleton::getInstance();

    std::cout << (&a == &b ? "Един и същ обект" : "Различни") << "\n";
    // Един и същ обект

    // Продължаваме от там, където спряхме:
    std::cout << a.generate() << "\n";  // 4
    std::cout << b.generate() << "\n";  // 5  ← a и b са едно и също
    std::cout << a.getId() << "\n";  // 6  ← следващото незададено

    a.print();   // Next ID: 6
}
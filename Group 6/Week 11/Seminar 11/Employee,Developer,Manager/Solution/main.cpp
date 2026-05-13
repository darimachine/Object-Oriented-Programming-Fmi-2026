#include <iostream>
#include "Manager.h"
#include "Developer.h"
using namespace std;

int main()
{
    Employee e("Иван Иванов", "ivan@company.bg", 2500.0);
    e.print();

    Developer dev("Мария Петрова", "maria@company.bg", 3800.0, "C++");
    dev.addTechnology("STL");
    dev.addTechnology("CMake");
    dev.addTechnology("Git");
    dev.print();

    std::cout << dev.hasTechnology("Git") << "\n";   // 1
    std::cout << dev.hasTechnology("Docker") << "\n";   // 0

    Manager mgr("Петър Георгиев", "peter@company.bg", 5200.0, "Engineering");
    mgr.addSubordinate("Иван Иванов");
    mgr.addSubordinate("Мария Петрова");
    mgr.print();

    std::cout << "Екип: " << mgr.getTeamSize() << " души\n";

    // Сравнение по заплата:
    std::cout << (dev < mgr) << "\n";   // 1 — 3800 < 5200

    // Copy — компилаторът генерира правилен copy constructor:
    Developer dev2 = dev;
    dev2.addTechnology("Docker");
    dev2.print();   // dev2 има Docker, dev — не

    cout << dev2;
}
#include <iostream>
#include"Warehouse.h"

int main()
{
    Warehouse sofia("Sofia", 10);
    Warehouse plovdiv("Plovdiv", 5);

    sofia.addPackage("BG001", "Ivan Ivanov", 2.5, Priority::NORMAL);
    sofia.addPackage("BG002", "Mariya Petrova", 0.8, Priority::URGENT);
    sofia.addPackage("BG003", "Petyr Georgiev", 5.1, Priority::EXPRESS);

    std::cout << sofia << "\n";

    sofia.transferTo("BG003", plovdiv);

    if (Package* p = sofia.operator[]("BG001"))
        std::cout << "Find: " << *p << "\n";

    if (Package* p = sofia.heaviestPackage())
        std::cout << "Heaviest: " << *p << "\n";

    std::cout << "Urgent packages: " << sofia.urgentPackages() << "\n";
    std::cout << "Total weight: " << sofia.totalWeight() << " kg.\n";

    sofia("BG001", Priority::URGENT)("BG002", Priority::EXPRESS);

    if (sofia)
        std::cout << "Warehouse is overworked!\n";
    else
        std::cout << "Warehouse works normal.\n";

    std::cout << plovdiv << "\n";
}

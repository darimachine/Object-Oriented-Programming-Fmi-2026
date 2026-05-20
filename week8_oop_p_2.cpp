#include <iostream>
#include "VehicleList.h"

int main() {
    Registration r1("C1234AB");
    Registration r2("C5678XY");
    Registration r3("XY1111AB");

    std::cout << r1 << "\n";

    Vehicle v1(r1, "Honda Civic", 2019, 150);
    Vehicle v2(r2, "Toyota Yaris", 2021, 120);
    Vehicle v3(r3, "BMW X5", 2019, 250);


    std::cout << v1 << "\n";
    std::cout << (v1 < v2 ? "v1 is older" : "v2 is older") << "\n";
    std::cout << (v1 < v3 ? "v1 is weaker" : "v3 is weaker") << "\n";

    VehicleList list(10);

    list += v1;
    list += v2;
    list += v3;
    list += v1;  // ignored — duplicate plate

    std::cout << list.getCount() << "\n";      // 3
    std::cout << list.getCapacity() << "\n";   // 10
    std::cout << list.isEmpty() << "\n";       // false
    std::cout << list.isFreeSlot(3) << "\n";   // true

    if (list)
        std::cout << "List is valid\n";

    std::cout << list << "\n";
    // [C1234AB] [C5678XY] [XY1111AB] [*] [*] ...

    std::cout << list("C") << "\n";    // 2 — v1 and v2
    std::cout << list("XY") << "\n";   // 1 — v3

    list -= r2;   // removes v2 -> slot 1 becomes nullptr

    std::cout << list.getCount() << "\n";   // 2
    std::cout << list << "\n";
    // [C1234AB] [*] [XY1111AB] [*] ...

    list += v2;   // adds to first free slot -> slot 1

    Vehicle* found = list.find(r1);
    if (found)
        std::cout << "Found: " << *found << "\n";

    VehicleList list2(5);
    list2 += v1;
    list2 += v2;

    std::cout << (list > list2 ? "list is larger" : "list2 is larger") << "\n";
}
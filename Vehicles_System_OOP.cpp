#include <iostream>
#include"VehicleList.h"

int main()
{
    Registration r1("C1234AB");
    Registration r2("C5678XY");
    Registration r3("XY1111AB");

    std::cout << r1 << "\n";   

    Vehicle v1(r1, "Honda Civic", 2019, 150);
    Vehicle v2(r2, "Toyota Yaris", 2021, 120);
    Vehicle v3(r3, "BMW X5", 2019, 250);

    std::cout << v1 << "\n";
    
    std::cout << (v1 < v2 ? "v1 is older" : "v2 is older") << "\n";  // v1
    
    std::cout << (v1 < v3 ? "v1 is less powered" : "v3 is less powered") << "\n";  // v1

    VehicleList list(10);

    list += v1;   
    list += v2;   
    list += v3;   
    list += v1;   

    std::cout << list.size() << "\n";   
    std::cout << list.getCapacity() << "\n";   
    std::cout << list.isEmpty() << "\n";   
    std::cout << list.isFreeSlot(3) << "\n"; 

    if (list)
        std::cout << "The list is valid\n";

    std::cout << list << "\n";
    

    std::cout << list("C") << "\n";   
    std::cout << list("XY") << "\n";  

    list -= r2;   

    std::cout << list.size() << "\n";  
    std::cout << list << "\n";
   

    list += v2;  

    Vehicle* found = list.find(r1);
    if (found)
        std::cout << "Find: " << *found << "\n";

    VehicleList list2(5);
    list2 += v1;
    list2 += v2;

    
    std::cout << (list > list2 ? "list is bigger" : "list2 is bigger") << "\n";
}


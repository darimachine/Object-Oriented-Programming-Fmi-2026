#include <iostream>
#include "Engine.h"
#include "Tire.h"
#include "Battery.h"

int main()
{
    try 
    {
        Engine e(1, "VAG", "Turbo Diesel", 150);
        Tire t(2, "Michelin", "Pilot Sport", 225, 45, 17);
        Battery b(3, "Bosch", "Silver S4", 74, "B-8821");

        std::cout << e << std::endl;
        std::cout << t << std::endl;
        std::cout << b << std::endl;
    }
    catch (const std::exception& ex) 
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
}

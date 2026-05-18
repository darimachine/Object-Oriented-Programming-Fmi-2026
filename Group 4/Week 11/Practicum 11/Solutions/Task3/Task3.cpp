#include <vector>
#include "Engine.h"
#include "Wheel.h"
#include "CarBattery.h"

int main() {
        Engine e1("VAG", "1.9 TDI - The Legend", 131);

        Wheel t1("Michelin", "Pilot Sport 4", 225, 45, 17);

         CarBattery b1("Bosch", "S5 Silver Plus", 74, "BOSCH-123456");

        std::cout << "--- Individual Parts ---" << std::endl;
        std::cout << e1 << std::endl;
        std::cout << t1 << std::endl;
        std::cout << b1 << std::endl;

    return 0;
}
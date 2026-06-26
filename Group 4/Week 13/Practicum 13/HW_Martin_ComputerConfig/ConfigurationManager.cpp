#include <iostream>
#include <memory>
#include <optional>
#include "Configuration.h"
#include "ComponentFactory.hpp"

int main()
{
    Configuration myPC;
    ComponentFactory factory;

    bool keepAdding = true;
    while (keepAdding) {
        std::cout << "--- Adding a new component ---\n";

        std::optional<std::unique_ptr<Component>> newCompOpt = factory.createComponent();

        if (newCompOpt.has_value()) {
            myPC.insert(newCompOpt.value());
            std::cout << "-> Component added successfully!\n\n";
        }
        else {
            std::cout << "-> Failed to create component.\n\n";
        }

        std::cout << "Do you want to add another component? (y/n): ";
        char userChoice;
        std::cin >> userChoice;

        std::cin.ignore(10000, '\n');

        if (userChoice != 'y' && userChoice != 'Y') {
            keepAdding = false;
        }
        std::cout << "\n";
    }

    std::cout << "===================================\n";
    std::cout << "FINAL SYSTEM CONFIGURATION:\n";
    std::cout << "===================================\n";
    std::cout << myPC;

    return 0;
}

//
// Created by Boris Bozhilov on 5/28/2026.
//

#include <iostream>
#include <string>

#include "ComponentFactory.h"
#include "Component.h"
#include "CPU.h"
#include "RAM.h"
#include "ROM.h"

Utils::ComponentTypes ComponentFactory::askUserForType(std::ostream &output, std::istream &input) {

    std::string userChoice;

    std::print(output,"Please enter the type of component that you want to create: ");
    input >> userChoice;

    std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(),
        [](unsigned char c){ return std::toupper(c); });

    if (userChoice == "CPU") return Utils::ComponentTypes::CPU;
    if (userChoice == "RAM") return Utils::ComponentTypes::RAM;
    if (userChoice == "ROM") return Utils::ComponentTypes::ROM;
    return Utils::ComponentTypes::Unknown;
}

std::optional<std::unique_ptr<Component> > ComponentFactory::createComponentFromType(std::ostream& output,
    std::istream& input) {

    Utils::ComponentTypes componentType = askUserForType(output, input);

    switch (componentType) {

        case Utils::ComponentTypes::CPU: {

            unsigned short cores = 0;
            unsigned short clockSpeed = 0;

            std::print(output, "Please enter number of cores and amount of clock speed for the CPU:\n");
            std::print(output, "Number of cores(1 to 8): ");
            input >> cores;
            std::print(output, "Amount of clock speed: ");
            input >> clockSpeed;

            try {
                return std::make_unique<CPU>(cores, clockSpeed);
            }
            catch (const std::invalid_argument& ex) {

                std::print(output, "Please enter correct values for the CPU parameters\n");
                output << ex.what();
                throw;
            }
            catch (...) {

                std::print(output, "Something went wrong when creating CPU");
                throw;
            }
        }

        case Utils::ComponentTypes::RAM: {

            unsigned short capacity = 0;

            std::print(output, "Please enter amount of capacity for the RAM:\n");
            std::print(output, "Amount of capacity(1 to 128): ");
            input >> capacity;

            try {
                return std::make_unique<RAM>(capacity);
            }
            catch (const std::invalid_argument& ex) {

                std::print(output, "Please enter correct values for the RAM parameters\n");
                output << ex.what();
                throw;
            }
            catch (...) {

                std::print(output, "Something went wrong when creating the RAM");
                throw;
            }
        }

        case Utils::ComponentTypes::ROM: {

            unsigned short capacity = 0;

            std::print(output, "Please enter amount of capacity for the ROM:\n");
            std::print(output, "Amount of capacity(1 to 10000): ");
            input >> capacity;

            try {
                return std::make_unique<ROM>(capacity);
            }
            catch (const std::invalid_argument& ex) {

                std::print(output, "Please enter correct values for the ROM parameters\n");
                output << ex.what();
                throw;
            }
            catch (...) {

                std::print(output, "Something went wrong when creating the ROM");
                throw;
            }
        }
        default: {

            std::print(output, "No such component exists");
            return std::nullopt;
        }
    }
}

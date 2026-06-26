#pragma once
#include <memory>
#include <string>
#include <optional>
#include <stdexcept>
#include <iostream>
#include "Component.h"
#include "CPU.h"
#include "Memory.h"

class ComponentFactory {
public:
    std::optional<std::unique_ptr<Component>> createComponent()
    {
        std::cout << "Choose type of component (1 for CPU, 2 for Memory): ";
        int choice;
        if (!(std::cin >> choice)) 
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return std::nullopt;
        }

        std::cin.ignore(10000, '\n'); 

        std::string ticket;
        std::cout << "Insert ticket: ";
        std::getline(std::cin, ticket);

        try {
            if (choice == 1) {
                unsigned short cores;
                unsigned short clockSpeed;

                std::cout << "Insert cores (1-8): ";
                std::cin >> cores;
                std::cout << "Insert frequency (MHz): ";
                std::cin >> clockSpeed;

                if (!std::cin) throw std::runtime_error("Invalid input");

                return std::make_unique<CPU>(ticket, cores, clockSpeed);

            }
            else if (choice == 2) {
                unsigned short capacity;

                std::cout << "Insert capacity (1-10000 GB): ";
                std::cin >> capacity;

                if (!std::cin) throw std::runtime_error("Invalid input");

                return std::make_unique<Memory>(ticket, capacity);
            }
            else {
                std::cout << "????????? ????? ?? ?????????.\n";
                return std::nullopt;
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error with creation: " << e.what() << "\n";

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            return std::nullopt;
        }
    }
};
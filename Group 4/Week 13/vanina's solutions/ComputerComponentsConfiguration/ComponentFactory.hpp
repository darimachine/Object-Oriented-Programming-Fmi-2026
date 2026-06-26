#pragma once

#include <optional>
#include<iostream>

#include "Component.h"
#include "CPU.h"
#include "Memory.h"

class ComponentFactory {
public:
    static std::optional<std::unique_ptr<Component>> createComponent() {
        std::cout << "enter component type (cpu or memory): ";
        std::string type;
        std::cin >> type;

        if ("cpu" == type) {
            std::string name;
            std::cout << "label: "; std::cin >> name;
            int core;
            std::cout << "cores: "; std::cin >> core;
            int clock;
            std::cout << "clock speed: "; std::cin >> clock;

            return std::make_unique<CPU>(name, core, clock);
        }
        if ("memory" == type) {
            std::string name;
            std::cout << "label: "; std::cin >> name;
            int cap;
            std::cout << "capacity in GBs: "; std::cin >> cap;

            return std::make_unique<Memory>(name, cap);
        }

        return std::nullopt;;
    }
};
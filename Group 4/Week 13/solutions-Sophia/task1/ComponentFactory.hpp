#pragma once
#include <Component.h>
#include <CPU.h>
#include <Memory.h>
#include <optional>
#include <iostream>

class ComponentFactory
{
public:
    static std::optional <std::unique_ptr<Component>> createComponent(const std::string& type, const std::string& name, const unsigned short param1, const unsigned short param2 = 0)
    {
        std::cout << "enter your choice {CPU or Memory}: ";
        std::string choice;
        std::cin >> choice;
        if (type == "CPU") {
            std::string name;
            std::cout << "label: " << name;
            int core;
            std::cout << "cores: " << core;
            int clock_speed;
            std::cout << "clock_speed: " << clock_speed;

            return std::make_unique<CPU>(name, core, clock_speed);
        }
        if (type == "Memory") {
            std::string name;
            std::cout << "label: " << name;
            int capacity;
            std::cout << "capacity: " << capacity;

            return std::make_unique<CPU>(name, capacity);
        }
        return std::nullopt;
    }
};
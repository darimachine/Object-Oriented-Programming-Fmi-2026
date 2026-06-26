//
// Created by Vanina Laleva on 2.05.26.
//

#ifndef REPAIRMAN_ENGINE_H
#define REPAIRMAN_ENGINE_H
#include "CarPart.h"


class Engine : public CarPart {
    unsigned horsepower;

public:
    Engine(const std::string& manufacturer, const std::string& description, unsigned horsepower);

    friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};


#endif //REPAIRMAN_ENGINE_H
//
// Created by Vanina Laleva on 2.05.26.
//

#include "Engine.h"

Engine::Engine(const std::string &manufacturer, const std::string &description,
    unsigned horsepower) : CarPart(manufacturer, description), horsepower(horsepower) {
}

std::ostream & operator<<(std::ostream &os, const Engine &engine) {
    os << (CarPart) engine;
    os << engine.horsepower << " hp";
    return os;
}

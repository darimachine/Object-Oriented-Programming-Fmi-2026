//
// Created by Vanina Laleva on 2.05.26.
//

#include "CarPart.h"

unsigned CarPart::idCounter = 0;

CarPart::CarPart(const std::string& name, const std::string& description) : name(name), description(description) {
    id = idCounter++;
}

std::ostream & operator<<(std::ostream &os, const CarPart &part) {
    os << "(" << part.id << ") by " << part.name << " - " << part.description << " - ";
    return os;
}

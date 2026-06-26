//
// Created by Vanina Laleva on 2.05.26.
//

#include "Tire.h"

Tire::Tire(const std::string& manufacturer, const std::string& description,
    unsigned weight, unsigned profile, unsigned diameter) : CarPart(manufacturer, description) {
    if (weight < 155 || weight > 365) {
        throw std::out_of_range("weight out of range (155-365)");
    }
    if (profile < 30 || profile > 80) {
        throw std::out_of_range("profile out of range (30-80)");
    }
    if (diameter < 13 || diameter > 21) {
        throw std::out_of_range("diameter out of range (155-365)");
    }

    this->weight = weight;
    this->profile = profile;
    this->diameter = diameter;
}

std::ostream & operator<<(std::ostream &os, const Tire &tire) {
    os << (CarPart) tire;
    os << tire.weight << "/" << tire.profile << "R" << tire.diameter;
    return os;
}

#include "Animal.h"

Animal::Animal(const std::string& name) : name(name) {}

const std::string& Animal::getName() const {
    return name;
}

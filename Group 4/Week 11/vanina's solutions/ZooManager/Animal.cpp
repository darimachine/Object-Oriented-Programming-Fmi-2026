#include "Animal.h"

Animal::Animal(const std::string& name, const std::string& type,
    unsigned age) : name(name), type(type), age(age) {
}

const std::string & Animal::getType() const {
    return type;
}

const std::string & Animal::getName() const {
    return name;
}

void Animal::print() const {
    std::cout << name << " - " << type << "(" << age << ")" << std::endl;
}

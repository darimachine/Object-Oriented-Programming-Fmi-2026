#include "Pig.h"

Pig::Pig(const std::string& name) : Animal(name) {}

void Pig::makeSound() const {
    std::cout << name << " says Oink oink!" << std::endl;
}

std::unique_ptr<Animal> Pig::clone() const {
    return std::make_unique<Pig>(*this);
}

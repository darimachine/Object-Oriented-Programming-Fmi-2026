#include "Sheep.h"

Sheep::Sheep(const std::string& name) : Animal(name) {}

void Sheep::makeSound() const {
    std::cout << name << " says Baaaaaaeeeaaea!" << std::endl;
}

std::unique_ptr<Animal> Sheep::clone() const {
    return std::make_unique<Sheep>(*this);
}

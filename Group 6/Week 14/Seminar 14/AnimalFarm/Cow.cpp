#include "Cow.h"

Cow::Cow(const std::string& name) : Animal(name) {}

void Cow::makeSound() const {
    std::cout << name << " says Moooooooo!" << std::endl;
}

std::unique_ptr<Animal> Cow::clone() const {
    return std::make_unique<Cow>(*this);
}

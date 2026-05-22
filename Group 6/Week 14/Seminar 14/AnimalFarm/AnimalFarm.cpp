#include "AnimalFarm.h"

void AnimalFarm::free() {
    animals.clear();
}

void AnimalFarm::copyFrom(const AnimalFarm& other) {
    animals.reserve(other.animals.size());
    for (const auto& animal : other.animals)
        animals.push_back(animal->clone());
}

AnimalFarm::AnimalFarm(const AnimalFarm& other) {
    copyFrom(other);
}

AnimalFarm& AnimalFarm::operator=(const AnimalFarm& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

void AnimalFarm::addAnimal(const Animal& animal) {
    animals.push_back(animal.clone());
}

void AnimalFarm::addAnimal(const std::unique_ptr<Animal>& animal) {
    if (!animal) {
        throw std::invalid_argument("Can't add null animal!");
    }
    animals.push_back(animal->clone());
}

void AnimalFarm::wakeUpAnimals() const {
    for (const auto& animal : animals)
        animal->makeSound();
}

#include "Exhibit.h"

Exhibit::Exhibit(const std::string &location, const std::string &type, int animalCount,
    int capacity) : location(location), type(type), animalCount(animalCount), capacity(capacity) {
}

const std::string & Exhibit::getLocation() const {
    return location;
}

bool Exhibit::addAnimal(const Animal &animal) {
    if (animalCount >= capacity) {
        // throw std::out_of_range("the exhibit is full");
        std::cout << "the exhibit is full\n";
        return false;
    }

    animals.push_back(std::make_unique<Animal>(animal));
    animalCount++;
    return true;
}

bool Exhibit::addAnimal(const std::string &name, const std::string &type, unsigned age) {
    // Animal animal(name, type, age);
    if(addAnimal(Animal(name, type, age))) {
        return true;
    }
    return false;
}

bool Exhibit::isFull() const {
    return animalCount == capacity;
}

Animal* Exhibit::search(const std::string &name) const {
    for (const auto& animal:animals) {
        if (animal->getName() == name) {
            return animal.get();
        }
    }
    return nullptr;
}

void Exhibit::printAnimals() const {
    std::cout << location << ":\n";
    for (const auto& animal : animals) {
        std::cout << animal->getName() << " - " << animal->getType() << std::endl;
    }
}

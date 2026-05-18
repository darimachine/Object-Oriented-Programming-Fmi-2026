#pragma once
#include "Animal.h"
#include <vector>
#include <string>

class Exhibit {
    std::string location;
    std::string animalType;
    std::vector<Animal> animals;
    size_t animalCapacity;

public:
    Exhibit(std::string location, std::string animalType, size_t capacity = 8);

    void addAnimal(const Animal& animal);
    bool isFull() const;

    const std::string& getLocation() const;
    const std::string& getAnimalType() const;
    const std::vector<Animal>& getAnimals() const;

};
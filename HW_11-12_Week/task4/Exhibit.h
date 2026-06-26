#pragma once
#include <string>
#include <vector>
#include "Animal.h"
class Exhibit
{
    std::string location;
    std::string animalType;
    size_t capacity;
    std::vector<Animal> animals;
public:
    Exhibit(const std::string& location, const std::string& animalType, size_t capacity);
    void addAnimal(const Animal& animal);
    bool isFull() const;
    const std::string& getLocation() const;
    const std::string& getAnimalType() const;
    const std::vector<Animal>& getAnimals() const;
    void print() const;
};


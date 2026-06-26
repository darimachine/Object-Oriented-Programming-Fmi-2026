#include "Exhibit.h"
#include "ZooException.h"
#include <iostream>
Exhibit::Exhibit(const std::string& location, const std::string& animalType, size_t capacity) : location(location), animalType(animalType), capacity(capacity)
{
    if (location.empty())
    {
        throw ZooException("Exhibit location cannot be empty.");
    }
    if (animalType.empty())
    {
        throw ZooException("Exhibit animal type cannot be empty.");
    }
    if (capacity == 0) 
    {
        throw ZooException("Exhibit capacity must be at least 1.");
    }
}

void Exhibit::addAnimal(const Animal& animal)
{
    if (isFull())
    {
        throw ZooException("Exhibit at '" + location + "' is full.");
    }
    if (animal.getSpecies() != animalType)
    { 
        throw ZooException("Animal species '" + animal.getSpecies() +" does not match exhibit type " + animalType + "");
    }
    animals.push_back(animal);
}

bool Exhibit::isFull() const
{
    return animals.size() >= capacity;
}

const std::string& Exhibit::getLocation() const
{
    return location;
}

const std::string& Exhibit::getAnimalType() const
{
    return animalType;
}

const std::vector<Animal>& Exhibit::getAnimals() const
{
    return animals;
}

void Exhibit::print() const
{
    std::cout << "Exhibit: " << location << " | type: " << animalType
        << " | " << animals.size() << "/" << capacity << std::endl;;
    for (const auto& animal : animals)
    {
        animal.print();
    }
}
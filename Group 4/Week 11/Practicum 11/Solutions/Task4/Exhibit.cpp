#include "Exhibit.h"

Exhibit::Exhibit(std::string location, std::string animalType, size_t capacity) : location(std::move(location)), animalType(std::move(animalType)), animalCapacity(capacity) { }

void Exhibit::addAnimal(const Animal& animal) {
    if (!isFull() && animal.getType() == animalType)
    {
        animals.push_back(animal);
    }
}

bool Exhibit::isFull() const 
{ 
    return animals.size() >= animalCapacity; 
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
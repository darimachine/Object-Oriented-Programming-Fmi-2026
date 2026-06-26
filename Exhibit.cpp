#include "Exhibit.h"

Exhibit::Exhibit(std::string location, std::string speciesType, int capacity)
: location(location), speciesType(speciesType), capacity(capacity)  {}

bool Exhibit::addAnimal(const Animal& animal)
{
	if (isFull()) {
	return false;
	}
	else {
		animals.push_back(animal);
		return true;
	}
}

bool Exhibit::isFull() const
{
	return animals.size() >= capacity;
}

void Exhibit::print() const
{
	std::cout << "Exhibit at " << location << " [" << speciesType << "] ("
		<< animals.size() << "/" << capacity << "):" << std::endl;
	for (const auto& a : animals) a.print();
}

const std::vector<Animal>& Exhibit::getAnimals() const
{
	return animals;
}


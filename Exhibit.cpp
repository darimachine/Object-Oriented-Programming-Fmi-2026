#include "Exhibit.h"
#include<stdexcept>

Exhibit::Exhibit(const string& location, const string& animalType,size_t capacity):location(location),
	animalType(animalType),countAnimals(0),capacity(capacity){ }

bool Exhibit::isFull()const
{
	return countAnimals >= capacity;
}

void Exhibit::addAnimal()
{
	if (isFull())
	{
		throw std::runtime_error("Exhibit is full!");
	}
	countAnimals++;
}

const string& Exhibit::getLocation()const
{
	return location;
}

ostream& operator<<(ostream& os, const Exhibit& e)
{
	return os << e.location << " " << e.animalType << " " << e.countAnimals << '\n';
}

const string& Exhibit::getAnimalType()const
{
	return animalType;
}

void Exhibit::removeAnimal()
{
	if (countAnimals == 0)
	{
		throw std::runtime_error("No animals to remove!");
	}
	countAnimals--;
}
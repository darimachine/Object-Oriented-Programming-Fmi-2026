#include "Exhibit.h"
#include <stdexcept>
#include <print>
Exhibit::Exhibit(const std::string& inpLocation, const std::string& inpSpecies, size_t inpCapacity)
	: location(inpLocation), species(inpSpecies), capacity(inpCapacity)
{
}

void Exhibit::addAnimal(const Animal& joiningAnimal)
{
	if (joiningAnimal.getSpecies() != species)
	{
		throw std::invalid_argument("The species does not belong here");
	}

	if (animals.size() < capacity)
	{
		animals.push_back(joiningAnimal);
	}
	else
	{
		throw std::overflow_error("The capacity is full. The animal can not join");
	}
}

bool Exhibit::isFull() const
{
	return animals.size() == capacity;
}

const std::string& Exhibit::getSpecies() const
{
	return species;
}

void Exhibit::print() const
{
	std::println("Location: {}, species: {}, capacity: {}", location, species, capacity);
	
	for (const auto& currAnimal : animals)
	{
		currAnimal.print();
	}
}

bool Exhibit::containsAnimal(const std::string& searchedName) const
{
	for (const auto& animal : animals)
	{
		if (animal.getName() == searchedName)
		{
			return true;
		}
	}
	return false;
}

#include "Exhibit.h"
#include <iostream>
#include <string>

Exhibit::Exhibit(const std::string& _location, const unsigned int _capacity, const AnimalType _type)
	:location(_location), capacity(_capacity), type(_type) {}

std::string Exhibit::getLocation() const
{
	return location;
}

AnimalType Exhibit::getType() const
{
	return type;
}

unsigned int Exhibit::getCapacity() const
{
	return capacity;
}

bool Exhibit::isFull() const
{
	return animals.size() >= capacity;
}

bool Exhibit::addAnimal(std::shared_ptr<Animal> animal)
{
	bool result = false;
	if (animal && animal->getType() == type) {
		if (!isFull()) {
			animals.push_back(animal);
			result = true;
		}
		else {
			std::cout << "Error! There is no free space in the exhibit." << std::endl;
		}
	}
	else {
		std::cout << "Error! The animal is not suitable for this exhibit." << std::endl;
	}

	return result;
}

bool Exhibit::searchAnimal(const std::string& name) const
{
	if (!name.empty()) {
		for (const auto& animal : animals) {
			if (animal && animal->getName() == name) {
				std::cout << "The animal " << name << " is located in " << getLocation() << std::endl;
				return true;
			}
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Exhibit& ex)
{
	os << "< " << ex.getLocation() << " | Capacity: " << ex.getCapacity() << " >" << std::endl;

	for (const auto& animal : ex.animals)
	{
		if (animal)
			os << *animal << std::endl;
	}

	return os;
}

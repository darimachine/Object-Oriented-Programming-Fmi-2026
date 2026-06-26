#include "Animal.h"

Animal::Animal(const AnimalType _type, const std::string& _name, size_t _age)
	: type(_type), name(_name), age(_age) {}

AnimalType Animal::getType() const
{
	return type;
}

std::string Animal::getName() const
{
	return name;
}

size_t Animal::getAge() const
{
	return age;
}

std::string Animal::animalType() const
{
	std::string aType = "Unknown type";

	switch (type) {
	case AnimalType::Bird: aType = "Bird"; break;
	case AnimalType::Mammal: aType = "Mammal"; break;
	case AnimalType::Reptyle: aType = "Reptile"; break;
	default: break;
	}
	return aType;
}

std::ostream& operator<<(std::ostream& os, const Animal& a)
{
	os << a.getName() << " | " << a.animalType() << " | Age: " << a.getAge();

	return os;
}

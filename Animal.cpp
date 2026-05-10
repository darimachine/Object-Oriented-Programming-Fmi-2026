#include "Animal.h"

Animal::Animal(std::string name, std::string type, int age)
:name(name), type(type), age(age) {}

std::string Animal::getName() const
{
	return name;
}

void Animal::print() const
{
	std::cout << "Animal: " << name << " (" << type << "), Age: " << age << std::endl;
}


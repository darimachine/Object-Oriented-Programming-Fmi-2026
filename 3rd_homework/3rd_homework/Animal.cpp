#include "Animal.h"
#include <iostream>
#include <print>
Animal::Animal(const std::string& inpName, unsigned inpAge, const std::string& inpSpecies): 
	name(inpName), age(inpAge), species(inpSpecies)
{}

const std::string& Animal::getSpecies() const
{
	return species;
}

const std::string& Animal::getName() const
{
	return name;
}
unsigned Animal::getAge() const
{
	return age;
}

void Animal::print() const
{
	std::println("Species: {}, Name: {}, Age: {} ",species, name, age );
}
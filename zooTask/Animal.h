#pragma once
#include <string>
#include <iostream>

enum class AnimalType {
	Bird,
	Mammal,
	Reptyle
};

class Animal
{
	AnimalType type;
	std::string name;
	size_t age;

public:
	Animal(const AnimalType _type, const std::string& _name, size_t _age);

	AnimalType getType() const;
	std::string getName() const;
	size_t getAge() const;

	std::string animalType() const;

	friend std::ostream& operator<<(std::ostream& os, const Animal& a);
};


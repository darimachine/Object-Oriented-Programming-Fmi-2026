#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Animal.h"

class Exhibit
{
	std::vector <std::shared_ptr<Animal>> animals;
	AnimalType type;
	std::string location;
	unsigned int capacity;
public:
	Exhibit(const std::string& _location, const unsigned int _capacity, const AnimalType _type);

	std::string getLocation() const;
	AnimalType getType() const;
	unsigned int getCapacity() const;

	bool isFull() const;

	bool addAnimal(std::shared_ptr<Animal> animal);
	bool searchAnimal(const std::string& name) const;

	friend std::ostream& operator<<(std::ostream& os, const Exhibit& ex);
};


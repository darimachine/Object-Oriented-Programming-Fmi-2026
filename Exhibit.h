#pragma once
#include <string>
#include <vector>
#include "Animal.h"
#include <iostream>

class Exhibit {
	std::string location;
	std::string speciesType;
	int capacity;
	std::vector<Animal> animals;

	public:
	Exhibit(std::string location, std::string speciesType, int capacity);

	bool addAnimal(const Animal& animal);
	bool isFull() const;

	void print() const;

	const std::vector<Animal>& getAnimals() const;
};

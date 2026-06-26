#pragma once
#include "Animal.h"
#include <string>
#include <vector>
class Exhibit
{
	private:
		std::string location;
		std::string species;
		size_t capacity;
		std::vector <Animal> animals;
	
	public:
		Exhibit(const std::string& inpLocation, const std::string& inpSpecies, size_t inpCapacity);
		void addAnimal(const Animal& joiningAnimal);
		bool isFull() const;

		const std::string& getSpecies() const;
		void print() const;

		bool containsAnimal(const std::string& searchedName) const;
};


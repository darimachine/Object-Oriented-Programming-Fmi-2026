#pragma once
#include"Animal.h"
#include<vector>
#include<fstream>

class Exhibit
{
private:
	string location;
	string animalType;
	size_t countAnimals;
	size_t capacity;

public:
	Exhibit() = default;
	Exhibit(const string& location, const string& animalType,size_t capacity);

	bool isFull()const;
	void addAnimal();
	void removeAnimal();

	const string& getLocation()const;
	const string& getAnimalType()const;

	friend ostream& operator<<(ostream& os, const Exhibit& e);
};


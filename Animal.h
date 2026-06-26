#pragma once
#include <string>
#include <iostream>

class Animal {
	std::string name;
	std::string type;
	int age;

	public:

	Animal(std::string name, std::string type, int age);
	std::string getName() const;

	void print() const;
};

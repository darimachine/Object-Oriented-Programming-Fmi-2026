#pragma once
#include <string>
class Animal
{
	private:
		std::string name;
		unsigned age;
		std::string species;

	public:

		Animal(const std::string&, unsigned, const std::string&);

		const std::string& getName() const;
		const std::string& getSpecies() const;
		unsigned getAge() const;

		void print() const;
};


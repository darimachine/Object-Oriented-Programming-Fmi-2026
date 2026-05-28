#pragma once
#include <string>
#include <iostream>

class Cartographer {
	std::string name;
	int yearsExperience;

	public:
	Cartographer(const std::string& name, int yearsExperience);
	virtual ~Cartographer() = default;

	virtual std::string getRole() const = 0;
	virtual void print() const;
};

#pragma once
#include <string>
#include <iostream>

class CarPart {
protected:
	unsigned int id;
	std::string name;
	std::string descriptiom;

	public:
	CarPart(unsigned int id, std::string name, std::string descriptiom);
	virtual ~CarPart() = default;


	virtual void printInfo(std::ostream& os) const = 0;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& part);
};

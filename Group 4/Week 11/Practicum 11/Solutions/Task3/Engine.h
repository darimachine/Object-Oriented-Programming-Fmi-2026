#pragma once
#include "CarPart.h"
class Engine : public CarPart
{
	unsigned horsePower;
public:
	Engine(std::string manufacturerName, std::string description, unsigned horsePower);

	unsigned getHorsePower() const;
	void setHorsePower(unsigned horsePower);

	friend std::ostream& operator<<(std::ostream& os, const Engine& e);
};


#pragma once
#include "CarPart.h"

class Engine : public CarPart {
	int horsePower;
	public:
	Engine(unsigned int id, std::string n, std::string desc, int hp);
	void printInfo(std::ostream& os) const override;
};

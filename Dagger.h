#pragma once
#include"Weapon.h"

class Dagger:public Weapon
{
private:
	bool thrown = false;

public:
	Dagger() = default;
	explicit Dagger(const std::string& name);

	int roll()const override;
	int throwDagger();
	void pickUp();
	bool isThrown()const { return thrown; }
};


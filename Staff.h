#pragma once
#include"Weapon.h"

class Staff:public Weapon
{
private:
	int maxMana;

public:
	Staff() = default;
	Staff(const std::string& name,int maxMana);

	int roll()const override;
};


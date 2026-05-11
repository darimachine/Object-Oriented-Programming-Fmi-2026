#pragma once
#include"Weapon.h"

class Sword:public Weapon
{
private:
	static constexpr int FIXED_VALUE = 10;

public:
	Sword() = default;
	explicit Sword(const std::string& name);

	int roll()const override;
};


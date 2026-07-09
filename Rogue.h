#pragma once
#include"Character.h"
#include"Dagger.h"

class Rogue:public Character
{
private:
	int critChance;

public:
	Rogue(const std::string& name, int hp, int maxHp, Weapon* weapon, int critChance);

	void attack(Character& target)override;
	void defend(int incomingDamage)override;
	void rest()override;
	const std::string statusLine()const override;
};


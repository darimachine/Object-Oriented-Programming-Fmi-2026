#pragma once
#include"Character.h"

class Warrior:public Character
{
private:
	int armor;

public:
	Warrior(const std::string& name, int hp, int maxHp, Weapon* weapon, int armor);

	void attack(Character& target)override;
	void defend(int incomingDamage) override;
	void rest()override;
	const std::string statusLine()const override;
};


#pragma once
#include"Character.h"
#include"OutOfManaException.h"

class Mage :public Character
{
private:
	int mana;
	int maxMana;

public:
	Mage(const std::string& name, int hp, int maxHp, Weapon* weapon, int mana, int maxMana);

	void attack(Character& target)override;
	void defend(int incomingDamage)override;
	void rest()override;
	const std::string statusLine()const override;
};


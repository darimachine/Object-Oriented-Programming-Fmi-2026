#include "Character.h"

Character::Character(const std::string& name, int hp, int maxHp,Weapon* weapon):
	name(name),hp(hp),maxHp(maxHp),weapon(weapon){ }

bool Character::isDead()const
{
	return hp == 0;
}

void Character::takeDamage(int amount)
{
	if (isDead())
	{
		throw DeadCharacterException(name);
	}

	defend(amount);

	if (hp < 0)
	{
		hp = 0;
	}
}

const std::string& Character::getName()const
{
	return name;
}

int Character::getHp()const
{
	return hp;
}

Weapon* Character::getWeapon()const
{
	return weapon;
}

int Character::getMaxHp()const
{
	return maxHp;
}

void Character::setHp(int hp)
{
	this->hp = hp;
}

void Character::setStunned(bool value)
{
	stunned = value;
}

bool Character::isStunned()const
{
	return stunned;
}

void Character::addDamageReduction(int amount)
{
	damageReduction += amount;
}

int Character::consumeDamageReduction()
{
	int tmp = damageReduction;
	damageReduction = 0;
	return tmp;
}

std::vector<std::unique_ptr<StatusEffect>>& Character::getEffects()
{
	return effects;
}

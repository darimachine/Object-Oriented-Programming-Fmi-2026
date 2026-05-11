#include "Warrior.h"

Warrior::Warrior(const std::string& name, int hp, int maxHp, Weapon* weapon, int armor):
	Character(name,hp,maxHp,weapon),armor(armor){ }

void Warrior::attack(Character& target)
{
	if (isDead())
	{
		throw DeadCharacterException(getName());
	}

	if (stunned)
	{
		stunned = false;
		return;
	}

	int damage = getWeapon()->roll();
	target.takeDamage(damage);
}

void Warrior::defend(int incomingDamage)
{
	int reduction = consumeDamageReduction();

	int damage = incomingDamage - armor - reduction;

	if (damage < 0)
	{
		damage = 0;
	}
	int newHp = getHp() - damage;
	setHp(newHp);
}

void Warrior::rest()
{
	setHp(getHp() + 10);

	if (getHp() > getMaxHp())
	{
		setHp(getMaxHp());
	}
}

const std::string Warrior::statusLine()const
{
	return getName() + " [Warrior] HP: " + std::to_string(getHp()) +
		"/" + std::to_string(getMaxHp());
}
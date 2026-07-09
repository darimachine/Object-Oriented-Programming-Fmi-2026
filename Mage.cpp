#include "Mage.h"

Mage::Mage(const std::string& name, int hp, int maxHp, Weapon* weapon, int mana, int maxMana):
	Character(name,hp,maxHp,weapon),mana(mana),maxMana(maxMana){ }

void Mage::attack(Character& target)
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

	if (mana < maxMana / 10)
	{
		throw OutOfManaException(getName(), 10 - mana);
	}

	mana -= 10;
	int damage = getWeapon()->roll();
	target.takeDamage(damage);
}

void Mage::defend(int incomingDamage)
{
	int reduction = consumeDamageReduction();
	int damage = incomingDamage - reduction;

	if (damage < 0)
	{
		damage = 0;
	}

	setHp(getHp() - damage);
}

void Mage::rest()
{
	mana += 10;
	if (mana > maxMana)
	{
		mana = maxMana;
	}
}

const std::string Mage::statusLine()const
{
	return getName() + " [Mage] HP: " + std::to_string(getHp()) + "/" +
		std::to_string(getMaxHp()) + " Mana: " + std::to_string(mana) + "/" +
		std::to_string(maxMana);
}
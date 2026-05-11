#include "Rogue.h"
#include "DaggerNotRetrievedException.h"
#include <random>

static std::mt19937 rogueEngine{ std::random_device{}() };

Rogue::Rogue(const std::string& name, int hp, int maxHp, Weapon* weapon, int critChance):
	Character(name,hp,maxHp,weapon),critChance(critChance){ }

void Rogue::attack(Character& target)
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

	Dagger* dagger = dynamic_cast<Dagger*>(getWeapon());
	if (dagger && dagger->isThrown())
	{
		throw DaggerNotRetrievedException(getName());
	}

	int damage = getWeapon()->roll();

	std::uniform_int_distribution<int> dist{ 1, 100 };
	int critRoll = dist(rogueEngine);

	if (critRoll <= critChance)
	{
		damage *= 2;
	}

	target.takeDamage(damage);
}

void Rogue::defend(int incomingDamage)
{
	int reduction = consumeDamageReduction();
	int damage = incomingDamage - reduction;

	if (damage < 0)
	{
		damage = 0;
	}

	setHp(getHp() - damage);
}

void Rogue::rest()
{
	Dagger* dagger = dynamic_cast<Dagger*>(getWeapon());

	if (dagger)
	{
		dagger->pickUp();
	}
}

const std::string Rogue::statusLine()const
{
	return getName() + " [Rogue] HP: " + std::to_string(getHp()) + "/" +
		std::to_string(getMaxHp()) + " Crit: " + std::to_string(critChance) + "%";
}

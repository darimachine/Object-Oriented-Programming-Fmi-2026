#include "Staff.h"
#include <random>

static std::mt19937 staffEngine{ std::random_device{}() };

Staff::Staff(const std::string& name, int maxMana) :
	Weapon(name), maxMana(maxMana) {}

int Staff::roll()const
{
	std::uniform_int_distribution<int> dist{ 1, maxMana / 5 };
	return dist(staffEngine);
}
#include "Weapon.h"

Weapon::Weapon(const std::string& name):name(name){}

const std::string& Weapon::getName()const
{
	return name;
}
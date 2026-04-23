#define _CRT_SECURE_NO_WARNINGS
#include "MonsterCard.h"
#include<print>

MonsterCard::MonsterCard():attackPoints(0),defensePoints(0)
{
	name = new char[DEFAULT_SIZE_NAME];
}

MonsterCard::MonsterCard(const char* name, unsigned int attack, unsigned int defense) :
	attackPoints(attack), defensePoints(defense)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

MonsterCard::~MonsterCard()
{
	delete[]name;
	name = nullptr;
}

void MonsterCard::copyFrom(const MonsterCard& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	attackPoints = other.attackPoints;
	defensePoints = other.defensePoints;
}

void MonsterCard::free()
{
	delete[]name;
	name = nullptr;
}

MonsterCard::MonsterCard(const MonsterCard& other)
{
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other) 
{
	if (this == &other)
	{
		return *this;
	}

	free();
	copyFrom(other);

	return *this;
}

void MonsterCard::describeType()
{
	std::println("Monster cards have a name, attack points and defense points.");
}

void MonsterCard::printInfo()const
{
	std::println("{} is a monster with ATK: {} and DEF: {}.", name, attackPoints, defensePoints);
}


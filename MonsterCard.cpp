#include "MonsterCard.h"
#include <cstring>
#include <print>

void MonsterCard::copyFrom(const MonsterCard& other)
{
	size_t size = strlen(other.name)+1;
	name = new char[size];
	strcpy_s(name, size, other.name);

	defence = other.defence;
	attack = other.attack;
}

void MonsterCard::free()
{
	delete[] name;
	name = nullptr;
}

MonsterCard::MonsterCard():defence(0), attack(0)
{
	name = new char[1];
	name[0] = '\0';
}

MonsterCard::MonsterCard(const char*name, unsigned int defence, unsigned int attack):defence(defence), attack(attack)
{
	if (!name) {
		this->name = new char[1];
		this->name[0] = '\0';
		return;
	}

	size_t size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

MonsterCard::MonsterCard(const MonsterCard&other)
{
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard&other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MonsterCard::~MonsterCard()
{
	free();
}

void MonsterCard::describeCard() const
{
	std::println("Monster cards have a name, attack points and defense points.");
}

void MonsterCard::print() const
{
	std::println("{} is a monster with ATK: {} and DEF: {}.", name, attack, defence);
}

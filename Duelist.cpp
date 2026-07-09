#include "Duelist.h"
#include <cstring>

void Duelist::copyFrom(const Duelist& other)
{
	size_t size = strlen(other.name) + 1;
	name = new char[size];
	strcpy_s(name, size, other.name);

	deck = other.deck;
}

void Duelist::free()
{
	delete[] name;
	name = nullptr;
}

Duelist::Duelist() 
{
	name = new char[1];
	name[0] = '\0';
}

Duelist::Duelist(const char* name)
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

Duelist::Duelist(const Duelist& other)
{
	copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Duelist::~Duelist()
{
	free();
}

void Duelist::changeMonster(size_t index, const MonsterCard& card)
{
	if (index >= deck.getMonstersCount()) {
		return;
	}

	deck.changeMonster(index, card);
}

void Duelist::changeMagic(size_t index, const MagicCard& card)
{
	
	if (index >= deck.getMagicsCount()) {
		return;
	}

	deck.changeMagic(index, card);
}

#define _CRT_SECURE_NO_WARNINGS
#include "Duelist.h"

Duelist::Duelist():d()
{
	name = new char[DEFAULT_SIZE_NAME];
}

Duelist::Duelist(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Duelist::~Duelist()
{
	delete[]name;
	name = nullptr;
}

void Duelist::copyFrom(const Duelist& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	d = other.d;
}

void Duelist::free()
{
	delete[]name;
	name = nullptr;
}

Duelist::Duelist(const Duelist& other)
{
	copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other)
{
	if (this == &other)
	{
		return *this;
	}

	free();
	copyFrom(other);

	return *this;
}

int Duelist::getMagicCardsCount()const
{
	return d.countMagicCards();
}

int Duelist::getMonsterCardsCount()const
{
	return d.countMonsterCards();
}

void Duelist::addMagicCardInDeck(const MagicCard& newCard)
{
	d.addMagicCard(newCard);
}

void Duelist::addMonsterCardInDeck(const MonsterCard& newCard)
{
	d.addMonsterCard(newCard);
}

void Duelist::changeMagicCardInDeck(size_t index, const MagicCard& newCard)
{
	d.changeMagicCard(index, newCard);
}

void Duelist::changeMonsterCardInDeck(size_t index, const MonsterCard& newCard)
{
	d.changeMonsterCard(index, newCard);
}

void Duelist::removeMagicCardInDeck(size_t index)
{
	d.removeMagicCard(index);
}

void Duelist::removeMonsterCardInDeck(size_t index)
{
	d.removeMonsterCard(index);
}
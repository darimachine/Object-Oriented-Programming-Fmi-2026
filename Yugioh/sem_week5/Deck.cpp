#include "Deck.h"
#include <iostream>

Deck::Deck() : monsterCount(0), magicCount(0)
{

}
int Deck::getMonsterCardCount() const
{
	return monsterCount;
}
int Deck::getMagicCardCount() const
{
	return magicCount;
}
bool Deck::addMonsterCard(const MonsterCard& card)
{
	if (monsterCount >= MAX_CARDS)
	{
		std::cout << "Monster deck is full!" << std::endl;
		return false;
	}
	monsterCards[monsterCount++] = card;
	return true;
}
bool Deck::addMagicCard(const MagicCard& card)
{
	if (magicCount >= MAX_CARDS)
	{
		std::cout << "Magic deck is full!" << std::endl;
		return false;
	}
	magicCards[magicCount++] = card;
	return true;
}
bool Deck::changeMonsterCard(int index, const MonsterCard& card)
{
	if (index < 0 || index >= monsterCount)
	{
		std::cout << "Invalid monster card index!" << std::endl;
		return false;
	}
	monsterCards[index] = card;
	return true;
}
bool Deck::changeMonsterCard(int index, const char* name, unsigned int atk, unsigned int def)
{
	return changeMonsterCard(index, MonsterCard(name, atk, def));
}
bool Deck::changeMagicCard(int index, const MagicCard& card)
{
	if (index < 0 || index >= magicCount)
	{
		std::cout << "Invalid magic card index!" << std::endl;
		return false;
	}
	magicCards[index] = card;
	return true;
}
bool Deck::changeMagicCard(int index, const char* name, const char* effect, MagicType type)
{
	return changeMagicCard(index, MagicCard(name, effect, type));
}
auto removeCard = [](auto* cards, int& count, int index, const char* errorMsg, auto emptyCard)
	{
		if (index < 0 || index >= count)
		{
			std::cout << errorMsg << std::endl;
			return false;
		}
		for (int i = index; i < count - 1; i++)
		{
			cards[i] = cards[i + 1];
		}
		cards[--count] = emptyCard;
		return true;
	};
bool Deck::removeMonsterCard(int index)
{
	return removeCard(monsterCards, monsterCount, index, "Invalid monster card index!", MonsterCard());
}
bool Deck::removeMagicCard(int index)
{
	return removeCard(magicCards, magicCount, index, "Invalid magic card index!", MagicCard());
}
const MonsterCard& Deck::getMonsterCard(int index) const
{
	return monsterCards[index];
}
const MagicCard& Deck::getMagicCard(int index) const
{
	return magicCards[index];
}
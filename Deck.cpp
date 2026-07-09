#include "Deck.h"

int Deck::countMonsterCards()const
{
	return countMonster;
}

int Deck::countMagicCards()const
{
	return countMagic;
}

void Deck::addCard(const MagicCard& newCard)
{
	if (countMagic== MAX_SIZE)
	{
		return;
	}

	magic[countMagic++] = newCard;
}

void Deck::addCard(const MonsterCard& newCard)
{
	if (countMonster == MAX_SIZE)
	{
		return;
	}

	monster[countMonster++] = newCard;
}

void Deck::changeCard(size_t index,const MagicCard& newCard)
{
	for (size_t i = 0;i < countMagic;i++)
	{
		if (i == index)
		{
			magic[i] = newCard;
			break;
		}
	}
}

void Deck::changeCard(size_t index, const MonsterCard& newCard)
{
	for (size_t i = 0;i < countMonster;i++)
	{
		if (i == index)
		{
			monster[i] = newCard;
			break;
		}
	}
}

void Deck::removeMonsterCard(size_t index)
{
	for (size_t i = 0;i < countMonster;i++)
	{
		if (i == index)
		{
			for (size_t j = i+1;j < countMonster;j++)
			{
				monster[j-1] = monster[j];
			}
			countMonster--;
			break;
		}
	}
}

void Deck::removeMagicCard(size_t index)
{
	for (size_t i = 0;i < countMagic;i++)
	{
		if (i == index)
		{
			for (size_t j = i + 1;j < countMagic;j++)
			{
				magic[j-1] = magic[j];
			}
			countMagic--;
			break;
		}
	}
}
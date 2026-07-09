#pragma once
#include"MagicCard.h"
#include"MonsterCard.h"

class Deck
{
private:
	static constexpr int MAX_SIZE = 20;
	MonsterCard monster[MAX_SIZE];
	MagicCard magic[MAX_SIZE];

	int countMonster = 0;
	int countMagic = 0;

public:
	int countMonsterCards()const;

	int countMagicCards()const;

	void addCard(const MonsterCard& newCard);

	void addCard(const MagicCard& newCard);

	void changeCard(size_t index, const MagicCard& newCard);

	void changeCard(size_t index, const MonsterCard& newCard);

	void removeMonsterCard(size_t index);

	void removeMagicCard(size_t index);
};


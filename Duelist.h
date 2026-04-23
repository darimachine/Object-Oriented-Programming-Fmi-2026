#pragma once
#include"Deck.h"

class Duelist
{
private:
	static constexpr int DEFAULT_SIZE_NAME = 0;
	char* name;
	Deck d;

    void copyFrom(const Duelist& other);
    void free();

public:
	Duelist();

    Duelist(const char* name);

    Duelist(const Duelist& other);

    Duelist& operator=(const Duelist& other);

	~Duelist();

    int getMagicCardsCount() const;
    int getMonsterCardsCount() const;

    void addMagicCardInDeck(const MagicCard& newCard);
    void addMonsterCardInDeck(const MonsterCard& newCard);

    void changeMagicCardInDeck(size_t index, const MagicCard& newCard);
    void changeMonsterCardInDeck(size_t index, const MonsterCard& newCard);

    void removeMagicCardInDeck(size_t index);
    void removeMonsterCardInDeck(size_t index);
};


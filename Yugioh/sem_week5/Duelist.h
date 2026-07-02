#pragma once
#include "Deck.h"
class Duelist
{
private:
    char* name;
    Deck deck;
    void copyFrom(const Duelist& other);
    void free();
public:
    Duelist(const char* name);
    Duelist(const Duelist& other);
    Duelist& operator=(const Duelist& other);
    ~Duelist();
    const char* getName() const;
    int getMonsterCardCount() const;
    int getMagicCardCount() const;
    bool addMonsterCard(const MonsterCard& card);
    bool addMagicCard(const MagicCard& card);
    bool changMonsterInDeck(int index, const MonsterCard& card);
    bool changeMagicCardInDeck(int index, const MagicCard& card);
    bool removeMonsterFromDeck(int index);
    bool removeMagicFromDeck(int index);
};


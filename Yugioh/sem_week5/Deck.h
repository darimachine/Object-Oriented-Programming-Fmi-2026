#pragma once
#include "MonsterCard.h"
#include "MagicCard.h"
class Deck
{
private:
    static const int MAX_CARDS = 20;
    MonsterCard monsterCards[MAX_CARDS];
    MagicCard magicCards[MAX_CARDS];
    int monsterCount;
    int magicCount;

public:
    Deck();
    int getMonsterCardCount() const;
    int getMagicCardCount() const;
    bool addMonsterCard(const MonsterCard& card);
    bool addMagicCard(const MagicCard& card);
    bool changeMonsterCard(int index, const MonsterCard& card);
    bool changeMonsterCard(int index, const char* name, unsigned int atk, unsigned int def);
    bool changeMagicCard(int index, const MagicCard& card);
    bool changeMagicCard(int index, const char* name, const char* effect, MagicType type);
    bool removeMonsterCard(int index);
    bool removeMagicCard(int index);
    const MonsterCard& getMonsterCard(int index) const;
    const MagicCard& getMagicCard(int index) const;
};


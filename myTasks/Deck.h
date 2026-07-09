#pragma once
#include  "MagicCard.h"
#include  "MonsterCard.h"

constexpr  int MAX_MONSTERS = 20;
constexpr  int MAX_MAGIC_CARDS = 20;
class Deck
{
    MonsterCard monsters[MAX_MONSTERS];
    MagicCard magicCards[MAX_MAGIC_CARDS];

    int currMonstersCount = 0;
    int currMagicCardsCount = 0;

    public:
         int getCurrMonstersCount();
         int getCurrMagicCardsCount();

        void addMagicCard(const MagicCard&);
        void addMonsterCard(const MonsterCard& );

        void changeMagicCard(const MagicCard&,unsigned int idx);
        void changeMonsterCard(const MonsterCard&, unsigned int idx);

        void removeMagicCard(unsigned int);
        void removeMonsterCard(unsigned int);


};



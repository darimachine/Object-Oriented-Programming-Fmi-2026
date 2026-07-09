#pragma once
#include  "Deck.h"
class Duelist
    {
        private:
            char* name = nullptr;
            Deck myDeck;

            void free();
            void copyFrom(const Duelist&);
        public:
            Duelist();
            Duelist(const char* name);
            ~Duelist();
            Duelist(const Duelist&);
            Duelist& operator=(const Duelist&);

            const char* getName() const;

            int getCurrMonstersCount();
            int getCurrMagicCardsCount();
            void addMagicCard(const MagicCard& magicCard);
            void addMonsterCard(const MonsterCard& monsterCard);
            void changeMonsterCard(const MonsterCard& newMonsterCard, unsigned int idx);
            void changeMagicCard(const MagicCard& newMagicCard, unsigned int idx);
            void removeMagicCard(unsigned int idx);
            void removeMonsterCard(unsigned int idx);
    };


#include <iostream>
#include  <print>
#include  <cstring>
#include "MagicCard.h"
#include "MonsterCard.h"

#include "Deck.h"

int Deck::getCurrMagicCardsCount()
{
    return  currMagicCardsCount;
}

int Deck::getCurrMonstersCount()
{
    return  currMonstersCount;
}

void Deck::addMagicCard(const MagicCard &magicCard)
{
    if (currMagicCardsCount == MAX_MAGIC_CARDS)
    {
        std::println("The set is already full.");
        return;
    }

    magicCards[currMagicCardsCount] = magicCard;
    currMagicCardsCount++;
}

void Deck::addMonsterCard(const MonsterCard & monsterCard)
{
    if (currMonstersCount == MAX_MONSTERS)
    {
        std::println("The set is already full");
        return;
    }

    monsters[currMonstersCount] = monsterCard;
    currMonstersCount++;
}

void Deck::changeMonsterCard(const MonsterCard &NewMonsterCard, unsigned int idx)
{
    if (idx >= currMonstersCount)
    {
        std::println("Invalid index");
        return;
    }

    monsters[idx] = NewMonsterCard;
}

void Deck::changeMagicCard(const MagicCard &NewMagicCard, unsigned int idx)
{
    if (idx >= currMagicCardsCount)
    {
        std::println("Invalid index");
        return;
    }
    magicCards[idx] = NewMagicCard;
}

void Deck::removeMagicCard(unsigned int idx)
{
    if (idx >= currMagicCardsCount)
    {
        std::println("Invalid index");
        return;
    }

    magicCards[idx] = magicCards[currMagicCardsCount - 1];
    --currMagicCardsCount;

}

void Deck::removeMonsterCard(unsigned int idx)
{
    if (idx >= currMonstersCount)
    {
        std::println("Invalid index");
        return;
    }

    monsters[idx] = monsters[currMonstersCount - 1];
    --currMonstersCount;
}

// int main()
// {
//     MonsterCard Monfirst("Blue-Eyes White Dragon", 3000, 2500);
//     MonsterCard Monsecond("Dark Magician", 2500, 2100);
//     MonsterCard Monthird("Red-Eyes Black Dragon", 2400, 2000);
//     MonsterCard Monfourth("Kuriboh", 300, 200);
//     MonsterCard Monfifth("Obelisk the Tormentor", 4000, 4000);
//
//     MagicCard first("Pot of Greed", "Draw 2 cards from your deck", type::SPELL);
//     MagicCard second("Monster Reborn", "Target 1 monster in either GY; Special Summon it.", type::SPELL);
//     MagicCard third("Mirror Force", "When opponent attacks: Destroy all their Attack Position monsters.",type::TRAP);
//     MagicCard fourth("United We Stand", "Equipped monster gains 800 ATK/DEF for each face-up monster you control.", type::EQUIP);
//     MagicCard fifth("Trap Hole", "When opponent Normal Summons a monster with 1000+ ATK: Destroy it.", type::TRAP);
//
//     Deck myDeck;
//     myDeck.addMagicCard(first);
//     myDeck.addMagicCard(second);
//     myDeck.addMagicCard(third);
//     myDeck.addMagicCard(fourth);
//     myDeck.addMagicCard(fifth);
//
//     myDeck.addMonsterCard(Monfirst);
//     myDeck.addMonsterCard(Monsecond);
//     myDeck.addMonsterCard(Monthird);
//     myDeck.addMonsterCard(Monfourth);
//     myDeck.addMonsterCard(Monfifth);
//
// }
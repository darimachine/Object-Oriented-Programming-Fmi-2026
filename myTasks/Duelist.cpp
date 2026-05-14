#include  "Deck.h"
#include "Duelist.h"
#include  <iostream>
#include  <cstring>
#include <print>


void Duelist::free()
{
    delete [] name;
    name = nullptr;
}

void Duelist::copyFrom(const Duelist &other)
{
    if (other.name == nullptr)
    {
        this->name = nullptr;
    }
    else
    {
        name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    myDeck = other.myDeck;
}

Duelist::Duelist(): name(nullptr)
{}

Duelist::Duelist(const char *name)
{
    if (name == nullptr)
    {
        this->name = nullptr;
    }
    else
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

Duelist::Duelist(const Duelist &other)
{
    copyFrom(other);
}

Duelist &Duelist::operator=(const Duelist &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return  *this;
}

Duelist::~Duelist()
{
    free();
}

const char *Duelist::getName() const
{
    return name? name: "";
}

int Duelist::getCurrMonstersCount()
{
    return  myDeck.getCurrMonstersCount();
}

int Duelist::getCurrMagicCardsCount()
{
    return myDeck.getCurrMagicCardsCount();
}

void Duelist::addMagicCard(const MagicCard &magicCard)
{
    myDeck.addMagicCard(magicCard);
}

void Duelist::addMonsterCard(const MonsterCard &monsterCard)
{
    myDeck.addMonsterCard(monsterCard);
}

void Duelist::removeMagicCard(unsigned int idx)
{
    myDeck.removeMagicCard(idx);
}

void Duelist::removeMonsterCard(unsigned int idx)
{
    myDeck.removeMonsterCard(idx);
}

void Duelist::changeMonsterCard(const MonsterCard &newMonsterCard, unsigned int idx)
{
    myDeck.changeMonsterCard(newMonsterCard, idx);
}

void Duelist::changeMagicCard(const MagicCard &newMagicCard, unsigned int idx)
{
    myDeck.changeMagicCard(newMagicCard, idx);
}

int main()
{
    MonsterCard Monfirst("Blue-Eyes White Dragon", 3000, 2500);
    MonsterCard Monsecond("Dark Magician", 2500, 2100);
    MonsterCard Monthird("Red-Eyes Black Dragon", 2400, 2000);
    MonsterCard Monfourth("Kuriboh", 300, 200);
    MonsterCard Monfifth("Obelisk the Tormentor", 4000, 4000);

    MagicCard first("Pot of Greed", "Draw 2 cards from your deck", type::SPELL);
    MagicCard second("Monster Reborn", "Target 1 monster in either GY; Special Summon it.", type::SPELL);
    MagicCard third("Mirror Force", "When opponent attacks: Destroy all their Attack Position monsters.",type::TRAP);
    MagicCard fourth("United We Stand", "Equipped monster gains 800 ATK/DEF for each face-up monster you control.", type::EQUIP);
    MagicCard fifth("Trap Hole", "When opponent Normal Summons a monster with 1000+ ATK: Destroy it.", type::TRAP);

    Duelist setoKaiba("Seto Kaiba");

    setoKaiba.addMagicCard(first);
    setoKaiba.addMagicCard(second);
    setoKaiba.addMagicCard(third);
    setoKaiba.addMagicCard(fourth);
    setoKaiba.addMagicCard(fifth);

    setoKaiba.addMonsterCard(Monfirst);
    setoKaiba.addMonsterCard(Monsecond);
    setoKaiba.addMonsterCard(Monthird);
    setoKaiba.addMonsterCard(Monfourth);
    setoKaiba.addMonsterCard(Monfifth);

    std::println("{} has {} magic cards and {} monster cards in his deck.",
                 setoKaiba.getName(),
                 setoKaiba.getCurrMagicCardsCount(),
                 setoKaiba.getCurrMonstersCount()); 
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "Duelist.h"

void Duelist::copyFrom(const Duelist& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    deck = other.deck;
}
void Duelist::free()
{
    delete[] name;
}
Duelist::Duelist(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Duelist::Duelist(const Duelist& other)
{
    copyFrom(other);
}
Duelist& Duelist::operator=(const Duelist& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
Duelist::~Duelist()
{
    free();
}
const char* Duelist::getName() const 
{
    return name;
}
int  Duelist::getMonsterCardCount() const 
{ 
    return deck.getMonsterCardCount(); 
}
int  Duelist::getMagicCardCount() const 
{
    return deck.getMagicCardCount();
}
bool Duelist::addMonsterCard(const MonsterCard& card) 
{
    return deck.addMonsterCard(card); 
}
bool Duelist::addMagicCard(const MagicCard& card) 
{
    return deck.addMagicCard(card);
}
bool Duelist::changMonsterInDeck(int index, const MonsterCard& card) 
{
    return deck.changeMonsterCard(index, card); 
}
bool Duelist::changeMagicCardInDeck(int index, const MagicCard& card)
{ 
    return deck.changeMagicCard(index, card); 
}
bool Duelist::removeMonsterFromDeck(int index) 
{
    return deck.removeMonsterCard(index); 
}
bool Duelist::removeMagicFromDeck(int index) 
{
    return deck.removeMagicCard(index); 
}
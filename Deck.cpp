#include "Deck.h"
#include <print>

size_t Deck::getMonstersCount() const
{
    return monstersCount;
}

size_t Deck::getMagicsCount() const
{
    return magicsCount;
}

void Deck::addMonster(const MonsterCard& card)
{
    if (monstersCount >= MAX_CARDS) {
        std::println("Deck is full!");
        return;
    }

    monsters[monstersCount++] = card;
}

void Deck::addMagic(const MagicCard&card)
{

    if (magicsCount >= MAX_CARDS) {
        std::println("Deck is full!");
        return;
    }

    magics[magicsCount++] = card;
}

void Deck::changeMonster(size_t index, const MonsterCard& card)
{
    if (index >= monstersCount) {
        return;
    }

    monsters[index] = card;
}

void Deck::changeMagic(size_t index, const MagicCard& card)
{
    if (index >= magicsCount) {
        return;
    }

    magics[index] = card;
}

void Deck::changeMonster(size_t index, const char*name, unsigned int defence, unsigned int attack)
{
    if (index >= monstersCount) {
        return;
    }

    monsters[index] = MonsterCard(name, defence, attack);
}

void Deck::changeMagic(size_t index, const char*name, const char*effect, const char* typeStr)
{
    if (index >= magicsCount) {
        return;
    }

    magics[index] = MagicCard(name, effect, magics[index].StringToType(typeStr));
}


void Deck::removeMonster(size_t index)
{
    if (index >= monstersCount) {
        return;
    }

    std::swap(monsters[index], monsters[monstersCount - 1]);
    monstersCount--;
}

void Deck::removeMagic(size_t index)
{
    if (index >= magicsCount) {
        return;
    }

    std::swap(magics[index], magics[magicsCount - 1]);
    magicsCount--;
}


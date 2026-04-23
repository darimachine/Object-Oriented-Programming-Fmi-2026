#pragma once
#include "MonsterCard.h"
#include "MagicCard.h"

class Deck
{
private:
	static constexpr unsigned int MAX_CARDS = 20;
    MonsterCard monsters[MAX_CARDS];
    MagicCard magics[MAX_CARDS];

    size_t monstersCount = 0;
    size_t magicsCount = 0;

public:
    size_t getMonstersCount() const;
    size_t getMagicsCount() const;

    void addMonster(const MonsterCard&);
    void addMagic(const MagicCard&);

    void changeMonster(size_t, const MonsterCard&);
    void changeMagic(size_t, const MagicCard&);

    void changeMonster(size_t, const char*, unsigned int, unsigned int);
    void changeMagic(size_t, const char*, const char*, const char*);

    void removeMonster(size_t);
    void removeMagic(size_t);

};


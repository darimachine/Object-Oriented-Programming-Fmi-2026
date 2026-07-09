#pragma once
#include "Deck.h"

class Duelist
{
private:
	char* name = nullptr;
	Deck deck;

	void copyFrom(const Duelist&);
	void free();

public:
	Duelist();
	Duelist(const char*);
	Duelist(const Duelist&);
	Duelist& operator= (const Duelist&);
	~Duelist();

	void changeMonster(size_t, const MonsterCard&);
	void changeMagic(size_t, const MagicCard&);
};


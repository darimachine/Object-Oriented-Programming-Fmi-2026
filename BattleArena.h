#pragma once
#include"Character.h"
#include<memory>
#include<iostream>
#include"OutOfManaException.h"
#include"StatusEffect.h"
class BattleArena
{
private:
	static constexpr size_t MAX_LEN_CHARACTERS = 2;
	Character* characters[MAX_LEN_CHARACTERS];

public:
	BattleArena(Character* first, Character* second);

	void tickEffects();
	void runRound();
	bool isOver()const;
	void addEffect(int characterIndex, std::unique_ptr<StatusEffect> effect);
};


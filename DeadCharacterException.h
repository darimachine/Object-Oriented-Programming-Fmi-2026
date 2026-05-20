#pragma once
#include"CombatException.h"

class DeadCharacterException:public CombatException
{
public:
	explicit DeadCharacterException(const std::string& characterName);
};


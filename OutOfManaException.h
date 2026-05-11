#pragma once
#include"CombatException.h"

class OutOfManaException:public CombatException
{
public:
	OutOfManaException(const std::string& mageName, int missingMana);
};


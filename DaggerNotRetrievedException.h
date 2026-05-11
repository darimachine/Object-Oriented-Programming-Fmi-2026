#pragma once
#include"CombatException.h"

class DaggerNotRetrievedException:public CombatException
{
public:
	DaggerNotRetrievedException(const std::string& rogueName);
};


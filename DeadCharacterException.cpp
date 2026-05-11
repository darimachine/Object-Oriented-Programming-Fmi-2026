#include "DeadCharacterException.h"

DeadCharacterException::DeadCharacterException(const std::string& characterName):
	CombatException(characterName+" is dead!"){ }
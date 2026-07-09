#include "OutOfManaException.h"

OutOfManaException::OutOfManaException(const std::string& mageName, int missingMana):
	CombatException(mageName+" does not have enough mana! Missing mana: "
		+ std::to_string(missingMana)){ }
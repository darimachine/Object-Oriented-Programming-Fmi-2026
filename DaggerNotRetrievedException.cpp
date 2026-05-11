#include "DaggerNotRetrievedException.h"

DaggerNotRetrievedException::DaggerNotRetrievedException(const std::string& rogueName):
	CombatException(rogueName + " cannot attack before retrieving the dagger!"){ }
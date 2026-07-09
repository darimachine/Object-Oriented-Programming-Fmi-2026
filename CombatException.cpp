#include "CombatException.h"

CombatException::CombatException(const std::string& message):
	message(message){ }

const char* CombatException::what()const noexcept
{
	return message.c_str();
}
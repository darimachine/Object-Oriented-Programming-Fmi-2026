#include "DeadCharacterException.h"

DeadCharacterException::DeadCharacterException(const std::string &msg,
    int code) : CombatException(msg, code) {
}

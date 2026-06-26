#include "DaggerNotRetrievedException.h"

DaggerNotRetrievedException::DaggerNotRetrievedException(const std::string &msg,
    int code) : CombatException(msg, code) {
}

#include "CombatException.h"

CombatException::CombatException(const std::string &msg,
    int code) : message("[" + msg + "]"), code(code){
}

int CombatException::getCode() const {
    return code;
}

const char * CombatException::what() const noexcept {
    return message.c_str();
}

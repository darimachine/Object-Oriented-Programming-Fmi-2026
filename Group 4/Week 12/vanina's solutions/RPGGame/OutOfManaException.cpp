#include "OutOfManaException.h"

OutOfManaException::OutOfManaException(const std::string &msg,
    int code) : CombatException(msg, code) {
}

// const char * OutOfManaException::what() const noexcept {
//     // return CombatException::what();
//     return message.c_str();
// }

// int OutOfManaException::getCode() const {
//     return code;
// }

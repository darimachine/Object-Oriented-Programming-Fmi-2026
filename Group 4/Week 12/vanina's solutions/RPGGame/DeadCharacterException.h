#ifndef RPGGAME_DEADCHARACTEREXCEPTION_H
#define RPGGAME_DEADCHARACTEREXCEPTION_H

#include "CombatException.h"

class DeadCharacterException : public CombatException {
public:
    DeadCharacterException(const std::string& msg, int code);
};


#endif //RPGGAME_DEADCHARACTEREXCEPTION_H
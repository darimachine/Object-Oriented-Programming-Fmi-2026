#ifndef RPGGAME_DAGGERNOTRETRIEVEDEXCEPTION_H
#define RPGGAME_DAGGERNOTRETRIEVEDEXCEPTION_H

#include "CombatException.h"

class DaggerNotRetrievedException : public CombatException {
public:
    DaggerNotRetrievedException(const std::string& msg, int code);
};


#endif //RPGGAME_DAGGERNOTRETRIEVEDEXCEPTION_H
#ifndef RPGGAME_OUTOFMANAEXCEPTION_H
#define RPGGAME_OUTOFMANAEXCEPTION_H
#include "CombatException.h"


class OutOfManaException : public CombatException {
public:
    OutOfManaException(const std::string& msg, int code);

    // int getCode() const override;
    // const char* what() const noexcept override;
};


#endif //RPGGAME_OUTOFMANAEXCEPTION_H
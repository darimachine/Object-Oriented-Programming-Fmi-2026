#ifndef RPGGAME_COMBATEXCEPTION_H
#define RPGGAME_COMBATEXCEPTION_H

#include <exception>
#include<string>


class CombatException : public std::exception {
protected:
    std::string message;
    int code;

public:
    CombatException(const std::string& msg, int code);
    // virtual
    int getCode() const;
    const char* what() const noexcept override;
};


#endif //RPGGAME_COMBATEXCEPTION_H
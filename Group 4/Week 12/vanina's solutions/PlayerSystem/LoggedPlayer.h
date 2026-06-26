#ifndef PLAYERSYSTEM_LOGGEDPLAYER_H
#define PLAYERSYSTEM_LOGGEDPLAYER_H

#include <string>

#include "Player.h"


class LoggedPlayer : public Player {
    std::string password;

    static constexpr int MAX_PASSWORD_LENGTH = 8;

public:
    LoggedPlayer(double points, const std::string& password);

    bool login(int id, const std::string& password);

    void print() const override;

};


#endif //PLAYERSYSTEM_LOGGEDPLAYER_H
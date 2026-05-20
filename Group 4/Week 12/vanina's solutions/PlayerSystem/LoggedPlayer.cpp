#include "LoggedPlayer.h"

#include <iostream>

LoggedPlayer::LoggedPlayer(double points, const std::string &password) : Player(points) {
    if (password.size() > MAX_PASSWORD_LENGTH) {
        throw std::invalid_argument("password is too long");
    }
    this->password = password;
}

bool LoggedPlayer::login(int id, const std::string &password) {
    return id == this->id && password == this->password;
}

void LoggedPlayer::print() const {
    std::cout << "[LoggedPlayer] ";
    Player::print();
}

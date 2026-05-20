#include "PremiumPlayer.h"

#include <iostream>

PremiumPlayer::PremiumPlayer(double points, const std::string &name,
    const std::string& password) : LoggedPlayer(points, password), name(name) {
}

int PremiumPlayer::minTwoStarsPoints() const {
    return MIN_STARS_POINTS;
}

int PremiumPlayer::minThreeStarsPoints() const {
    return MIN_STARS_POINTS;
}

int PremiumPlayer::minFourStarsPoints() const {
    return MIN_STARS_POINTS;
}

int PremiumPlayer::minFiveStarsPoints() const {
    return MIN_STARS_POINTS;
}

void PremiumPlayer::sendMessage(const std::string &message) const {
    std::cout << name << ": " << message << std::endl;
}

void PremiumPlayer::print() const {
    std::cout << "[PremiumPlayer] Name: " << name << " ";
    Player::print();
}

#include "Player.h"

#include <iostream>

int Player::nextId = 0;

Player::Player(double points) : points(points), id(nextId++) {
    stars = Stars::ONE;
}

int Player::minTwoStarsPoints() const {
    return MIN_TWO_STARS_POINTS;
}

int Player::minThreeStarsPoints() const {
    return MIN_THREE_STARS_POINTS;
}

int Player::minFourStarsPoints() const {
    return MIN_FOUR_STARS_POINTS;
}

int Player::minFiveStarsPoints() const {
    return MIN_FIVE_STARS_POINTS;
}

void Player::addPoints(double points) {
    this->points += points;
}

bool Player::levelUp() {
    if (stars == Stars::ONE && points >= minTwoStarsPoints()) {
        stars = Stars::TWO;
        return true;
    }
    if (points >= minThreeStarsPoints() && stars == Stars::TWO) {
        stars = Stars::THREE;
        return true;
    }
    if (points >= minFourStarsPoints() && stars == Stars::THREE) {
        stars = Stars::FOUR;
        return true;
    }
    if (points >= minFiveStarsPoints() && stars == Stars::FOUR) {
        stars = Stars::FIVE;
        return true;
    }
    return false;
}

void Player::print() const {
    std::cout << "Player id: " << id <<
        ", points: " << points <<
            ", stars: " << (int) stars << std::endl;
}
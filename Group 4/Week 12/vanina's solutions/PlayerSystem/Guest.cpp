#include "Guest.h"

#include <iostream>
#include <ostream>

Guest::Guest(double points, int maxTimePlayed) : Player(points), maxTimePlayed(maxTimePlayed) {
}

bool Guest::levelUp() {
    return false;
}

void Guest::print() const {
    std::cout << "[Guest] ";
    Player::print();
    std::cout << "Remaining time: " << maxTimePlayed << " min\n";
}
#include "Poison.h"

#include <iostream>
#include <ostream>

Poison::Poison(int duration) : StatusEffect(duration) {
}

void Poison::tick(Character &target) {
    try {
        target.takeDamage(POISON_DAMAGE);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    duration--;
}

std::string Poison::getStatus() const {
    return "poisoned ";
}

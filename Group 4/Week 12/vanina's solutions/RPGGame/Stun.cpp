#include "Stun.h"

Stun::Stun(int duration) : StatusEffect(duration) {
}

void Stun::tick(Character &target) {
    target.stun();
    duration--;
}

std::string Stun::getStatus() const {
    return "stunned ";
}

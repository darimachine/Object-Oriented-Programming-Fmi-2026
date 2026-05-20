#include "Sword.h"

Sword::Sword(const std::string &name) : Weapon(name) {
}

int Sword::roll() const {
    return SWORD_DAMAGE;
}

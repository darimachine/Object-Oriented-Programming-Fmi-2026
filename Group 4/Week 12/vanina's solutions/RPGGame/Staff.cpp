#include "Staff.h"

Staff::Staff(const std::string &name, int maxMana) : Weapon(name), maxMana(maxMana) {
}

int Staff::roll() const {
    std::uniform_int_distribution<int> dist{1, maxMana/5};
    return dist(engine);
}

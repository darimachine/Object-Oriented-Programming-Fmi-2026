#include "Dagger.h"

Dagger::Dagger(const std::string &name) : Weapon(name), isDrop(false) {
}

void Dagger::drop() {
    isDrop = true;
}

bool Dagger::isDropped() const {
    return isDrop;
}

void Dagger::pickUp() {
    isDrop = false;
}

int Dagger::roll() const {
    int minDamage = 1;
    int maxDamage = 20;

    if (isDrop) {
        minDamage *= 5;
        maxDamage *= 1.5;
    }

    std::uniform_int_distribution<int> dist{minDamage, maxDamage};
    return dist(engine);
}

#include "Rogue.h"

Rogue::Rogue(const std::string &name, int maxHp, std::unique_ptr<Weapon> w,
    int critChance) : Character(name, maxHp, std::move(w)) {
    if (critChance < 1 || critChance > 100) {
        throw std::invalid_argument("critChance must be between 1 and 100");
    }
    this->critChance = critChance;
}

void Rogue::attack(Character &target) {
    if (isStunned) {
        isStunned = false;
        return;
    }

    int damage = weapon->roll();

    std::uniform_int_distribution<int> dist{1, 100};
    if (dist(engine) <= critChance) {
        damage *= 2;
    }

    target.takeDamage(damage);
}

void Rogue::defend(int incomingDamage) {
    hp -= incomingDamage;
}

void Rogue::rest() {
    Dagger* dagger = dynamic_cast<Dagger*>(getWeapon());

    if (dagger) {
        dagger->pickUp();
    }
}

std::string Rogue::statusLine() const {
    return getName() + " [Rogue]  HP: " + std::to_string(getHp()) +
        "/" + std::to_string(getMaxHp()) +
                " - " + getStatus();
}

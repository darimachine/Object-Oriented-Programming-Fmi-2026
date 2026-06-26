#include "Warrior.h"

Warrior::Warrior(const std::string &name, int maxHp, std::unique_ptr<Weapon> w,
    int armor) : Character(name, maxHp, std::move(w)), armor(armor) {
}

std::string Warrior::statusLine() const {
    return getName() + " [Warrior]  HP: " + std::to_string(getHp()) +
        "/" + std::to_string(getMaxHp()) +
            " - " + getStatus();
}

void Warrior::attack(Character &target) {
    if (isStunned) {
        isStunned = false;
        return;
    }
    target.takeDamage(weapon->roll());
}

void Warrior::defend(int incoming) {
    int takenDamage = std::max(0, incoming - armor);

    hp -= takenDamage;
}

void Warrior::rest() {
    hp += REST_HEALTH;
}

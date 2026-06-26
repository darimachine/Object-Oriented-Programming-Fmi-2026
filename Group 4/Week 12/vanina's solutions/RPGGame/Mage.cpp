#include "Mage.h"

#include "OutOfManaException.h"
#include "Warrior.h"

Mage::Mage(const std::string &name, int maxHp,std::unique_ptr<Weapon> w,
           int maxMana) : Character(name, maxHp, std::move(w)), maxMana(maxMana), mana(maxMana) {
}

void Mage::attack(Character &target) {
    if (isStunned) {
        isStunned = false;
        return;
    }
    if (mana < (MIN_MANA_NEED * maxMana)) {
        throw OutOfManaException(getName() + " needs more "
            + std::to_string(MANA_COSTS - mana) + " mana", 1);
    }

    target.takeDamage(weapon->roll());
    mana -= MANA_COSTS;
}

void Mage::defend(int incomingDamage) {
    hp -= incomingDamage;
}

void Mage::rest() {
    mana += REST_MANA;
}

std::string Mage::statusLine() const {
    return getName() + " [Mage]  HP: " + std::to_string(getHp()) +
        "/" + std::to_string(getMaxHp()) +
            ", mana: " + std::to_string(mana) + "/ " + std::to_string(maxMana) +
                " - " + getStatus();
}

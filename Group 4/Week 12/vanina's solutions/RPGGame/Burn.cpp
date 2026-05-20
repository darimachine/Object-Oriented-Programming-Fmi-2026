#include "Burn.h"

#include <iostream>
#include <ostream>

#include "DeadCharacterException.h"

Burn::Burn(int duration) : StatusEffect(duration) {
}

void Burn::tick(Character &target) {
    try {
        target.takeDamage(BURN_DAMAGE - target.getDamageReduce());

    } catch (const DeadCharacterException& e) {
        std::cout << target.getName() << e.what() << std::endl;
    }
    target.setDamageReduce(target.getDamageReduce() + 3);
    duration--;
}

std::string Burn::getStatus() const {
    return "burned ";
}

#include "Character.h"

#include "DeadCharacterException.h"

Character::Character(const std::string &name, int maxHp,
    std::unique_ptr<Weapon> w) : name(name), hp(maxHp), maxHp(maxHp), weapon(std::move(w)) {
}

const std::string & Character::getName() const {
    return name;
}

int Character::getHp() const {
    return hp;
}

int Character::getMaxHp() const {
    return maxHp;
}

int Character::getDamageReduce() const {
    return damageReduce;
}

Weapon * Character::getWeapon() const {
    return weapon.get();
}

std::vector<std::unique_ptr<StatusEffect>>& Character::getEffects() {
    return status;
}

std::string Character::getStatus() const {
    std::string result;
    for (const auto & effect : status) {
        result += effect->getStatus();
    }
    return result;
}

bool Character::getStun() const {
    return isStunned;
}

void Character::stun() {
    isStunned = true;
}

void Character::setDamageReduce(int damageReduce) {
    this->damageReduce = damageReduce;
}

void Character::addEffect(std::unique_ptr<StatusEffect> effect) {
    status.push_back(std::move(effect));
}

void Character::takeDamage(int amount) {
    if (isDead()) {
        throw DeadCharacterException(getName() + " is already dead", 2);
    }
    defend(amount);
    if (hp <= 0) {
        hp = 0;
    }
}

bool Character::isDead() const {
    return hp <= 0;
}

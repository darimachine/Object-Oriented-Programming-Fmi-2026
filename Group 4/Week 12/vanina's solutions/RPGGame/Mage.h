#ifndef RPGGAME_MAGE_H
#define RPGGAME_MAGE_H

#include <memory>

#include "Character.h"

class Mage : public Character {
    int mana;
    int maxMana;

    static constexpr double MIN_MANA_NEED = 0.1;
    static constexpr int MANA_COSTS = 10;
    static constexpr int REST_MANA = 10;

public:
    Mage(const std::string& name, int maxHp, std::unique_ptr<Weapon> w, int maxMana);

    void attack(Character &target) override;
    void defend(int incomingDamage) override;

    void rest() override;
    std::string statusLine() const override;
};


#endif //RPGGAME_MAGE_H
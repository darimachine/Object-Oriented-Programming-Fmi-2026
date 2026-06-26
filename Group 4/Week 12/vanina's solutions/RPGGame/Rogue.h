#ifndef RPGGAME_ROGUE_H
#define RPGGAME_ROGUE_H

#include "Character.h"
#include "Dagger.h"

#include<random>


class Rogue : public Character {
    int critChance;

    mutable std::mt19937 engine{std::random_device{}()};

public:
    Rogue(const std::string& name, int maxHp, std::unique_ptr<Weapon> w, int critChance);

    void attack(Character &target) override;
    void defend(int incomingDamage) override;

    void rest() override;
    std::string statusLine() const override;
};


#endif //RPGGAME_ROGUE_H
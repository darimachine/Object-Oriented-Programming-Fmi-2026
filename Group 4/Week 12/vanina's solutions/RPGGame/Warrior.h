#ifndef RPGGAME_WARRIOR_H
#define RPGGAME_WARRIOR_H

#include "Character.h"

class Warrior : public Character {
    int armor;

    static constexpr int REST_HEALTH = 10;

public:
    Warrior(const std::string& name, int maxHp, std::unique_ptr<Weapon> w, int armor);

    std::string statusLine() const override;

    void attack(Character& target) override;
    void defend(int incoming) override;

    void rest() override;
};


#endif //RPGGAME_WARRIOR_H
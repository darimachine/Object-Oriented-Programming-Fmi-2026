#ifndef RPGGAME_SWORD_H
#define RPGGAME_SWORD_H

#include "Weapon.h"


class Sword : public Weapon {
    static constexpr int SWORD_DAMAGE = 10;

public:
    explicit Sword(const std::string& name);
    int roll() const override;
};


#endif //RPGGAME_SWORD_H
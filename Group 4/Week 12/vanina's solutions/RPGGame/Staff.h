#ifndef RPGGAME_STAFF_H
#define RPGGAME_STAFF_H

#include "Weapon.h"
#include<random>


class Staff : public Weapon {
    int maxMana;

    mutable std::mt19937 engine{std::random_device{}()};

public:
    Staff(const std::string& name, int maxMana);

    int roll() const override;
};


#endif //RPGGAME_STAFF_H
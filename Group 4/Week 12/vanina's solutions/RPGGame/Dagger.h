#ifndef RPGGAME_DAGGER_H
#define RPGGAME_DAGGER_H

#include "Weapon.h"

#include<random>

class Dagger : public Weapon {
    bool isDrop;

    mutable std::mt19937 engine{std::random_device{}()};

public:
    Dagger(const std::string& name);

    void drop();
    bool isDropped() const;
    void pickUp();
    int roll() const override;
};


#endif //RPGGAME_DAGGER_H
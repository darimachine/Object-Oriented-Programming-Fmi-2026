#ifndef RPGGAME_WEAPON_H
#define RPGGAME_WEAPON_H

#include<string>

class Weapon {
    std::string name;

public:
    explicit Weapon(const std::string& name);
    virtual ~Weapon() = default;

    virtual int roll() const = 0;
};


#endif //RPGGAME_WEAPON_H

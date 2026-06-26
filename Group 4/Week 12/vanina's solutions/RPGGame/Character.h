#ifndef RPGGAME_CHARACTER_H
#define RPGGAME_CHARACTER_H

#include<string>
#include<vector>
#include<memory>

#include "StatucEffect.h"
#include "Weapon.h"

class Character {
protected:
    std::string name;
    int hp;
    int maxHp;
    std::vector<std::unique_ptr<StatusEffect>> status;
    std::unique_ptr<Weapon> weapon;

    int damageReduce = 0;
    bool isStunned = false;

public:
    Character(const std::string& name, int maxHp, std::unique_ptr<Weapon> w);

    const std::string& getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getDamageReduce() const;
    Weapon* getWeapon() const;
    std::vector<std::unique_ptr<StatusEffect>>& getEffects();

    std::string getStatus() const;

    bool getStun() const;
    void stun();

    void setDamageReduce(int damageReduce);
    void addEffect(std::unique_ptr<StatusEffect> effect);

    virtual void attack(Character& target) = 0;
    virtual void defend(int incomingDamage) = 0;

    void takeDamage(int amount);
    bool isDead() const;

    virtual std::string statusLine() const = 0;
    virtual void rest() = 0;

    virtual ~Character() = default;
};


#endif //RPGGAME_CHARACTER_H
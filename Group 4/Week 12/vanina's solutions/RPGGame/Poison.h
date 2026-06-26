#ifndef RPGGAME_POISON_H
#define RPGGAME_POISON_H

#include "StatucEffect.h"


class Poison : public StatusEffect {
    static constexpr int POISON_DAMAGE = 5;

public:
    explicit Poison(int duration);

    void tick(Character& target) override;
    std::string getStatus() const override;
};


#endif //RPGGAME_POISON_H
#ifndef RPGGAME_BURN_H
#define RPGGAME_BURN_H

#include "StatucEffect.h"

class Burn : public StatusEffect {
    static constexpr int BURN_DAMAGE = 8;

public:
    explicit Burn(int duration);

    void tick(Character &target) override;
    std::string getStatus() const override;
};


#endif //RPGGAME_BURN_H
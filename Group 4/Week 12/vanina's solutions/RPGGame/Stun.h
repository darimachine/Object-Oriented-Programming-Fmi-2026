#ifndef RPGGAME_STUN_H
#define RPGGAME_STUN_H

#include "StatucEffect.h"

class Stun : public StatusEffect {
public:
    explicit Stun(int duration);

    void tick(Character &target) override;
    std::string getStatus() const override;
};


#endif //RPGGAME_STUN_H
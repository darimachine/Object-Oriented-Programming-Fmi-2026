#ifndef RPGGAME_STATUCEFFECT_H
#define RPGGAME_STATUCEFFECT_H
#include "Character.h"


class StatusEffect {
protected:
    int duration;

public:
    explicit StatusEffect(int duration);
    virtual void tick(Character& target) = 0;
    bool isExpired() const;

    virtual std::string getStatus() const = 0;

    virtual ~StatusEffect() = default;
};


#endif //RPGGAME_STATUCEFFECT_H
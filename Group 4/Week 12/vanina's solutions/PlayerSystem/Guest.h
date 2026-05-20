#ifndef PLAYERSYSTEM_GUEST_H
#define PLAYERSYSTEM_GUEST_H

#include "Player.h"


class Guest : public Player {
    int maxTimePlayed;

public:
    Guest(double points, int maxTimePlayed);

    bool levelUp() override;

    void print() const override;
};


#endif //PLAYERSYSTEM_GUEST_H
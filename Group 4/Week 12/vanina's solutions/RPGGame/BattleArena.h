#ifndef RPGGAME_BATTLEARENA_H
#define RPGGAME_BATTLEARENA_H

#include <memory>
#include <vector>

#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "StatucEffect.h"
// #include "Stun.h"
// #include "Poison.h"
// #include "Burn.h"

class BattleArena {
    static constexpr size_t MAX_PLAYERS = 2;

    std::vector<std::unique_ptr<Character>> characters;

public:
    BattleArena(std::unique_ptr<Character> player1, std::unique_ptr<Character> player2);

    void runRound();
    void tickEffects();

    bool isOver() const;
    void addEffect(int characterIndex, std::unique_ptr<StatusEffect> effect) const;
};


#endif //RPGGAME_BATTLEARENA_H
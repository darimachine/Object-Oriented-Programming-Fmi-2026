#include "BattleArena.h"

#include <iostream>
#include <ostream>

#include "DeadCharacterException.h"
#include "OutOfManaException.h"

BattleArena::BattleArena(std::unique_ptr<Character> player1,
                         std::unique_ptr<Character> player2) {
    characters.push_back(std::move(player1));
    characters.push_back(std::move(player2));
}

void BattleArena::runRound() {
    tickEffects();

    try {
        if (!characters[0]->getStun() && !characters[0]->isDead()) {
            characters[0]->attack(*characters[1]);
        }
    }
    catch (const OutOfManaException& e) {
        std::cout << e.what() << std::endl;
        characters[0]->rest();
    }
    catch (const DeadCharacterException& e) {
        // std::cout << e.what() << std::endl;
        return;
    }


    try {
        if (!characters[1]->getStun() && !characters[1]->isDead()) {
            characters[1]->attack(*characters[0]);
        }
    }
    catch (const OutOfManaException& e) {
        std::cout << e.what() << std::endl;
        characters[1]->rest();
    }
    catch (const DeadCharacterException& e) {
        // std::cout << e.what() << std::endl;
        return;
    }

    for (const auto& character : characters) {
        std::cout << character->statusLine() << "\n";
    }
}

void BattleArena::tickEffects() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        auto& effects = characters[i]->getEffects();

        for (auto it = effects.begin(); it != effects.end();) {
            (*it)->tick();

            if ((*it)->isExpired()) {
                it = effects.erase(it);
            }
            else {
                ++it;
            }
        }
    }
}

bool BattleArena::isOver() const {
    return characters[0]->isDead() || characters[1]->isDead();
}

void BattleArena::addEffect(int characterIndex, std::unique_ptr<StatusEffect> effect) const {
    characters[characterIndex]->addEffect(std::move(effect));
}

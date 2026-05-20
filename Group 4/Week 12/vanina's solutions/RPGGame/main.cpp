#include <iostream>
#include <memory>

#include "BattleArena.h"
#include "Burn.h"
#include "Poison.h"
#include "Stun.h"
#include "Staff.h"
#include "Sword.h"

int main() {

    std::unique_ptr<Character> warrior1 = std::make_unique<Warrior>("Stoyan",
        10,std::make_unique<Sword>("sword1"), 15);

    std::unique_ptr<Character> mage1 = std::make_unique<Mage>("Garjo",
        100,std::make_unique<Staff>("staff1", 10), 30);


    BattleArena battle(std::move(warrior1), std::move(mage1));

    // std::unique_ptr<Poison> poison = std::make_unique<Poison>(3);
    Poison p(3);
    Burn b(65);

    battle.addEffect(0, std::make_unique<Poison>(3));
    battle.addEffect(1, std::make_unique<Stun>(1));


}
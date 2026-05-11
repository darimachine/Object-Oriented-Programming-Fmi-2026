#include <iostream>
#include <memory>

#include "BattleArena.h"

#include "Warrior.h"
#include "Mage.h"

#include "Sword.h"
#include "Staff.h"

#include "Poison.h"
#include "Stun.h"

int main()
{
    srand(time(nullptr));

    Weapon* sword = new Sword("Basic Sword");
    Weapon* staff = new Staff("Magic Staff", 50);

    Warrior ivan("Ivan", 80, 100, sword, 15);
    Mage georgi("Georgi", 60, 120, staff, 30, 65);

    BattleArena arena(&ivan, &georgi);

    arena.addEffect(0, std::make_unique<Poison>(3));
    arena.addEffect(1, std::make_unique<Stun>(1));

    int round = 1;

    while (!arena.isOver())
    {
        std::cout << "\nRound " << round << "\n";

        arena.runRound();
        round++;
    }

    std::cout << "\nWinner\n";

    if (ivan.isDead())
    {
        std::cout << georgi.getName() << " wins!\n";
    }
    else
    {
        std::cout << ivan.getName() << " wins!\n";
    }

    delete sword;
    delete staff;

    return 0;
}
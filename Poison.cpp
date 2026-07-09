#include "Character.h"
#include "Poison.h"

Poison::Poison(int duration):StatusEffect(duration){}

void Poison::tick(Character& target)
{
    try
    {
        target.takeDamage(5);
    }
    catch (const DeadCharacterException& ex)
    {
        std::cout << ex.what() << '\n';
    }

    duration--;
}
#include "Character.h"
#include "Burn.h"

Burn::Burn(int duration):StatusEffect(duration){}

void Burn::tick(Character& target)
{
    try
    {
        target.takeDamage(8);
    }
    catch (const DeadCharacterException& ex)
    {
        std::cout << ex.what() << '\n';
    }

    target.addDamageReduction(3);
    duration--;
}
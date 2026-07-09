#include "Engine.h"

void Engine::setHorsepower(int hp)
{
    if (hp > 0)
        horsepower = hp;
}

int Engine::getHorsepower() const
{
    return horsepower;
}

void Engine::print(std::ostream& os) const
{
    CarPart::print(os);
    os << " - " << horsepower << " hp";
}
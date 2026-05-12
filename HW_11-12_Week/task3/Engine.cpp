#include "Engine.h"
#include <iostream>
#include "CarPartException.h"

Engine::Engine(unsigned id, std::string manufacturer, std::string description, int hp) : CarPart(id, manufacturer, description), hp(hp)
{
    if (hp <= 0)
    {
        throw CarPartException("Horsepower must be greater than 0.");
    }
    if (hp > 2000)
    {
        throw CarPartException("Horsepower cannot exceed 2000.");
    }
}

void Engine::printExtended(std::ostream& os) const
{
	os << hp << " hp";
}

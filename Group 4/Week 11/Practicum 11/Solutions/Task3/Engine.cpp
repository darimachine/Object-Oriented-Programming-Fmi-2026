#include "Engine.h"

Engine::Engine(std::string manufacturerName, std::string description, unsigned horsePower) : CarPart(std::move(manufacturerName), std::move(description))
{
    setHorsePower(horsePower);
}

unsigned Engine::getHorsePower() const
{
    return horsePower;
}

void Engine::setHorsePower(unsigned horsePower)
{
    if (horsePower > 0) this->horsePower = horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& e)
{
    e.printBase(os) << " - " << e.horsePower << " hp";
    return os;
}

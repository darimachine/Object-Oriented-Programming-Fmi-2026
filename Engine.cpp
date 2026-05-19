#include "Engine.h"

Engine::Engine(unsigned int id, std::string n, std::string desc, int hp)
    : CarPart(id, n, desc), horsePower(hp) {
}

void Engine::printInfo(std::ostream& os) const {
    os << horsePower << " hp";
}
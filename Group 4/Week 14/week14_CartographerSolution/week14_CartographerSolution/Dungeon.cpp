#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon(std::string name, const double x, const double y,
    const short threatLevel, const int depth) :
    Landmark(std::move(name), x, y, threatLevel), depth(depth)
{
}

std::string Dungeon::getType() const
{
    return std::move(std::string("Dungeon"));
}

void Dungeon::print() const
{
    std::cout << "(" << coordinates.x << ", " << coordinates.y << "): "
        << name << " dungeon with " << depth << " depth "
        << "and a threat level of " << threatLevel << std::endl;
}

std::unique_ptr<Landmark> Dungeon::clone()
{
    return std::unique_ptr<Dungeon>(this);
}

#include "Ruin.h"
#include <iostream>

Ruin::Ruin(std::string name, const double x, const double y,
    const short threatLevel, std::string civilization) :
    Landmark(std::move(name), x, y, threatLevel), civilization(std::move(civilization))
{
}

std::string Ruin::getType() const
{
    return std::move(std::string("Ruin"));
}

void Ruin::print() const
{
    std::cout << "(" << coordinates.x << ", " << coordinates.y << "): "
        << name << " ruin, home of the " << civilization << " civilization "
        << "and a threat level of " << threatLevel << std::endl;
}

std::unique_ptr<Landmark> Ruin::clone()
{
    return std::unique_ptr<Ruin>(this);
}

#include "Settlement.h"
#include <iostream>

Settlement::Settlement(std::string name, const double x, const double y, 
    const short threatLevel, const int population) :
    Landmark(std::move(name), x, y, threatLevel), population(population)
{
}

std::string Settlement::getType() const
{
    return std::move(std::string("Settlement"));
}

void Settlement::print() const
{
    std::cout << "(" << coordinates.x << ", " << coordinates.y << "): "
        << name << " settlement with " << population << " population "
        << "and a threat level of " << threatLevel << std::endl;
}

std::unique_ptr<Landmark> Settlement::clone()
{
    return std::unique_ptr<Settlement>(this);
}

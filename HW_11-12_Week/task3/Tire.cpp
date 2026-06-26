#include "Tire.h"
#include <stdexcept>
#include <iostream>
#include "CarPartException.h"

Tire::Tire(unsigned id, std::string manufacturer, std::string description, int width, int profile, int rimSize)
    : CarPart(id, manufacturer, description), width(width), profile(profile), rimSize(rimSize)
{
    if (width < 155 || width > 365)
    {
        throw CarPartException("Tire width must be between 155 and 365 mm.");
    }
    if (profile < 30 || profile > 80)
    {
        throw CarPartException("Tire profile must be between 30 and 80.");
    }
    if (rimSize < 13 || rimSize > 21)
    {
        throw CarPartException("Rim size must be between 13 and 21 inches.");
    }
}

void Tire::printExtended(std::ostream& os) const
{
    os << width << "/" << profile << "R" << rimSize;
}

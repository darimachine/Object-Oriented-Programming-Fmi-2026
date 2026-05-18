#include "Wheel.h"

Wheel::Wheel(std::string manufacturerName, std::string description, unsigned width, unsigned profile, unsigned diameter) : CarPart(std::move(manufacturerName), std::move(description))
{
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

unsigned Wheel::getWidth() const
{
    return width;
}

void Wheel::setWidth(unsigned width)
{
    if (width >= 155 && width <= 365) this->width = width;
}

unsigned Wheel::getProfile() const
{
    return profile;
}

void Wheel::setProfile(unsigned profile)
{
    if (profile >= 30 && profile <= 80) this->profile = profile;
}

unsigned Wheel::getDiameter() const
{
    return diameter;
}

void Wheel::setDiameter(unsigned diameter)
{
    if (diameter >= 13 && diameter <= 21) this->diameter = diameter;
}

std::ostream& operator<<(std::ostream& os, const Wheel& w)
{
    w.printBase(os) << " - " << w.width << "/" << w.profile << "R" << w.diameter;
    return os;
}

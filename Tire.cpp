#include "Tire.h"

int Tire::getWidth_() const
{
    return width;
}

int Tire::getProfile_() const
{
    return profile;
}

int Tire::getRimSize() const
{
    return rimSize;
}

void Tire::setWidth(int w) {
    if (w >= 155 && w <= 365) width = w;
}

void Tire::setProfile(int p) {
    if (p >= 30 && p <= 80) profile = p;
}

void Tire::setRimSize(int r) {
    if (r >= 13 && r <= 21) rimSize = r;
}

void Tire::print(std::ostream& os) const {
    CarPart::print(os);
    os << " - " << width << "/" << profile << "R" << rimSize;
}
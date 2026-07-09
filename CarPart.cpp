#include "CarPart.h"

unsigned int CarPart::getId() const
{
    return id;
}

std::string CarPart::getManufacturer() const
{
    return manufacturer;
}

std::string CarPart::getDescription() const
{
    return description;
}

void CarPart::setId(unsigned int newId) {
    if (newId > 0) id = newId;
    else id = 1;
}

void CarPart::setManufacturer(const std::string& m)
{
    manufacturer = m;
}

void CarPart::setDescription(const std::string& d)
{
    description = d;
}

void CarPart::print(std::ostream& os) const {
    os << "(" << id << ") by " << manufacturer << " - " << description;
}

std::ostream& operator<<(std::ostream& os, const CarPart& cp) {
    cp.print(os);
    return os;
}
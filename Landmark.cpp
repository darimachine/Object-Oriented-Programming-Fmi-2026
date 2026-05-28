#include "Landmark.h"

Landmark::Landmark(const std::string& name, const Coords& coords, int threat)
	: name(name), coords(coords) {
    if (threat < 0 || threat >10) {
		throw std::invalid_argument("Threat level must be between 0 and 10.");
    }
    this->threat = threat;
}

std::string Landmark::getName() const
{
    return name;
}

void Landmark::print() const
{
    std::cout << "Name: " << name
        << " | Coords: (" << coords.x << ", " << coords.y << ")"
        << " | Threat level: " << threat;
}



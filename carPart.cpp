#include "carPart.h"
#include <stdexcept>

unsigned CarPart::counter = 0;

CarPart::CarPart(std::string _manufacturer, std::string _description)
	:manufacturer(_manufacturer), description(_description)
{
	id = ++counter;
}

void CarPart::print(std::ostream& os) const
{
    os << "(" << id << ") manufactured by " << manufacturer<< " - " << description;
}

Engine::Engine(const std::string& _manufacturer, const std::string& _description, int _horsepower)
	: CarPart(_manufacturer, _description), horsePower(_horsepower) {}

void Engine::print(std::ostream& os) const
{
    CarPart::print(os);
    os << " - " << horsePower << " hp";
}

Tire::Tire(const std::string& _manufacturer, const std::string& _description, int _width, int _profile, int _rimSize)
	: CarPart(_manufacturer, _description)
{
    if (_width < 155 || _width > 365)
        throw std::invalid_argument("Invalid width!");

    if (_profile < 30 || _profile > 80)
        throw std::invalid_argument("Invalid profile!");

    if (_rimSize < 13 || _rimSize > 21)
        throw std::invalid_argument("Invalid rim size!");

    this->width = _width;
    this->profile = _profile;
    this->rimSize = _rimSize;
}

void Tire::print(std::ostream& os) const
{
    CarPart::print(os);
    os << " - " << width << "/" << profile << "R" << rimSize;
}

Battery::Battery(const std::string& _manufacturer, const std::string& _description, int _ampHours, const std::string& _batteryId)
	: CarPart(_manufacturer, _description), ampHours(_ampHours), batteryId(_batteryId) {}

void Battery::print(std::ostream& os) const
{
    CarPart::print(os);
    os << " - " << ampHours << " Ah";
}

std::ostream& operator<<(std::ostream& os, const CarPart& part)
{
    part.print(os);
    return os;
}
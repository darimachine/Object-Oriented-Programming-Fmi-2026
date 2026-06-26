#include "CarPart.h"
unsigned int CarPart::num = 1;
CarPart::CarPart(std::string _name, std::string _descr) : name(_name), descr(_descr)
{
	id = num;
	num++;
}

void CarPart::print(std::ostream& os) const
{
    os << "(" << id << ") by " << name << " - " << descr << " ";
}


std::ostream& operator<<(std::ostream& os,const CarPart& part)
{
    part.print(os);
    return os;
}


void Accumulator::print(std::ostream& os) const
{
    CarPart::print(os);
    os << capacity << " Ah";
}

void Engine::print(std::ostream& os) const
{
    CarPart::print(os);
	os << horsePower << " hp";
}

Tires::Tires(std::string _name, std::string _descr, int _width, int _profile, int _diameter)
	:CarPart(_name, _descr)
{
	if (_width >= 155 && _width <= 365) {
		width = _width;
	}
	if (_profile >= 30 && _profile <= 80) {
		profile = _profile;
	}
	if (_diameter <= 21 && _diameter >= 13) {
		diameter = _diameter;
	}
}

void Tires::print(std::ostream& os) const
{
    CarPart::print(os);
    os << width << "/" << profile << "R" << diameter;
}

Accumulator::Accumulator(std::string _name, std::string _descr, int _capacity, std::string _batteryId)
	:CarPart(_name, _descr), capacity(_capacity), batteryId(_batteryId)
{
}

Engine::Engine(std::string _name, std::string _descr, int _horsePower)
	:CarPart(_name, _descr), horsePower(_horsePower)
{
}
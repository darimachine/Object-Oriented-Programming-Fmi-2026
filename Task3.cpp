#include "Task3.h"
#include <stdexcept>

void CarPart::print(std::ostream& os) const {
	os << "(" << id << ") by "<< manifacturer << " - " << description << " - ";
}

CarPart::CarPart(unsigned int _id, std::string& _manifacturer, std::string& _description)
	: id(_id), manifacturer(_manifacturer), description(_description) {}

std::ostream& operator<<(std::ostream& os, const CarPart& cp) {
	cp.print(os);
	return os;
}

void Engine::print(std::ostream& os) const {
	CarPart::print(os);
	os << horsePower << " hp" << std::endl;
}

Engine::Engine(unsigned int _id, std::string& m, std::string& d, unsigned int hp)
	: CarPart(_id, m, d), horsePower(hp) {}

void Tyre::validateParameters(unsigned width, unsigned profile, unsigned diameter) {
	if (width < 155 || width > 365)
		throw std::out_of_range("Width must be between 155 and 365 mm!");
	if (profile < 30 || profile > 80)
		throw std::out_of_range("Profile must be between 30 and 80!");
	if (diameter < 13 || diameter > 21)
		throw std::out_of_range("Diameter must be between 13 and 21 inches!");
}

void Tyre::print(std::ostream& os) const {
	CarPart::print(os);
	os << width << "/" << profile << "R" << diameter << std::endl;
}

Tyre::Tyre(unsigned int _id, std::string& m, std::string& desc, unsigned int w, unsigned int p, unsigned int d)
	: CarPart(_id, m, desc), width(w), profile(p), diameter(d) {
	validateParameters(w, p, d);
}

void Accumulator::print(std::ostream& os) const {
	CarPart::print(os);
	os << capacity << "Ah" << std::endl;
}

Accumulator::Accumulator(unsigned int _id, std::string& m, std::string& d, unsigned int c, std::string& _batteryId)
	: CarPart(_id, m, d), capacity(c), batteryId(_batteryId) {}

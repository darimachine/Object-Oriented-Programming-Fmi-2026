#include "Tires.h"

Tires::Tires(unsigned int id, std::string name, std::string desc, int w, int p, int d)
: CarPart(id, name, desc), width(w), profile(p), diameter(d) {}

void Tires::printInfo(std::ostream& os) const
{
	os << width << "/" << profile << "R" << diameter;
}

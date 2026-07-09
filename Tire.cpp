#include "Tire.h"
#include<stdexcept>

Tire::Tire(const string& producer, const string& description, double width, double profil, double diameter):
	CarPart(producer,description),width(width),profil(profil),diameter(diameter)
{
	if (width < 155 || width>365)
	{
		throw std::invalid_argument("Width out of range!");
	}

	if (profil < 30 || profil>80)
	{
		throw std::invalid_argument("Profil out of range!");
	}

	if (diameter < 13 || diameter>21)
	{
		throw std::invalid_argument("Diameter out of range");
	}
}

ostream& operator<<(ostream& os, const Tire& t)
{
	const CarPart& base = t;
	return os << base << " - " << 
		t.width << '/' << t.profil << 'R' << t.diameter << '\n';
}
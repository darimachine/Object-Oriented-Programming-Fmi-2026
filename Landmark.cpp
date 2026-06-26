#include "Landmark.h"

std::string Landmark::getName() const
{
	return name;
}

Landmark::Landmark(const std::string &n, Coords c1, int t):name(n), threat(t)
{
	if (t < 0 || t>10) throw std::invalid_argument("Invalid threat level!");
	c.x = c1.x;
	c.y = c1.y;
}

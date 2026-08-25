#pragma once
class Coordinates
{
public:

	double x = 0;
	double y = 0;

	Coordinates() = default;
	Coordinates(const double x, const double y) : x(x), y(y) {}
};


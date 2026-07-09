#include "Accumulator.h"
#include<stdexcept>

Accumulator::Accumulator(const string& producer, const string& description, double capacity, const string& batteryId) :
	CarPart(producer,description),batteryId(batteryId),capacity(capacity)
{
	if (capacity < 0)
	{
		throw std::invalid_argument("Capacity cannot be negative!");
	}
}

ostream& operator<<(ostream& os, const Accumulator& a)
{
	const CarPart& base = a;
	return os << base << " - " << a.capacity << " Ah" << '\n';
}
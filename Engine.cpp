#include "Engine.h"
#include<stdexcept>

Engine::Engine(const string& producer, const string& description, double horsePower) :
	CarPart(producer, description),horsePower(horsePower)
{
	if (horsePower < 0)
	{
		throw std::invalid_argument("Horse power cannot be negative!");
	}
}

ostream& operator<<(ostream& os, const Engine& e)
{
	const CarPart& base = e;
	return os << base << " - " << e.horsePower << " hp" << '\n';
}
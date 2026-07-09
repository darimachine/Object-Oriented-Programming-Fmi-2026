#pragma once
#include"CarPart.h"

class Accumulator:public CarPart
{
private:
	double capacity;
	string batteryId;

public:
	Accumulator(const string& producer, const string& description, double capacity, const string& batteryId);

	friend ostream& operator<<(ostream& os, const Accumulator& a);
};


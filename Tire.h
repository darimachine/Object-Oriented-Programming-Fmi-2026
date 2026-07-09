#pragma once
#include"CarPart.h"

class Tire:public CarPart
{
private:
	double width;
	double profil;
	double diameter;

public:
	Tire() = default;
	Tire(const string& producer, const string& description,double width, double profil, double diameter);

	friend ostream& operator<<(ostream& os, const Tire& t);
};


#pragma once
#include"CarPart.h"

class Engine:public CarPart
{
private:
	double horsePower;

public:
	Engine() = default;
	Engine(const string& producer, const string& description, double horsePower);

	friend ostream& operator<<(ostream& os, const Engine& e);
};


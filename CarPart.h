#pragma once
#include<string>
#include<fstream>
using namespace std;

class CarPart
{
private:
	static unsigned nextId;
	unsigned id;
	string producer;
	string description;

public:
	CarPart() = default;
	CarPart(const string& producer, const string& description);

	friend ostream& operator<<(ostream& os, const CarPart& cp);
};


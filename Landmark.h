#pragma once
#include"Utils.h"
#include<string>
using namespace std;

class Landmark
{
private:
	static constexpr unsigned MAX_THREAT = 10;
	string name;
	Coordinates coords;
	unsigned threat;

public:
	Landmark() = default;
	Landmark(const string& name, Coordinates coords, unsigned threat);

	virtual string getType()const = 0;
	virtual void print()const = 0;
	virtual ~Landmark() = default;

	const string& getName()const;
	Coordinates getCoords()const;
	unsigned getThreat()const;
};


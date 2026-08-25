#pragma once
#include "Coordinates.h"
#include <string>
#include <iostream>

class Landmark
{
protected:

	std::string name;
	Coordinates coordinates;
	short threatLevel = -1;

public:

	Landmark() = default;
	Landmark(std::string name, const double x, const double y, const short threatLevel);

	virtual std::string getType() const = 0;
	virtual void print() const = 0;
	virtual std::unique_ptr<Landmark> clone() = 0;

	void setThreatLevel(const short threatLevel);

	std::string getName() const;
	short getThreatLevel() const;

	virtual ~Landmark() = default;
};


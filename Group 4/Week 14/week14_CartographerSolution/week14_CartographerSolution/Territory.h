#pragma once
#pragma once
#include "Coordinates.h"
#include <string>
#include <iostream>
#include <vector>

#include "Landmark.h"
#include "Settlement.h"
#include "Dungeon.h"
#include "NaturalFeature.h"
#include "Ruin.h"

class Territory
{
private:

	std::vector<std::unique_ptr<Landmark>> landmarks;

public:

	Territory() = default;

	Territory(const Territory& other);

	void addLandmark(std::unique_ptr<Landmark> landmark);
	std::unique_ptr<Landmark> removeLandmark(const std::string& name);
	void setDangetLevel(const short dangerLevel);
	bool hasLandmark(const std::string& name);
	void print();

	unsigned getDangerLevel() const;
};


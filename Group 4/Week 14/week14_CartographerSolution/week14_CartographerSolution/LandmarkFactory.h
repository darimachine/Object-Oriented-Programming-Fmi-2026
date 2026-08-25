#pragma once
#include "Landmark.h"
#include "Settlement.h"
#include "Dungeon.h"
#include "NaturalFeature.h"
#include "Ruin.h"

class LandmarkFactory
{
public:

	static std::unique_ptr<Landmark> create(
		const std::string& type,
		const std::string& name,
		Coordinates coordinates,
		const int threat,
		const std::string extra = ""
	);

};


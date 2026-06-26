#pragma once
#include "Landmark.h"
#include <memory>
#include "FeatureKind.h"
#include <string>
#include "Coordinates.h"

class LandmarkFactory
{
	public:
		static std::unique_ptr<Landmark> create(const std::string& type, const std::string& name,
			Coordinates coords, int threat, const std::string& extra = "");

		static std::unique_ptr<Landmark> create(const std::string& args);
};


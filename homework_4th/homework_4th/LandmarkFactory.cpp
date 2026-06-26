#include "LandmarkFactory.h"
#include <stdexcept>
#include "Settlement.h"
#include "Dungeon.h"
#include "Ruin.h"
#include "NaturalFeature.h"
#include "FeatureKind.h"
#include <sstream>

std::unique_ptr<Landmark> LandmarkFactory::create(const std::string& type, const std::string& name,
	Coordinates coords, int threat, const std::string& extra)
{
	if (type == "settlement")
	{
		int population = std::stoi(extra);
		return std::make_unique<Settlement>(name, coords, threat, population);
	}
	else if (type == "dungeon")
	{
		int depth = std::stoi(extra);
		return std::make_unique<Dungeon>(name, coords, threat, depth);
	}
	else if (type == "ruin")
	{
		return std::make_unique<Ruin>(name, coords, threat, extra);
	}
	else if (type == "natural")
	{
		FeatureKind kind = parseFeatureKind(extra);
		return std::make_unique<NaturalFeature>(name, coords, threat, kind);
	}
	else
	{
		throw std::invalid_argument("the type was not recognised");
	}
}

std::unique_ptr<Landmark> LandmarkFactory::create(const std::string& args)
{
	std::istringstream iss(args);
	std::string type, name, extra;
	int x, y, threat;

	iss >> type >> name >> x >> y >> threat;

	if (!(iss >> type >> name >> x >> y >> threat))
	{
		throw std::invalid_argument("Invalid arguments format for Landmark!");
	}

	if (!(iss >> extra))
	{
		extra = "";
	}
	
	Coordinates coords(x, y);
	return create(type, name, coords, threat, extra);
}

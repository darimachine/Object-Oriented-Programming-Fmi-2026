#include "LandmarkFactory.h"
#include "Settlement.h"
#include "Dungeon.h"
#include "NaturalFeature.h"
#include "Ruin.h"
#include <string>

FeatureKind stringToFeature(const std::string& s) {
    if (s == "Volcano")
        return FeatureKind::Volcano;

    if (s == "Forest")
        return FeatureKind::Forest;

    if (s == "Lake")
        return FeatureKind::Lake;

    if (s == "Bog")
        return FeatureKind::Bog;

    if (s == "Mountain")
        return FeatureKind::Mountain;

    if (s == "Desert")
        return FeatureKind::Desert;

    throw std::invalid_argument("Unknown feature kind " + s);
}

std::unique_ptr<Landmark> LandmarkFactory::create(const std::string& type, const std::string& name, Coords coords, int threat, const std::string& extra)
{
    if (type == "settlement") return std::make_unique<Settlement>(name, coords, threat, stoi(extra));
    else if (type == "dungeon") return std::make_unique<Dungeon>(name, coords, threat, stoi(extra));
    else if (type == "ruin") return std::make_unique<Ruin>(name, coords, threat, extra);
    else if (type == "natural") return std::make_unique<NaturalFeature>(name, coords, threat, stringToFeature(extra));
    else throw std::invalid_argument("Invalid type!");
}

#include "LandmarkFactory.h"
#include "Settlement.h"
#include "Dungeon.h"
#include "Ruin.h"
#include "NaturalFeature.h"

std::unique_ptr<Landmark> LandmarkFactory::create(const std::string& type, const std::string& name, Coords coords, int threat, const std::string& extra)
{
    if (type == "settlement") {
        int population = extra.empty() ? 0 : std::stoi(extra);
        return std::make_unique<Settlement>(name, coords, threat, population);
    }
    else if (type == "dungeon") {
        int depth = extra.empty() ? 1 : std::stoi(extra);
        return std::make_unique<Dungeon>(name, coords, threat, depth);
    }
    else if (type == "ruin") {
        return std::make_unique<Ruin>(name, coords, threat, extra);
    }
    else if (type == "natural") {
        FeatureKind kind = FeatureKind::Forest; // Стойност по подразбиране
        if (extra == "Volcano") kind = FeatureKind::Volcano;
        else if (extra == "Forest") kind = FeatureKind::Forest;
        else if (extra == "Lake") kind = FeatureKind::Lake;
        else if (extra == "Bog") kind = FeatureKind::Bog;
        else if (extra == "Mountain") kind = FeatureKind::Mountain;
        else if (extra == "Desert") kind = FeatureKind::Desert;

        return std::make_unique<NaturalFeature>(name, coords, threat, kind);
    }

    throw std::invalid_argument("Unknown landmark type: " + type);
}

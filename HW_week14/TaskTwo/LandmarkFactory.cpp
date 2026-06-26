#include "LandmarkFactory.h"
#include "Settlement.h"
#include "Dungeon.h"
#include "Ruin.h"
#include "FeatureKind.h"
#include "NaturalFeature.h"
#include <stdexcept>

std::unique_ptr<Landmark> LandmarkFactory::create(const std::string& type, const std::string& name, Coords coords, int threat, const std::string& extra)
{
    if (type == "settlement") 
    {
        int pop = 0;
        if (!extra.empty()) 
        {
            pop = parseIntFromString(extra);
        }
        return std::make_unique<Settlement>(name, coords, threat, pop);
    }
    if (type == "dungeon") 
    {
        int depth = 1;
        if (!extra.empty()) 
        {
            depth = parseIntFromString(extra);
        }
        return std::make_unique<Dungeon>(name, coords, threat, depth);
    }
    if (type == "ruin") 
    {
        return std::make_unique<Ruin>(name, coords, threat, extra);
    }
    if (type == "natural")
    {
        FeatureKind kind = FeatureKind::Forest;
        if (!extra.empty()) 
        {
            kind = featureKindFromString(extra);
        }
        return std::make_unique<NaturalFeature>(name, coords, threat, kind);
    }
    throw std::invalid_argument("Unknown landmark type: " + type);
}

int LandmarkFactory::parseIntFromString(const std::string& string)
{
    int result = 0;
    for (char charche : string) 
    {
        if (charche < '0' || charche > '9')
        {
            break;
        }
        result = result * 10 + (charche - '0');
    }
    return result;
}

#include "LandmarkFactory.h"
#include"Settlement.h"
#include"Dungeon.h"
#include"NaturalFeature.h"
#include"Ruin.h"
#include<stdexcept>

unique_ptr<Landmark> LandmarkFactory::create(const string& type, const string& name, Coordinates coords, int threat, const string& extra)
{
    if (type == "Settlement")
    {
        return make_unique<Settlement>(name, coords, threat, stoi(extra));
    }
    else if (type == "Dungeon")
    {
        return make_unique<Dungeon>(name, coords, threat, stoi(extra));
    }
    else if (type == "NaturalFeature")
    {
        return make_unique<NaturalFeature>(name, coords, threat, Utils::convertStringToFeature(extra));
    }
    else if (type == "Ruin")
    {
        return make_unique<Ruin>(name, coords, threat, extra);
    }

    throw invalid_argument("Invalid type.");
}

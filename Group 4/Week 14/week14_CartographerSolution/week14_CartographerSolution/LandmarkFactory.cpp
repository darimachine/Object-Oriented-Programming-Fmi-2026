#include "LandmarkFactory.h"
#include "Settlement.h"
#include "Dungeon.h"
#include "Ruin.h"
#include "NaturalFeature.h"

std::unique_ptr<Landmark> LandmarkFactory::create(
        const std::string& type, 
        const std::string& name, 
        Coordinates coordinates, 
        const int threat, 
        const std::string extra
)
{
    
    if (type == "settlement")
    {
        return std::make_unique<Settlement>
            (std::move(name), coordinates.x, coordinates.y, threat, std::stoi(extra));
    }
    if (type == "dungeon")
    {
        return std::make_unique<Dungeon>
            (std::move(name), coordinates.x, coordinates.y, threat, std::stoi(extra));
    }
    if (type == "ruin")
    {
        return std::make_unique<Ruin>
            (std::move(name), coordinates.x, coordinates.y, threat, extra);
    }
    if (type == "natural")
    {
        return std::make_unique<NaturalFeature>
            (std::move(name), coordinates.x, coordinates.y, threat, 
                NaturalFeature::stringToKind(extra));
    }

    throw std::invalid_argument("A landmark of such type doesn't exist");
}

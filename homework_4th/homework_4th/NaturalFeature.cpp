#include "NaturalFeature.h"
#include <print>
NaturalFeature::NaturalFeature(const std::string& inpName, const Coordinates& inpCoords,
    unsigned int inpThreat, FeatureKind inpKind) : Landmark(inpName, inpCoords, inpThreat), kind(inpKind)
{
}
std::string NaturalFeature::getType() const
{
    return "NaturalFeature";
}

void NaturalFeature::print() const
{
    Landmark::print();
    std::println("Feature kind: {}, threat: {}", getFeatureKindAsString(), threat);
}

std::string NaturalFeature::getFeatureKindAsString() const
{
    switch (kind)
    {
    case FeatureKind::VOLCANO:
        return "volcano";

    case FeatureKind::DESERT:
        return "desert";

    case FeatureKind::LAKE:
        return "lake";

    case FeatureKind::BOG:
        return "bog";

    case FeatureKind::MOUNTAIN:
        return "mountain";

    case FeatureKind::FOREST:
        return "forest";
    }
}

#include "FeatureKind.h"
#include <stdexcept>

std::string featureKindToString(FeatureKind kind)
{
    switch (kind) 
    {
    case FeatureKind::Volcano:
        return "Volcano";
    case FeatureKind::Forest:
        return "Forest";
    case FeatureKind::Lake:
        return "Lake";
    case FeatureKind::Bog:
        return "Bog";
    case FeatureKind::Mountain:
        return "Mountain";
    case FeatureKind::Desert:
        return "Desert";
    }
    return "Unknown";
}

FeatureKind featureKindFromString(const std::string& string)
{
    if (string == "Volcano")
    {
        return FeatureKind::Volcano;
    }
    if (string == "Forest")
    {
        return FeatureKind::Forest;
    }
    if (string == "Lake")
    {
        return FeatureKind::Lake;
    }
    if (string == "Bog")
    {
        return FeatureKind::Bog;
    }
    if (string == "Mountain")
    {
        return FeatureKind::Mountain;
    }
    if (string == "Desert")
    {
        return FeatureKind::Desert;
    }
    throw std::invalid_argument("Unknown Feature Kind: " + string);
}

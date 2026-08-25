#include "NaturalFeature.h"
#include <iostream>

NaturalFeature::NaturalFeature(std::string name, const double x, const double y,
    const short threatLevel, FeatureKind kind) :
    Landmark(std::move(name), x, y, threatLevel), kind(kind)
{
}

std::string NaturalFeature::getType() const
{
    return std::move(std::string("NaturalFeature"));
}

void NaturalFeature::print() const
{
    std::cout << "(" << coordinates.x << ", " << coordinates.y << "): "
        << name << " " << kindToString(kind) << " is a natural feature "
        << "with a threat level of " << threatLevel << std::endl;
}

std::unique_ptr<Landmark> NaturalFeature::clone()
{
    return std::unique_ptr<NaturalFeature>(this);
}

NaturalFeature::FeatureKind NaturalFeature::stringToKind(const std::string& kindString)
{
    
    if (kindString == "volcano") return FeatureKind::Volcano;
    if (kindString == "bog") return FeatureKind::Bog;
    if (kindString == "desert") return FeatureKind::Desert;
    if (kindString == "lake") return FeatureKind::Lake;
    if (kindString == "forest") return FeatureKind::Forest;
    if (kindString == "mountain") return FeatureKind::Mountain;
    if (kindString == "volcano") return FeatureKind::Volcano;
    
    return FeatureKind::Unknown;
}

std::string NaturalFeature::kindToString(FeatureKind kind)
{
    switch (kind)
    {
    case FeatureKind::Volcano:
    {
        return std::move(std::string("Volcano"));
    }
    case FeatureKind::Bog:
    {
        return std::move(std::string("Bog"));
    }
    case FeatureKind::Desert:
    {
        return std::move(std::string("Desert"));
    }
    case FeatureKind::Forest:
    {
        return std::move(std::string("Forest"));
    }
    case FeatureKind::Lake:
    {
        return std::move(std::string("Lake"));
    }
    case FeatureKind::Mountain:
    {
        return std::move(std::string("Mountain"));
    }
    default:
    {
        return std::move(std::string("Uknown"));
    }


    }
}

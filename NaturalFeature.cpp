#include "NaturalFeature.h"
#include <iostream>

NaturalFeature::NaturalFeature(const std::string& n, Coords c1, int t, FeatureKind k) : Landmark(n, c1, t), kind(k) {}

std::string NaturalFeature::getType() const {
    return "natural";
}

static std::string featureKindToString(FeatureKind fk) {
    switch (fk) {
    case FeatureKind::Volcano:  return "Volcano";
    case FeatureKind::Forest:   return "Forest";
    case FeatureKind::Lake:     return "Lake";
    case FeatureKind::Bog:      return "Bog";
    case FeatureKind::Mountain: return "Mountain";
    case FeatureKind::Desert:   return "Desert";
    default:                    return "Unknown";
    }
}

void NaturalFeature::print() const {
    std::cout << "(Natural Feature) Name: " << name << ", Coords: (" << c.x << ", " << c.y << ")" << ", threat level: " << threat << ", kind: " << featureKindToString(kind) << "\n";
}

std::unique_ptr<Landmark> NaturalFeature::clone() const
{
    return std::make_unique<NaturalFeature>(*this);
}
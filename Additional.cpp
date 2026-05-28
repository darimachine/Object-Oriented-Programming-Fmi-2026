#include "Additional.h"

std::string featureKindToString(FeatureKind kind)
{
    switch (kind) {
    case FeatureKind::Volcano:  return "Volcano";
    case FeatureKind::Forest:   return "Forest";
    case FeatureKind::Lake:     return "Lake";
    case FeatureKind::Bog:      return "Bog";
    case FeatureKind::Mountain: return "Mountain";
    case FeatureKind::Desert:   return "Desert";
    default:                    return "Unknown";
    }
}

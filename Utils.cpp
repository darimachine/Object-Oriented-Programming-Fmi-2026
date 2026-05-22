#include"Utils.h"
#include<stdexcept>

string Utils::convertFeatureToString(FeatureKind feature)
{
	switch (feature)
	{
	case FeatureKind::Volcano:return "Volcano";
	case FeatureKind::Desert:return "Desert";
	case FeatureKind::Forest:return "Forest";
	case FeatureKind::Lake:return "Lake";
	case FeatureKind::Bog:return "Bog";
	case FeatureKind::Mountain:return "Mountain";
	default:throw invalid_argument("Invalid feature input.");
	}
}

FeatureKind Utils::convertStringToFeature(const string& feature)
{
	if (feature == "Volcano")
	{
		return FeatureKind::Volcano;
	}
	else if (feature == "Desert")
	{
		return FeatureKind::Desert;
	}
	else if (feature == "Lake")
	{
		return FeatureKind::Lake;
	}
	else if (feature == "Bog")
	{
		return FeatureKind::Bog;
	}
	else if (feature == "Forest")
	{
		return FeatureKind::Forest;
	}
	else if (feature == "Mountain")
	{
		return FeatureKind::Mountain;
	}

	throw invalid_argument("Invalid feature.");
}

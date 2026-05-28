#include "NaturalFeature.h"

NaturalFeature::NaturalFeature(const std::string& name, const Coords& coords, int threat, FeatureKind kind)
	: Landmark(name, coords, threat), kind(kind)
{}

std::string NaturalFeature::getType() const
{
	return "Natural Feature";
}

void NaturalFeature::print() const
{
	Landmark::print();
	std::cout << " | Kind: " << featureKindToString(kind) << "\n";
}

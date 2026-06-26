#include "NaturalFeature.h"
#include <iostream>

NaturalFeature::NaturalFeature(const std::string& name, Coords coords, int threat, FeatureKind kind) : Landmark(name, coords, threat), kind(kind)
{

}

std::string NaturalFeature::getType() const
{
	return "NaturalFeature";
}

void NaturalFeature::print() const
{
	std::cout << "Dungeon " << name << " (" << coords.x << ", " << coords.y << ")" << " | threat: " << threat << " | kind: " << featureKindToString(kind) << std::endl;
}

std::unique_ptr<Landmark> NaturalFeature::clone() const
{
	return std::make_unique<NaturalFeature>(*this);
}


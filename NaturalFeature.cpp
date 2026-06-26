#include "NaturalFeature.h"
#include<print>

NaturalFeature::NaturalFeature(const string& name, Coordinates coords, unsigned threat, FeatureKind feature):
    Landmark(name,coords,threat),feature(feature){}

string NaturalFeature::getType() const
{
    return "NaturalFeature";
}

void NaturalFeature::print() const
{
    println("Name: {}, Coordinates: {} {}, Threat: {}, Feature: {}",
        getName(), getCoords().x, getCoords().y, getThreat(), Utils::convertFeatureToString(feature));
}

FeatureKind NaturalFeature::getFeature() const
{
    return feature;
}

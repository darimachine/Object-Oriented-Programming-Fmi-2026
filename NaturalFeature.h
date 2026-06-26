#pragma once
#include"Landmark.h"
#include"NaturalFeature.h"

class NaturalFeature:public Landmark
{
private:
	FeatureKind feature;

public:
	NaturalFeature() = default;
	NaturalFeature(const string& name, Coordinates coords, unsigned threat, FeatureKind feature);

	string getType() const override;
	void print() const override;

	FeatureKind getFeature()const;
};


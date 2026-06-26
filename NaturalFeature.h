#pragma once
#include <iostream>
#include "Landmark.h"

enum class FeatureKind {
	Volcano,
	Forest,
	Lake,
	Bog,
	Mountain,
	Desert
};

class NaturalFeature : public Landmark {
	FeatureKind kind;
public:
	NaturalFeature(const std::string& n, Coords c1, int t, FeatureKind k);
	std::unique_ptr<Landmark> clone() const override;
	std::string getType() const override;
	void print() const override;
};
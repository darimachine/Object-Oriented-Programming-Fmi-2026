#pragma once
#include <iostream>
#include "Landmark.h"

class Settlement : public Landmark {
	int population;
public:
	Settlement(const std::string& n, Coords c1, int t, int p);
	std::unique_ptr<Landmark> clone() const override;
	std::string getType() const override;
	void print() const override;
};
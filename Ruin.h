#pragma once
#include <iostream>
#include "Landmark.h"

class Ruin : public Landmark {
	std::string civilization="";
public:
	Ruin(const std::string& n, Coords c1, int t, std::string civil);
	std::unique_ptr<Landmark> clone() const override;
	std::string getType() const override;
	void print() const override;
};
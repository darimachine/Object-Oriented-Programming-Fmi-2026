#pragma once
#include <iostream>
#include "Landmark.h"

class Dungeon : public Landmark {
	int depth;
public:
	Dungeon(const std::string& n, Coords c1, int t, int d);
	std::unique_ptr<Landmark> clone() const override;
	std::string getType() const override;
	void print() const override;
};
#pragma once
#include"Landmark.h"

class Dungeon:public Landmark
{
private:
	int depth;

public:
	Dungeon() = default;
	Dungeon(const string& name, Coordinates coords, unsigned threat, int depth);

	string getType() const override;
	void print() const override;

	int getDepth()const;
};


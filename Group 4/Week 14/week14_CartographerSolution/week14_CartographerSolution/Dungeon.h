#pragma once
#include "Landmark.h"

class Dungeon : public Landmark
{

private:
	int depth = 0;

public:

	Dungeon() = default;
	Dungeon(std::string name, const double x, const double y,
		const short threatLevel, const int depth);

	virtual std::string getType() const override;
	virtual void print() const override;
	virtual std::unique_ptr<Landmark> clone() override;

};




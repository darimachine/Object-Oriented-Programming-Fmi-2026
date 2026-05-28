#pragma once
#include "Landmark.h"

class Dungeon : public Landmark {
int depth;

public:
	Dungeon(const std::string& name, const Coords& coords, int threat, int depth);

	virtual std::string getType() const override;
	virtual void print() const override;

	std::unique_ptr<Landmark> clone() const override {
		return std::make_unique<Dungeon>(*this);
	}
};

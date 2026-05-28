#pragma once
#include "Landmark.h"

class Settlement : public Landmark {
int population;

public:
	Settlement(const std::string& name, const Coords& coords, int threat, int population);

	virtual std::string getType() const override;
	virtual void print() const;

	std::unique_ptr<Landmark> clone() const override {
		return std::make_unique<Settlement>(*this);
	}
};

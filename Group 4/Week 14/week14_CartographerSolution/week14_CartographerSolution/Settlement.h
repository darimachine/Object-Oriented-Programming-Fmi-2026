#pragma once
#include "Landmark.h"

class Settlement : public Landmark
{

private:
	int population = 0;

public:

	Settlement() = default;
	Settlement(std::string name, const double x, const double y,
		const short threatLevel, const int population);

	virtual std::string getType() const override;
	virtual void print() const override;
	virtual std::unique_ptr<Landmark> clone() override;

};


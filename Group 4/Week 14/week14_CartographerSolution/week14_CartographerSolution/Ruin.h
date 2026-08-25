#pragma once
#include "Landmark.h"

class Ruin : public Landmark
{

private:
	std::string civilization;

public:

	Ruin() = default;
	Ruin(std::string name, const double x, const double y,
		const short threatLevel, std::string civilization);

	virtual std::string getType() const override;
	virtual void print() const override;
	virtual std::unique_ptr<Landmark> clone() override;

};


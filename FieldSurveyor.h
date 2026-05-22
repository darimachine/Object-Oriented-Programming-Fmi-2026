#pragma once
#include"Cartographer.h"

class FieldSurveyor:public Cartographer
{
private:
	string region;

public:
	FieldSurveyor() = default;
	FieldSurveyor(const string& name, unsigned yearsExperience, const string& region);

	string getRole() const override;
	void print() const override;
	const string& getRegion()const;
};


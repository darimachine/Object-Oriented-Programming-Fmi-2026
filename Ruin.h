#pragma once
#include"Landmark.h"

class Ruin:public Landmark
{
private:
	string civilization;

public:
	Ruin() = default;
	Ruin(const string& name, Coordinates coords, unsigned threat, const string& civilization);

	string getType() const override;
	void print() const override;

	const string& getCivilization()const;
};


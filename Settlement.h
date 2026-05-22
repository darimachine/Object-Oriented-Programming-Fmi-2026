#pragma once
#include"Landmark.h"

class Settlement:public Landmark
{
private:
	int population;

public:
	Settlement() = default;
	Settlement(const string& name, Coordinates coords, unsigned threat, int population);


	string getType() const override;
	void print() const override;
	int getPopulation()const;
};


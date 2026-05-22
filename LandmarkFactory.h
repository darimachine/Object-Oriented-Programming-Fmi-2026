#pragma once
#include"Landmark.h"
#include<memory>

class LandmarkFactory
{
public:
	LandmarkFactory() = default;

	static unique_ptr<Landmark> create(const string& type, const string& name,
		Coordinates coords, int threat, const string& extra);
};


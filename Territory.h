#pragma once
#include"Landmark.h"
#include<memory>
#include<vector>

class Territory
{
private:
	static constexpr int MAX_DANGER_LEVEL = 10;
	static constexpr int MIN_DANGER_LEVEL = 1;

	vector<unique_ptr<Landmark>> landmarks;
	int dangerLevel;

public:
	Territory() = default;

	void addLandmark(unique_ptr<Landmark> landmark);
	unique_ptr<Landmark> removeLandmark(const string& name);
	void setDangerLevel(int dangerLevel);
	bool hasLandmark(const string& name);
	void print()const;

	int getDangerlevel()const;
};


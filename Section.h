#pragma once
#include"Exhibit.h"
#include"Guard.h"

class Section
{
private:
	string name;
	unsigned minExperience;
	vector<Exhibit> exhibits;
	Guard* guard;

public:
	Section() = default;
	Section(const string& name, int minExperience);

	bool addExhibit(const Exhibit& e);
	void assignGuard(Guard* g);
	bool hasActiveGuard()const;

	friend ostream& operator<<(ostream& os, const Section& s);

	const vector<Exhibit>& getExhibits()const;

	const string& getName()const;

	Exhibit* findExhibit(const string& animalType);
};


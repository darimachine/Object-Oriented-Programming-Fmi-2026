#pragma once
#include"Cartographer.h"

class Archivist:public Cartographer
{
private:
	string institution;

public:
	Archivist() = default;
	Archivist(const string& name, unsigned yearsExperience, const string& institution);

	string getRole() const override;
	void print() const override;
	const string& getInstitution()const;
};


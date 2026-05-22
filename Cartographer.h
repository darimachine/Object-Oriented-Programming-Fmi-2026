#pragma once
#include<string>
using namespace std;

class Cartographer
{
private:
	string name;
	unsigned yearsExperience;

public:
	Cartographer() = default;
	Cartographer(const string& name, unsigned yearsExperience);

	virtual string getRole()const = 0;
	virtual void print()const = 0;
	virtual ~Cartographer() = default;

	const string& getName()const;
	unsigned getYearsExperience()const;
};


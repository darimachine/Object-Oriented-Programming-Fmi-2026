#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Patient
{
	string egn;
	string name;
	string diagnose;
	unsigned int roomNumber;

public:
	Patient(const string& name, const string& egn, const string& diagnose, unsigned int roomNumber);

	friend ostream& operator<<(ostream& os, const Patient& p);
	auto operator<=>(const Patient& p) const = default;

	const string& getEgn() const;
	const string& getName() const;
	const string& getDiagnose() const;

	void setDiagnose(const string& newDiagnose);

};


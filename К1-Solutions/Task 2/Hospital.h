#pragma once
#include "Ward.h"
class Hospital
{
	string name;
	vector<Ward> wards;

	Hospital() = default;
public:
	Hospital(const Hospital&) = delete;
	Hospital operator=(const Hospital&) = delete;

	static Hospital& getInstance();

	void addWard(const string& name);

	void removeWard(const string& name);

	Ward& operator[](const string& name);

	vector<Ward> findPatientInWards(const string& egn) const;

	size_t totalPatients() const;

	friend ostream& operator<<(ostream& os, const Hospital& h);

	operator bool() const;
};


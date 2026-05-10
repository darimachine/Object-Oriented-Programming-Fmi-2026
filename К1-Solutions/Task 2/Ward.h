#pragma once
#include "Patient.h"
#include <algorithm>
class Ward
{
	string name;
	vector<shared_ptr<Patient>> patients;

public:
	Ward(const string& name);

	void addPatient(const shared_ptr<Patient>& p);
	void removePatient(const string& egn);
	// or optional
	Patient* findPatient(const string& egn) const;

	const vector<shared_ptr<Patient>>& getPatients() const;
	size_t patientCount() const;

	const string& getName() const;

	friend ostream& operator<<(ostream& os, const Ward& w);

	operator bool() const;

	Ward& operator()(const string& egn, const string& newDiagnose);
};


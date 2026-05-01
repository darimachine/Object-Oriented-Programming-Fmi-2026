#include "Ward.h"

Ward::Ward(const string& name): name(name)
{
}

void Ward::addPatient(const shared_ptr<Patient>& p)
{
	for (const auto& patient : patients) {
		if (patient->getEgn() == p->getEgn()) {
			return;
		}
	}

	patients.push_back(p);
}

void Ward::removePatient(const string& egn)
{
	erase_if(patients, [&egn](const shared_ptr<Patient>& p) {
		return p->getEgn() == egn;
		});

}

Patient* Ward::findPatient(const string& egn) const
{
	auto it = find_if(patients.begin(),patients.end(), [&egn](const shared_ptr<Patient>& p) {
		return p->getEgn() == egn;
		});
	if (it != patients.end()) {
		return it->get();
	}
	return nullptr;
}

const string& Ward::getName() const {
	return name;
}

const vector<shared_ptr<Patient>>& Ward::getPatients() const
{
	return patients;
}

size_t Ward::patientCount() const
{
	return patients.size();
}

ostream& operator<<(ostream& os, const Ward& w)
{
	os << w.name;
	for (int i = 0; i < w.patients.size(); i++)
	{
		os << *w.patients[i];
	}
	return os;
}
Ward::operator bool() const {
	return patients.size() > 0;
}

Ward& Ward::operator()(const string& egn, const string& newDiagnose)
{

	Patient* patient = findPatient(egn);
	if (patient != nullptr) {
		patient->setDiagnose(newDiagnose);
	}
	return *this;
}

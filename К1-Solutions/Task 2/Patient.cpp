#include "Patient.h"

Patient::Patient(const string& name, const string& egn, const string& diagnose, unsigned int roomNumber) :
	name(name), egn(egn), diagnose(diagnose), roomNumber(roomNumber)
{

}

const string& Patient::getEgn() const
{
	return egn;
}

const string& Patient::getName() const
{
	return name;
}

const string& Patient::getDiagnose() const
{
	return diagnose;
}
void Patient::setDiagnose(const string& newDiagnose)
{
	diagnose = newDiagnose;
}

ostream& operator<<(ostream& os, const Patient& p)
{
	os << "Name: " << p.name
		<< "EGN: " << p.egn
		<< "Diagnose: " << p.diagnose
		<< "Room Number: " << p.roomNumber;
	return os;
	
}

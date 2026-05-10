#include "ZooKeeper.h"

ZooKeeper::ZooKeeper(std::string n, int id, int exp)
:name(n), employeeID(id), experienceYears(exp)  {}

int ZooKeeper::getID() const
{
	return employeeID;
}

int ZooKeeper::getExperience() const
{
	return experienceYears;
}

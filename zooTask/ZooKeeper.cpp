#include "ZooKeeper.h"

ZooKeeper::ZooKeeper(const size_t _id, const std::string& _name, const size_t _experience)
	: id(_id), name(_name), experience(_experience) {}

std::string ZooKeeper::getName() const
{
	return name;
}

size_t ZooKeeper::employeeId() const
{
	return id;
}

size_t ZooKeeper::getExperience() const
{
	return experience;
}

std::ostream& operator<<(std::ostream& os, const ZooKeeper& k)
{
	os << k.employeeId() << ". " << k.getName() << " | Experience: " << k.getExperience();

	return os;
}
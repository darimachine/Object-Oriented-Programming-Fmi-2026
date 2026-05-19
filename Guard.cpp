#include "Guard.h"

unsigned Guard::nextId = 0;

Guard::Guard(const std::string& name,unsigned experience):
	employeeId(++nextId),name(name),experience(experience){}

unsigned Guard::getEmployeeId()const
{
	return employeeId;
}

const std::string& Guard::getName()const
{
	return name;
}

std::ostream& operator<<(std::ostream& os, const Guard& g)
{
	return os << g.employeeId << " " << g.name << '\n';
}
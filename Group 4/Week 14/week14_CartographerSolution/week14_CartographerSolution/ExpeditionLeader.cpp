#include "ExpeditionLeader.h"

ExpeditionLeader::ExpeditionLeader(std::string name, const unsigned yearsExperience,
	const unsigned expediotionsCount) : Cartographer(std::move(name), yearsExperience), 
	expediotionsCount(expediotionsCount)
{
}

std::string ExpeditionLeader::getRole() const
{
    return std::move(std::string("Expedition leader"));
}

void ExpeditionLeader::print() const
{
	std::cout << name << " is a " << getRole()
		<< " with " << yearsExperience << " years of experience"
		<< " who has lead " << expediotionsCount << " expeditions" << std::endl;
}

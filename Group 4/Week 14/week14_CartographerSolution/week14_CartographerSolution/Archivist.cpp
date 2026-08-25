#include "Archivist.h"

Archivist::Archivist(std::string name, const unsigned yearsExperience, std::string institution)
	: Cartographer(std::move(name), yearsExperience), institution(std::move(institution))
{
}

std::string Archivist::getRole() const
{
    return std::move(std::string("Archivist"));
}

void Archivist::print() const
{
	std::cout << name << " is a " << getRole()
		<< " with " << yearsExperience << " years of experience"
		<< " working in " << institution << " institution" << std::endl;
}

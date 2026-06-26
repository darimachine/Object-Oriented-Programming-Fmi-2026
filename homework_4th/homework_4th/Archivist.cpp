#include "Archivist.h"
#include <print>
Archivist::Archivist(const std::string& inpName, unsigned int inpYearsExp,
	const std::string& inpInstitution) : Cartographer(inpName, inpYearsExp), institution(inpInstitution)
{
}

void Archivist::printInfo() const
{
	Cartographer::printInfo();
	std::print(" institution: {}", institution);
}

 std::string Archivist::getRole() const
{
	return "Archivist";
}

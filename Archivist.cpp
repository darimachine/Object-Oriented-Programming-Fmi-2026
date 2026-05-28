#include "Archivist.h"

Archivist::Archivist(const std::string& name, int yearsExperience, const std::string& institution)
	: Cartographer(name, yearsExperience), institution(institution) {
}

std::string Archivist::getRole() const
{
	return "Archivist";
}

void Archivist::print() const
{
	Cartographer::print();
	std::cout << ", Institution: " << institution << "\n";
}



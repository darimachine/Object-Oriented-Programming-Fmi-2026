#include "Archivist.h"
#include <iostream>

Archivist::Archivist(const std::string& name, int yearsExperience, const std::string& institution) : Cartographer(name, yearsExperience), institution(institution)
{

}

std::string Archivist::getRole() const
{
	return "Archivist";
}

void Archivist::print() const
{
	std::cout << "Archivist " << name << " | " << yearsExperience << " years" << " | Institution: " << institution << std::endl;
}



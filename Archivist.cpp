#include "Archivist.h"

Archivist::Archivist(const std::string& n, unsigned y, const std::string& inst) : Cartographer(n, y), institution(inst) {}

std::string Archivist::getRole() const
{
	return "Archivist";
}

void Archivist::print() const
{
    std::cout << "Archivist: " << name << ", Exp: " << yearsExperience << " years, Institution: " << institution << "\n";
}

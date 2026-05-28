#include "Cartographer.h"

Cartographer::Cartographer(const std::string& name, int yearsExperience)
: name(name), yearsExperience(yearsExperience){}

void Cartographer::print() const
{
std::cout << "Name: " << name << ", Experience: " << yearsExperience << "years.\n";
}

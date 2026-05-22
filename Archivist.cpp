#include "Archivist.h"
#include<stdexcept>
#include<print>

Archivist::Archivist(const string& name, unsigned yearsExperience, const string& institution):
    Cartographer(name,yearsExperience)
{
    if (institution.empty())
    {
        throw invalid_argument("The institution cannot be an emtpy string.");
    }
    this->institution = institution;
}

string Archivist::getRole() const
{
    return "Archivist";
}

void Archivist::print() const
{
    println("Name: {}, Role: {}, Experience: {}, Institution: {}",
        getName(), getRole(), getYearsExperience(), institution);
}

const string& Archivist::getInstitution() const
{
    return institution;
}

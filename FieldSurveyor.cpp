#include "FieldSurveyor.h"
#include<stdexcept>
#include<print>

FieldSurveyor::FieldSurveyor(const string& name, unsigned yearsExperience, const string& region) :
    Cartographer(name, yearsExperience)
{
    if (region.empty())
    {
        throw invalid_argument("The region cannot be an empty string.");
    }
    this->region = region;
}


string FieldSurveyor::getRole() const
{
    return "FieldSurveyor";
}

void FieldSurveyor::print() const
{
    println("Name: {}, Role: {}, Experience: {}, Region: {}",
        getName(), getRole(), getYearsExperience(), region);
}

const string& FieldSurveyor::getRegion() const
{
    return region;
}

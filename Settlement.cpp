#include "Settlement.h"
#include<stdexcept>
#include<print>

Settlement::Settlement(const string& name, Coordinates coords, unsigned threat, int population):
    Landmark(name,coords,threat)
{
    if (population < 0)
    {
        throw invalid_argument("The population cannot be a negative number.");
    }
    this->population = population;
}

string Settlement::getType() const
{
    return "Settlement";
}

void Settlement::print() const
{
    println("Name: {}, Coordinates: {} {}, Threat: {}, Population: {}",
        getName(), getCoords().x, getCoords().y, getThreat(), population);
}

int Settlement::getPopulation() const
{
    return population;
}

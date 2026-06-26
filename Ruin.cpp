#include "Ruin.h"
#include<stdexcept>
#include<print>

Ruin::Ruin(const string& name, Coordinates coords, unsigned threat, const string& civilization):
    Landmark(name,coords,threat)
{
    if (civilization.empty())
    {
        throw invalid_argument("The civilization cannot be an empty string.");
    }
    this->civilization = civilization;
}

string Ruin::getType() const
{
    return string();
}

void Ruin::print() const
{
    println("Name: {}, Coordinates: {} {}, Threat: {}, Civilization: {}",
        getName(), getCoords().x, getCoords().y, getThreat(), civilization);
}

const string& Ruin::getCivilization() const
{
    return civilization;
}

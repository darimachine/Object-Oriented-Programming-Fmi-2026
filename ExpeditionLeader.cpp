#include "ExpeditionLeader.h"
#include<stdexcept>
#include<print>

ExpeditionLeader::ExpeditionLeader(const string& name, unsigned yearsExperience, int expeditionsLed):
    Cartographer(name,yearsExperience)
{
    if (expeditionsLed < 0)
    {
        throw invalid_argument("Expeditions that are led cannot be a negative number.");
    }
    this->expeditionsLed = expeditionsLed;
}

string ExpeditionLeader::getRole() const
{
    return "ExpeditionLeader";
}

void ExpeditionLeader::print() const
{
    println("Name: {}, Role: {}, Experience: {}, Number of expeditions: {}",
        getName(), getRole(), getYearsExperience(), expeditionsLed);
}

int ExpeditionLeader::getExpeditionsLed() const
{
    return expeditionsLed;
}

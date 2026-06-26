#include "Cartographer.h"

std::string Cartographer::getName() const
{
    return name;
}

std::string FieldSurveyor::getRole() const
{
    return "Field Surveyor";
}

void FieldSurveyor::print() const
{
    std::cout << "Field Surveyor: " << getName() << ", Region: " << region << "\n";
}

std::string Archivist::getRole() const
{
    return "Archivist";
}

void Archivist::print() const
{
    std::cout << "Archivist: " << getName() << ", Institution: " << institution << "\n";
}

std::string ExpeditionLeader::getRole() const
{
    return "Expedition Leader";
}

void ExpeditionLeader::print() const
{
    std::cout << "Expedition Leader: " << getName() << ", Expeditions led: " << expeditionLed << "\n";
}

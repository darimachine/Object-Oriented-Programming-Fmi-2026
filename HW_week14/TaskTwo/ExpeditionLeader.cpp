#include "ExpeditionLeader.h"
#include <iostream>

ExpeditionLeader::ExpeditionLeader(const std::string& name, int yearsExperience, int expeditionsLed) : Cartographer(name, yearsExperience), expeditionsLed(expeditionsLed)
{

}

std::string ExpeditionLeader::getRole() const
{
	return "Expedition Leader";
}

void ExpeditionLeader::print() const
{
	std::cout << "Expedition Leader " << name << " | " << yearsExperience << " years" << " | Expedition Led: " << expeditionsLed << std::endl;
}


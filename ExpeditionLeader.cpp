#include "ExpeditionLeader.h"

ExpeditionLeader::ExpeditionLeader(const std::string& name, int yearsExperience, int expeditionsLed)
	: Cartographer(name, yearsExperience), expeditionsLed(expeditionsLed) {
}

std::string ExpeditionLeader::getRole() const
{
	return "Expedition Leader";
}

void ExpeditionLeader::print() const
{
	Cartographer::print();
	std::cout << ", Expeditions Led: " << expeditionsLed << "\n";
}



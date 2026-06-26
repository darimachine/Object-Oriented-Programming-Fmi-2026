	#include "ExpeditionLeader.h"
	#include <print>
	ExpeditionLeader::ExpeditionLeader(const std::string& inpName, unsigned int inpYearsExp,
		unsigned int inpExpLed): Cartographer(inpName, inpYearsExp), expeditionsLed(inpExpLed)
	{
	}

	void ExpeditionLeader::printInfo() const
	{
		Cartographer::printInfo();
		std::print(" expeditions led : {}", expeditionsLed);
	}

	 std::string ExpeditionLeader::getRole() const
	{
		return "ExpeditionLeader";
	}

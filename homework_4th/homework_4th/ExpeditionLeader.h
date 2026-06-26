#pragma once
#include "Cartographer.h"
class ExpeditionLeader : public Cartographer
{
	private:
		unsigned int expeditionsLed;

	public:
		ExpeditionLeader(const std::string& inpName, unsigned int inpYearsExp, unsigned int inpExpLed);
		void printInfo() const override;
		 std::string getRole() const override;
};


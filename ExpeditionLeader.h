#pragma once
#include <string>
#include "Cartographer.h"

class ExpeditionLeader : public Cartographer {
	int expeditionsLed;

	public:
		ExpeditionLeader(const std::string& name, int yearsExperience, int expeditionsLed);

		std::string getRole() const override;
		void print() const override;
};

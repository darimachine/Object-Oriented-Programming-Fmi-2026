#pragma once
#include "Cartographer.h"

class FieldSurveyor :  public Cartographer {
	std::string fieldServeyor;

	public:
		FieldSurveyor(const std::string& name, int yearsExperience, const std::string& fieldServeyor);

		std::string getRole() const override;
		void print() const override;
};

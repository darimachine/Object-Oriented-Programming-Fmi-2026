#pragma once
#include "Cartographer.h"
class FieldSurveyor : public Cartographer
{
	private:
		std::string region;
		

	public:
		FieldSurveyor(const std::string& inpName, unsigned int inpYExp ,const std::string& region);
		void printInfo() const override;
		 std::string getRole() const override;
};


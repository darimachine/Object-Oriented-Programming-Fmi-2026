#pragma once
#include "Cartographer.h"
class Archivist : public Cartographer
{
	private:
		std::string institution;

	public:
		Archivist(const std::string& inpName, unsigned int inpYearsExp, const std::string& inpInstitution);
		void printInfo() const override;
		 std::string getRole() const override;
};


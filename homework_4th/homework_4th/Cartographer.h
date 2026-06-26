#pragma once
#include <string>
class Cartographer
{
	protected:
		std::string name;
		unsigned int yearsOfExperience;


	public:
		Cartographer(const std::string& inpName, unsigned int inpYearsExp);
		virtual  std::string getRole() const = 0;
		virtual void printInfo() const = 0;
		virtual ~Cartographer() = default;



};


#include "AdmissionResult.h"
#include <iostream>

AdmissionResult::AdmissionResult(bool admitted) : admitted(admitted)
{

}

void AdmissionResult::addReason(const std::string& reason)
{
	reasons.push_back(reason);
}

bool AdmissionResult::isAdmitted() const
{
	return admitted;
}

const std::vector<std::string>& AdmissionResult::getReasons() const
{
	return reasons;
}

void AdmissionResult::print() const
{
	if (admitted)
	{
		std::cout << "Student is admitted to the state exam.";
		std::cout << std::endl;
	}
	else 
	{
		std::cout << "Student is not admitted to the state exam:";
		std::cout << std::endl;
		for (const auto& reason : reasons)
		{
			std::cout << "- " << reason;
			std::cout << std::endl;
		}
	}
}


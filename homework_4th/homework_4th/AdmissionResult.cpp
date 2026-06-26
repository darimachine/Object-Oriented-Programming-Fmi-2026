#include "AdmissionResult.h"
#include <iostream>
#include <print>
AdmissionResult::AdmissionResult(bool isAdmitted, const std::vector<std::string>& inpMsg)
	:admitted(isAdmitted), messages(inpMsg)
{
}

bool AdmissionResult::getAdmitted() const
{
	return admitted;
}

const std::vector<std::string>& AdmissionResult::getMessages() const
{
	return messages;
}

void AdmissionResult::printReport() const
{
	if (admitted)
	{
		std::println("The student is admitted to the final exam");
	}
	else
	{
		for (const auto& currM : messages)
		{
			std::cout << "- " << currM << '\n';
		}
	}
}

#pragma once
#include <vector>
#include <string>
class AdmissionResult
{
	private:
		bool admitted;
		std::vector<std::string> messages;

	public:
		AdmissionResult(bool isAdmitted, const std::vector<std::string>& inpMsg);
		bool getAdmitted() const;
		const std::vector<std::string>& getMessages() const;
		void printReport() const;
};


#pragma once
#include <print>
#include <string>
#include <vector>

struct RequirementCheckResult {
	bool passed;
	std::string failureMessage;
};

class AdmissionResult {
	bool admitted;
	std::vector<std::string> failureReasons;

public:
	explicit AdmissionResult(bool, std::vector<std::string>) noexcept;
	bool isAdmitted() const;
	const std::vector<std::string>& getFailureReasons() const;
	void print() const;
};

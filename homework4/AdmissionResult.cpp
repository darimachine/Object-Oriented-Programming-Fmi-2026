#include "AdmissionResult.h"

AdmissionResult::AdmissionResult(bool a, std::vector<std::string> fr) noexcept
	: admitted(a), failureReasons(std::move(fr)) {}

bool AdmissionResult::isAdmitted() const {
	return admitted;
}

const std::vector<std::string>& AdmissionResult::getFailureReasons() const {
	return failureReasons;
}

void AdmissionResult::print() const {
	if (admitted == true)
		std::println("Student is admitted.");
	else {
		std::println("Student is not admitted for the following reasons:");
		for (const std::string& reason : failureReasons) {
			std::println(" - {}", reason);
		}
	}
}

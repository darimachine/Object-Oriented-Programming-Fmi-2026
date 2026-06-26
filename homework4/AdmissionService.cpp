#include "AdmissionService.h"

void AdmissionService::copyFrom(const AdmissionService& other) {
	for (const std::unique_ptr<AdmissionRequirement>& requirement : other.requirements)
		addRequirement(requirement->clone());
}

void AdmissionService::moveFrom(AdmissionService&& other) noexcept {
	requirements = std::move(other.requirements);
}

AdmissionService::AdmissionService(const AdmissionService& other) {
	copyFrom(other);
}

AdmissionService& AdmissionService::operator=(const AdmissionService& other) {
	if (this != &other)
		copyFrom(other);
	return *this;
}

AdmissionService::AdmissionService(AdmissionService&& other) noexcept {
	moveFrom(std::move(other));
}

AdmissionService& AdmissionService::operator=(AdmissionService&& other) noexcept {
	if (this != &other)
		moveFrom(std::move(other));
	return *this;
}

void AdmissionService::addRequirement(std::unique_ptr<AdmissionRequirement> requirement) {
	requirements.push_back(std::move(requirement));
}

AdmissionResult AdmissionService::check(const Student& s) const noexcept {
	bool admitted = true;
	std::vector<std::string> failureReasons;
	for (const std::unique_ptr<AdmissionRequirement>& requirement : requirements) {
		RequirementCheckResult result = requirement->check(s);
		if (result.passed == false) {
			failureReasons.push_back(result.failureMessage);
			admitted = false;
		}
	}
	return AdmissionResult(admitted, std::move(failureReasons));
}

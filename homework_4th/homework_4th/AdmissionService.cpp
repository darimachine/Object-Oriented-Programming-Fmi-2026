#include "AdmissionService.h"
#include "AdmissionResult.h"
void AdmissionService::free()
{
	requirements.clear();
}

void AdmissionService::copyFrom(const AdmissionService& other)
{
	for (const auto& currReq : other.requirements)
	{
		requirements.push_back(currReq->clone());
	}
}

void AdmissionService::moveFrom(AdmissionService&& other) noexcept
{
	requirements = std::move(other.requirements);
}

AdmissionService::AdmissionService(const AdmissionService& other)
{
	copyFrom(other);
}

AdmissionService& AdmissionService::operator=(const AdmissionService& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

AdmissionService::AdmissionService(AdmissionService&& other) noexcept
{
	moveFrom(std::move(other));
}

AdmissionService& AdmissionService::operator=(AdmissionService&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

AdmissionService::~AdmissionService()
{
	free();
}

void AdmissionService::addRequirement(std::unique_ptr<Requirement> addingRequirement)
{
	requirements.push_back(std::move(addingRequirement));
}

AdmissionResult AdmissionService::checkStudent(const Student& s) const
{
	std::vector<std::string> errors;
	for (const auto& currReq : requirements)
	{
		auto result = currReq->check(s);
		
		if (result)
		{
			errors.push_back(result.value());
		}
	}

	bool isAdmitted = errors.empty();

	return AdmissionResult(isAdmitted, errors);
}

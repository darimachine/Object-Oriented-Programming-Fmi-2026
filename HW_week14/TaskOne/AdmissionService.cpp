#include "AdmissionService.h"

void AdmissionService::clear() 
{
    for (auto* requirement : requirements)
    {
        delete requirement;
    }
    requirements.clear();
}

void AdmissionService::copyFrom(const AdmissionService& other)
{
    for (auto* requirement : other.requirements)
    {
        requirements.push_back(requirement->clone());
    }
}

AdmissionService::AdmissionService(const AdmissionService& other)
{
    copyFrom(other);
}

AdmissionService& AdmissionService::operator=(const AdmissionService& other)
{
    if (this != &other) 
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

AdmissionService::AdmissionService(AdmissionService&& other) noexcept : requirements(std::move(other.requirements))
{
    other.requirements.clear();
}

AdmissionService& AdmissionService::operator=(AdmissionService&& other) noexcept
{
    if (this != &other) 
    {
        clear();
        requirements = std::move(other.requirements);
        other.requirements.clear();
    }
    return *this;
}

AdmissionService::~AdmissionService()
{
    clear();
}

void AdmissionService::addRequirement(AdmissionRequirement* requirement)
{
    requirements.push_back(requirement->clone());
    delete requirement;
}

AdmissionResult AdmissionService::checkAdmission(const Student& student) const
{
    std::vector<std::string> allFailures;
    for (auto* req : requirements)
    {
        auto result = req->check(student);
        if (!result.passed)
        {
            allFailures.push_back(result.message);
        }
    }
    if (allFailures.empty())
    {
        return AdmissionResult(true);
    }
    AdmissionResult result(false);
    for (const auto& failure : allFailures)
    {
        result.addReason(failure);
    }
    return result;
}
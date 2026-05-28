#include "AdmissionService.h"
#include "AdmissionRequirement.h"
#include "Student.h"

AdmissionService::AdmissionService(const AdmissionService& other)
{
	for (const auto& req : other.requirements) {
		if (req) {
			requirements.push_back(req->clone());
		}
}
}

AdmissionService& AdmissionService::operator=(const AdmissionService& other)
{
    if (this != &other) {
        requirements.clear();
        for (const auto& req : other.requirements) {
            if (req) {
                requirements.push_back(req->clone());
            }
        }
    }
    return *this;
}

void AdmissionService::addRequirement(std::unique_ptr<AdmissionRequirement> req)
{
    if (req) {
        requirements.push_back(std::move(req));
    }
}

RequirementCheckResult AdmissionService::checkStudent(const Student& student) const
{
    RequirementCheckResult finalResult;
    for (const auto& req : requirements) {
        finalResult.merge(req->check(student));
    }
    return finalResult;
}

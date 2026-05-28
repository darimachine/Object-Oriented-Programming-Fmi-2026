#include "RequirementCheckResult.h"


RequirementCheckResult::RequirementCheckResult(bool success) : admitted(success)
{
}

void RequirementCheckResult::addReason(const std::string& reason)
{
admitted = false;
reasons.push_back(reason);
}

void RequirementCheckResult::merge(const RequirementCheckResult& other)
{
    if (!other.isAdmitted()) {
        admitted = false;
        reasons.insert(reasons.end(), other.reasons.begin(), other.reasons.end());
    }
}

bool RequirementCheckResult::isAdmitted() const
{
    return admitted;
}

const std::vector<std::string>& RequirementCheckResult::getReasons() const
{
    return reasons;
}

void RequirementCheckResult::printReport() const
{
    if (admitted) {
        std::cout<< "Student is admitted.\n";
    }
    else {
        std::cout <<"Student is not admitted.\n";
        for (const auto& reason : reasons) {
            std::cout << " * " << reason << "\n";
        }
    }
}


#pragma once
#include <string>
#include "Student.h"

struct RequirementCheckResult
{
    bool passed;
    std::string message;
};

class AdmissionRequirement 
{
public:
    virtual ~AdmissionRequirement() = default;
    virtual AdmissionRequirement* clone() const = 0;
    virtual RequirementCheckResult check(const Student& student) const = 0;
};

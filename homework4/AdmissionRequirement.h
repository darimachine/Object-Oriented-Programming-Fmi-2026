#pragma once
#include "AdmissionResult.h"
#include "Student.h"
#include <memory>

class AdmissionRequirement {
public:
	virtual ~AdmissionRequirement() = default;
	virtual std::unique_ptr<AdmissionRequirement> clone() const = 0;
	virtual RequirementCheckResult check(const Student&) const = 0;
};

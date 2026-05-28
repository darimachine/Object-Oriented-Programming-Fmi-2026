#pragma once
#include <vector>
#include <memory>
#include "RequirementCheckResult.h"

class AdmissionRequirement;
struct Student;

class AdmissionService {
private:
    std::vector<std::unique_ptr<AdmissionRequirement>> requirements;

public:
    AdmissionService() = default;
    ~AdmissionService() = default;

    AdmissionService(const AdmissionService& other);
    AdmissionService& operator=(const AdmissionService& other);
    AdmissionService(AdmissionService&& other) noexcept = default;
    AdmissionService& operator=(AdmissionService&& other) noexcept = default;

    void addRequirement(std::unique_ptr<AdmissionRequirement> req);
    RequirementCheckResult checkStudent(const Student& student) const;
};

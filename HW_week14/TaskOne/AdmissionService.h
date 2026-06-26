#pragma once
#include <vector>
#include "AdmissionRequirement.h"
#include "AdmissionResult.h"
class AdmissionService
{
    std::vector<AdmissionRequirement*> requirements;
    void clear();
    void copyFrom(const AdmissionService& other);
public:
    AdmissionService() = default;
    AdmissionService(const AdmissionService& other);
    AdmissionService& operator=(const AdmissionService& other);
    AdmissionService(AdmissionService&& other) noexcept;
    AdmissionService& operator=(AdmissionService&& other) noexcept;
    ~AdmissionService();
    void addRequirement(AdmissionRequirement* requirement);
    AdmissionResult checkAdmission(const Student& student) const;
};


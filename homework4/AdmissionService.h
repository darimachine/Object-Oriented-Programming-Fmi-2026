#pragma once
#include "AdmissionRequirement.h"
#include <memory>
#include <string>
#include <vector>

class AdmissionService {
	std::vector<std::unique_ptr<AdmissionRequirement>> requirements;

	void copyFrom(const AdmissionService&);
	void moveFrom(AdmissionService&&) noexcept;

public:
	AdmissionService() = default;
	AdmissionService(const AdmissionService&);
	AdmissionService& operator=(const AdmissionService&);
	AdmissionService(AdmissionService&&) noexcept;
	AdmissionService& operator=(AdmissionService&&) noexcept;
	~AdmissionService() = default;
	void addRequirement(std::unique_ptr<AdmissionRequirement>);
	AdmissionResult check(const Student&) const noexcept;
};

#pragma once
#include "Requirement.h"
#include "Student.h"
#include <memory>
#include <string>
#include "AdmissionResult.h"
class AdmissionService
{
	private:
		std::vector<std::unique_ptr<Requirement>> requirements;

		void free();
		void copyFrom(const AdmissionService& other);
		void moveFrom(AdmissionService&& other) noexcept;
	public:
		AdmissionService() = default;
		AdmissionService(const AdmissionService& other);
		AdmissionService& operator=(const AdmissionService& other);
		AdmissionService(AdmissionService&& other) noexcept;
		AdmissionService& operator=(AdmissionService&& other) noexcept;
		~AdmissionService();

		void addRequirement(std::unique_ptr<Requirement> addingRequirement);
		AdmissionResult checkStudent(const Student& s) const;
};


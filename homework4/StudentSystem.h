#pragma once
#include "AdmissionService.h"
#include "Exceptions.h"
#include <string>
#include <vector>

class StudentSystem {
	std::vector<Student> students;
	AdmissionService admissionService;

public:
	explicit StudentSystem(const AdmissionService&);
	explicit StudentSystem(AdmissionService&&) noexcept;
	void addStudent(const Student&);
	void removeStudent(const std::string&);
	Student& operator[](const std::string&);
	const std::vector<Student>& getStudents() const noexcept;
	AdmissionService& getAdmissionService() noexcept;
	AdmissionResult checkAdmission(const Student&);
};

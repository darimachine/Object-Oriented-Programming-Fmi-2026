#pragma once
#include <vector>
#include "Student.h"
#include "AdmissionService.h"
class StudentSystem
{
	private:
		std::vector<Student> students;
		AdmissionService admissionService;

	public:
		StudentSystem(const AdmissionService& inpAdService);
		void addStudent(const Student& addingStudent);
		void removeStudent(const std::string& removingFacNum);
		const Student& operator[](const std::string& facNum) const;

		const std::vector<Student>& getStudent() const;
		AdmissionResult checkAdmission(const std::string& facNum) const ;
		AdmissionService& getService();
		
};


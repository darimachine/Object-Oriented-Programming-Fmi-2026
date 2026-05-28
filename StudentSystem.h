#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "AdmissionService.h"
#include "AdmissionRequirement.h"

class StudentSystem {
private:
    std::vector<Student> students;
    AdmissionService admissionService;

public:
    StudentSystem() = default;
    explicit StudentSystem(const AdmissionService& service);

    AdmissionService& getAdmissionService();

    void addStudent(const Student& student);
    void removeStudent(const std::string& fn);

    Student& operator[](const std::string& fn);
    RequirementCheckResult checkStudentAdmission(const std::string& fn);
};
#pragma once
#include <vector>
#include "Student.h"
#include "AdmissionService.h"
class StudentSystem
{
private:
    std::vector<Student> students;
    AdmissionService admissionService;
    int findIndex(const std::string& facultyNumber) const;
public:
    explicit StudentSystem(const AdmissionService& service);
    void addStudent(const Student& student);
    void removeStudent(const std::string& facultyNumber);
    const Student& operator[](const std::string& facultyNumber) const;
    const std::vector<Student>& getStudents() const;
    AdmissionResult checkAdmission(const std::string& facultyNumber) const;
};


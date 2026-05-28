#include <algorithm>
#include "StudentSystem.h"
#include "Exceptions.h"

StudentSystem::StudentSystem(const AdmissionService& service) : admissionService(service)
{
}

AdmissionService& StudentSystem::getAdmissionService()
{
    return admissionService;
}

void StudentSystem::addStudent(const Student& student)
{
    for (const auto& s : students) {
        if (s.fn == student.fn) throw StudentAlreadyExistsException(student.fn);
    }
    students.push_back(student);
}

void StudentSystem::removeStudent(const std::string& fn)
{
    auto it = std::remove_if(students.begin(), students.end(),
        [&fn](const Student& s) { return s.fn == fn; });

    if (it == students.end()) throw StudentNotFoundException(fn);
    students.erase(it, students.end());
}

Student& StudentSystem::operator[](const std::string& fn)
{
    for (auto& s : students) {
        if (s.fn == fn) return s;
    }
    throw StudentNotFoundException(fn);
}

RequirementCheckResult StudentSystem::checkStudentAdmission(const std::string& fn)
{
    for (const auto& s : students) {
        if (s.fn == fn) {
            return admissionService.checkStudent(s);
        }
    }
    throw StudentNotFoundException(fn);
}

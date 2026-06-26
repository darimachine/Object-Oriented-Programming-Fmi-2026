#include "StudentSystem.h"
#include "StudentAlreadyExistsException.h"
#include "StudentNotFoundException.h"

int StudentSystem::findIndex(const std::string& facultyNumber) const
{
    for (int i = 0; i < (int)students.size(); i++)
    {
        if (students[i].getFacultyNumber() == facultyNumber)
        {
            return i;
        }
    }
    return -1;
}

StudentSystem::StudentSystem(const AdmissionService& service) : admissionService(service)
{

}

void StudentSystem::addStudent(const Student& student)
{
    if (findIndex(student.getFacultyNumber()) != -1)
    {
        throw StudentAlreadyExistsException(student.getFacultyNumber());
    }
    students.push_back(student);
}

void StudentSystem::removeStudent(const std::string& facultyNumber)
{
    int index = findIndex(facultyNumber);
    if (index == -1)
    {
        throw StudentNotFoundException(facultyNumber);
    }
    students.erase(students.begin() + index);
}

const Student& StudentSystem::operator[](const std::string& facultyNumber) const
{
    int index = findIndex(facultyNumber);
    if (index == -1)
    {
        throw StudentNotFoundException(facultyNumber);
    }
    return students[index];
}

const std::vector<Student>& StudentSystem::getStudents() const
{
    return students;
}

AdmissionResult StudentSystem::checkAdmission(const std::string& facultyNumber) const
{
    int idx = findIndex(facultyNumber);
    if (idx == -1)
    {
        throw StudentNotFoundException(facultyNumber);
    }
    return admissionService.checkAdmission(students[idx]);
}
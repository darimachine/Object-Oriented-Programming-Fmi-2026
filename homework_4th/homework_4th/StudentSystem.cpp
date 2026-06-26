#include "StudentSystem.h"
#include <algorithm>
#include <stdexcept>
StudentSystem::StudentSystem(const AdmissionService& inpAdService) : admissionService(inpAdService)
{
}

void StudentSystem::addStudent(const Student& addingStudent)
{
	students.push_back(addingStudent);
}

void StudentSystem::removeStudent(const std::string& removingFacNum)
{
		students.erase(
			std::remove_if(students.begin(), students.end(), [&removingFacNum](const Student& currS)
		{return removingFacNum == currS.getFacNum(); }));
}

const Student& StudentSystem::operator[](const std::string& facNum) const
{
	auto it = std::find_if(students.begin(), students.end(), [&facNum](const Student& currS)
		{return facNum == currS.getFacNum(); });

	if (it != students.end())
	{
		return *it;
	}
}

const std::vector<Student>& StudentSystem::getStudent() const
{
	return students;
}

AdmissionResult StudentSystem::checkAdmission(const std::string& facNum) const
{
	const Student& targetStudent = (*this)[facNum];
	return admissionService.checkStudent(targetStudent);
}

AdmissionService& StudentSystem::getService() 
{
	return admissionService;
}

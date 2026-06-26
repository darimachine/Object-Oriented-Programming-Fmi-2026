#include "StudentSystem.h"

StudentSystem::StudentSystem(const AdmissionService& as) : admissionService(as) {}

StudentSystem::StudentSystem(AdmissionService&& as) noexcept : admissionService(std::move(as)) {}

void StudentSystem::addStudent(const Student& newStudent) {
	for (const Student& student : students) {
		if (newStudent.getFacultyNumber() == student.getFacultyNumber())
			throw StudentAlreadyExistsException(newStudent.getFacultyNumber());
	}
	students.push_back(newStudent);
}

void StudentSystem::removeStudent(const std::string& facultyNumber) {
	(*this)[facultyNumber];
	students.erase(std::find_if(students.begin(), students.end(),
		[&facultyNumber](const Student& s) {return facultyNumber == s.getFacultyNumber(); }));
}

Student& StudentSystem::operator[](const std::string& facultyNumber) {
	auto it = std::find_if(students.begin(), students.end(),
		[&facultyNumber](const Student& s) { return facultyNumber == s.getFacultyNumber(); });
	if (it == students.end())
		throw StudentNotFoundException(facultyNumber);
	return *it;
}

const std::vector<Student>& StudentSystem::getStudents() const noexcept {
	return students;
}

AdmissionService& StudentSystem::getAdmissionService() noexcept {
	return admissionService;
}

AdmissionResult StudentSystem::checkAdmission(const Student& s) {
	return admissionService.check(s);
}

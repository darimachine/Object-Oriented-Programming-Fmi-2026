#include "Exceptions.h"

StudentAlreadyExistsException::StudentAlreadyExistsException(const std::string& facultyNumber)
	: message("Student with faculty number " + facultyNumber + " already exists") {}

const char* StudentAlreadyExistsException::what() const noexcept {
	return message.c_str();
}

StudentNotFoundException::StudentNotFoundException(const std::string& facultyNumber)
	: message("Student with faculty number " + facultyNumber + " not found.") {}

const char* StudentNotFoundException::what() const noexcept {
	return message.c_str();
}

InvalidRequirementConfigException::InvalidRequirementConfigException(const std::string& m)
	: message(m) {}

const char* InvalidRequirementConfigException::what() const noexcept {
	return message.c_str();
}

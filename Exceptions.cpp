#include "Exceptions.h"

StudentAlreadyExistsException::StudentAlreadyExistsException(const std::string& fn)
	: std::runtime_error("Student with FN '" + fn + "' already exists.")  {}

StudentNotFoundException::StudentNotFoundException(const std::string& fn)
	: std::runtime_error("Student with FN '" + fn + "' was not found.") {}

InvalidRequirementException::InvalidRequirementException(const std::string& msg)
	: std::runtime_error("Invalid requirement configuration: " + msg)  {}

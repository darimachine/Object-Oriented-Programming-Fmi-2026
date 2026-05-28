#pragma once
#include <stdexcept>
#include <string>

class StudentAlreadyExistsException : public std::runtime_error {
public:
explicit StudentAlreadyExistsException(const std::string& fn);
};

class StudentNotFoundException : public std::runtime_error {
	public:
		explicit StudentNotFoundException(const std::string& fn);
};

class InvalidRequirementException : public std::runtime_error {
public:
	explicit InvalidRequirementException(const std::string& msg);
};

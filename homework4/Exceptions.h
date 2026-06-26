#pragma once
#include <exception>
#include <string>

class StudentAlreadyExistsException : public std::exception {
	std::string message;

public:
	explicit StudentAlreadyExistsException(const std::string&);
	const char* what() const noexcept override;
};

class StudentNotFoundException : public std::exception {
	std::string message;

public:
	explicit StudentNotFoundException(const std::string&);
	const char* what() const noexcept override;
};

class InvalidRequirementConfigException : public std::exception {
	std::string message;

public:
	explicit InvalidRequirementConfigException(const std::string&);
	const char* what() const noexcept override;
};

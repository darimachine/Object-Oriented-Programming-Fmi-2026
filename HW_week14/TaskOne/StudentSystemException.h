#pragma once
#include <stdexcept>

class StudentSystemException : public std::exception
{
    const std::string message;
public:
    explicit StudentSystemException(const std::string& message);
    const char* what() const noexcept override;
};
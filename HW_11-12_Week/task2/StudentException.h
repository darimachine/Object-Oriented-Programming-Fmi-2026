#pragma once
#include <stdexcept>
#include <string>
class StudentException : public std::invalid_argument 
{
public:
    explicit StudentException(const std::string& message) : std::invalid_argument(message) 
    {
    
    }
};


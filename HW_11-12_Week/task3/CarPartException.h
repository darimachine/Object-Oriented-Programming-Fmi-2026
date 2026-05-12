#pragma once
#include <stdexcept>
#include <string>

class CarPartException : public std::invalid_argument
{
public:
    explicit CarPartException(const std::string& message) : std::invalid_argument(message) 
    {

    }
};
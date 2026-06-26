#pragma once
#include <stdexcept>
#include <string>

class ZooException : public std::runtime_error 
{
public:
    explicit ZooException(const std::string& message) : std::runtime_error(message)
    {

    }
};
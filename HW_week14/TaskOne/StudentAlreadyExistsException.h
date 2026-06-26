#pragma once
#include "StudentSystemException.h"

class StudentAlreadyExistsException : public StudentSystemException 
{
public:
    explicit StudentAlreadyExistsException(const std::string& facultyNumber);
};


#pragma once
#include "StudentSystemException.h"

class StudentNotFoundException : public StudentSystemException
{
public:
    explicit StudentNotFoundException(const std::string& facultyNumber);
};

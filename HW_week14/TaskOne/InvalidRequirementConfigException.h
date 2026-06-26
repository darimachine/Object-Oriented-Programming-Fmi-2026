#pragma once
#include "StudentSystemException.h"

class InvalidRequirementConfigException : public StudentSystemException 
{
public:
    explicit InvalidRequirementConfigException(const std::string& reason);
};
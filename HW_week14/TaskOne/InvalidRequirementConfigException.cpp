#include "InvalidRequirementConfigException.h"

InvalidRequirementConfigException::InvalidRequirementConfigException(const std::string& reason)
    : StudentSystemException("Invalid requirement configuration: " + reason) 
{

}

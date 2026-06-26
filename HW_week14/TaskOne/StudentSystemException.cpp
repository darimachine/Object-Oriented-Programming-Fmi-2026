#include "StudentSystemException.h"

StudentSystemException::StudentSystemException(const std::string& message): message(message)
{

}

const char* StudentSystemException::what() const noexcept
{
	return "Student error";
}



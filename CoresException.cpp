#include "CoresException.h"

CoresException::CoresException(const std::string& message):MyException(message){}

const char* CoresException::what()const noexcept
{
	return getMessage().c_str();
}
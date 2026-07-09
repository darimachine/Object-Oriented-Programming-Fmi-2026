#include "MemoryException.h"

MemoryException::MemoryException(const std::string& message):MyException(message){}

const char* MemoryException::what()const noexcept
{
	return getMessage().c_str();
}
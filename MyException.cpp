#include "MyException.h"

MyException::MyException(const std::string& message):message(message){}

const std::string& MyException::getMessage()const
{
	return message;
}
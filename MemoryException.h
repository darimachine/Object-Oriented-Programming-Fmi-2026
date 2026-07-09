#pragma once
#include"MyException.h"

class MemoryException:public MyException
{
public:
	MemoryException(const std::string& message);

	const char* what()const noexcept override;
};


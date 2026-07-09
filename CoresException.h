#pragma once
#include"MyException.h"

class CoresException:public MyException
{
public:
	CoresException(const std::string& message);
	const char* what()const noexcept override;
};


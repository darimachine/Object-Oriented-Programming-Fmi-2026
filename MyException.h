#pragma once
#include<stdexcept>
#include<string>

class MyException:public std::exception
{
private:
	std::string message;

public:
	MyException(const std::string& message);

	const std::string& getMessage()const;

	virtual const char* what()const noexcept = 0;
	virtual ~MyException() = default;
};


#include "Util.h"
#include <print>
using std::println;

/**
* returns false (0) on valid error code and true (1) on an invalid error code.

*/
bool Util::CheckErrorCode(const ErrorCode& code)
{
	if (code==ErrorCode::OK)
	{
		return false;
	}
	switch (code)
	{
	case ErrorCode::NotFound:
		println("Not found error");
		break;
	case ErrorCode::Duplicate:
		println("Duplicate error. Entity that you tried to operate already exists.");
		break;
	case ErrorCode::InvalidInput:
		println("Invalid input. Default value set for variable.");
		break;
	case ErrorCode::DepartmentFull:
		println("Department full. The employee was not added.");
		break;
	case ErrorCode::CompanyDepartmentsFull:
		println("The number of departments is full. Current department not added.");
		break;
	default:
		break;
	}

    return true;

}

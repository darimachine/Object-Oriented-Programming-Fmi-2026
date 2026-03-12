#pragma once
#pragma warning(disable : 4996)

#include <string>
enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    DepartmentFull,
    CompanyDepartmentsFull
};
class Util
{
    Util() = delete;
public:
    static bool CheckErrorCode(const ErrorCode& code);
};


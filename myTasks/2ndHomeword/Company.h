#pragma once
#include  "Department.h"

constexpr  int MAX_DEPARTMENTS = 10;

class Company
{
private:
    Department departments[MAX_DEPARTMENTS];
    unsigned int countOfDepartments = 0;
    Company();

public:
    static Company& getInstance();
    Company(const Company&) = delete;
    Company& operator=(const Company&) = delete;
    Company(Company&&) noexcept = delete;
    Company& operator=(Company&&) = delete;


    ErrorCode addDepartment(const char* );
    ErrorCode removeDepartment(const char* );
    ErrorCode addEmployeeToDepartment(const char* ,const Employee& );
    ErrorCode removeEmployeeFromDeaprtment(const char* ,unsigned int);

    friend std::ostream& operator<<(std::ostream&, const Company&);
    operator bool() const;
    Department* operator[](const char*);

};
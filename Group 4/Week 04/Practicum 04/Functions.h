#pragma once
enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput
};

class Employee;
class Department;

void swapEmployees(Employee employees[15], int count, int index);
void swapDepartments(Department departments[10], int count, int index);
int find(Department departments[10], const char* name, const unsigned count);
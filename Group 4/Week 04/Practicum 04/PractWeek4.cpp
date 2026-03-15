#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"
#include "Department.h"
#include "Company.h"
#include "Functions.h"
#include <print>
unsigned Employee::id = 0;

const int MAX_NUMBER_EMPLOYEES = 15;

void swapEmployees(Employee employees[15], int count, int index) {
    for (int i = index; i < count - 1; i++) {
        std::swap(employees[i], employees[i + 1]);
    }
}
void swapDepartments(Department departments[10], int count, int index) {
    for (int i = index; i < count - 1; i++) {
        std::swap(departments[i], departments[i + 1]);
    }
}
int find(Department departments[10], const char* name,const unsigned count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(departments[i].getName(), name) == 0)return i;
    }
    return -1;
}


int main()
{
    std::cout << "Hello World!\n";
}

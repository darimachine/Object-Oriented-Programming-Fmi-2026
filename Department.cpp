#include <iostream>
#include "Department.h"
#include <cstring>


Department::Department(const char* name): countOfEmployees(0) {
	strcpy_s(this->name, MAX_LEN+1, name);
}

ErrorCode Department::addEmployee(const Employee& employee) {
	if (countOfEmployees >= MAX_SIZE) {
		return ErrorCode::InvalidInput;
	}

    for (size_t i = 0; i < countOfEmployees; i++)
    {
        if (employees[i].getId() == employee.getId())
            return ErrorCode::Duplicate;
    }

	employees[countOfEmployees++] = employee;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
    bool found = false;
    size_t index = 0;


    for (size_t i = 0; i < countOfEmployees; i++)
    {
        if (employees[i].getId() == id)
        {
            index = i;
            found = true;
            break;
        }
    }

    if (!found)
        return ErrorCode::NotFound;

    for (size_t i = index; i < countOfEmployees - 1; i++)
    {
        employees[i] = employees[i + 1];
    }

    countOfEmployees--;
    return ErrorCode::OK;
}

unsigned Department::getMaxEmployees() {
	return MAX_SIZE;
}

const char* Department::getName() const {
	return name;
}


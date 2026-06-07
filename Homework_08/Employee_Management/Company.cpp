#define _CRT_SECURE_NO_WARNINGS

#include "Company.h"

Company::Company() : countOfDepartments(0) 
{

}

Company& Company::getInstance()
{
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* name)
{
    if (countOfDepartments >= MAX_DEPARTMENTS) {
        return ErrorCode::Full;
	}

    if (name == nullptr || name[0] == '\0') {
        return ErrorCode::InvalidInput;
	}

    for (unsigned i = 0; i < countOfDepartments; ++i) {
        if (strcmp(departments[i].name, name) == 0) {
            return ErrorCode::Duplicate;
        }
    }

    departments[countOfDepartments++] = Department(name, 8);
	return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
    if (name == nullptr || name[0] == '\0') {
        return ErrorCode::InvalidInput;
    }

    for (unsigned i = 0; i < countOfDepartments; ++i) {
        if (strcmp(departments[i].name, name) == 0) {
            for (unsigned j = i; j < countOfDepartments - 1; ++j) {
                departments[j] = std::move(departments[j + 1]);
            }
            --countOfDepartments;
            return ErrorCode::OK;
        }
	}

	return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
    if (departmentName == nullptr || departmentName[0] == '\0' || &employee == nullptr) {
        return ErrorCode::InvalidInput;
    }

    for (unsigned i = 0; i < countOfDepartments; ++i) {
        if (strcmp(departments[i].name, departmentName) == 0) {
           departments[i].addEmployee(employee);
		   return ErrorCode::OK;
        }
	}

	return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
    if (departmentName == nullptr || departmentName[0] == '\0') {
        return ErrorCode::InvalidInput;
	}

    for (unsigned i = 0; i < countOfDepartments; ++i) {

        if (strcmp(departments[i].name, departmentName) == 0) {
			return departments[i].removeEmployee(id);
        }        
	}

	return ErrorCode::NotFound;
}

Department* Company::operator[](const char* name)
{
    for (size_t i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(name, departments[i].name) == 0) {
			return &departments[i];
        }
    }

	return nullptr;
}

const Department* Company::operator[](const char* name) const
{
    for (size_t i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(name, departments[i].name) == 0) {
            return &departments[i];
        }
    }

    return nullptr; 
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
	os << "Company with " << company.countOfDepartments << " departments:" << std::endl;
    for (unsigned i = 0; i < company.countOfDepartments; ++i) {
        os << company.departments[i] << std::endl;
	}

	return os;  
}

Company::operator bool() const
{
    if (countOfDepartments > 0) {
        for (size_t i = 0; i < countOfDepartments; i++)
        {
            if (departments[i].countOfEmployees > 0) {
				return true;
            }
        }
	}

	return false;
}

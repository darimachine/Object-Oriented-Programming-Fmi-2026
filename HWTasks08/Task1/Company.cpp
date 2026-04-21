#include "Company.h"

//Department Company::departments[10];
//size_t Company::countOfDepartments;

auto Company::_findByName(const char* name) -> size_t
{
	for (auto i = size_t{ 0 }; i < countOfDepartments; ++i)
	{
		if (!strcmp(departments[i].m_name, name))
		{
			return i;
		}
	}
	return countOfDepartments;
}

auto Company::instance() -> Company&
{
	static auto instance = Company{};
	return instance;
}

auto Company::addDepartment(const char* name) -> ErrorCode
{
	if (countOfDepartments == 9)
		return ErrorCode::Full;

	if (_findByName(name) != countOfDepartments)
		return ErrorCode::Duplicate;

	departments[countOfDepartments++] = std::move(Department{ name, 0 });
	return ErrorCode::OK;
}

auto Company::removeDepartment(const char* name) -> ErrorCode
{
	if (countOfDepartments == 9)
		return ErrorCode::Full;

	auto index = _findByName(name);
	if (index == countOfDepartments)
		return ErrorCode::NotFound;

	for (auto i = index; i < countOfDepartments - 1; ++i)
	{
		std::swap(departments[i], departments[i + 1]);
	}
	--countOfDepartments;
	return ErrorCode::OK;
}

auto Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee) -> ErrorCode
{
	auto index = _findByName(departmentName);
	if (index == countOfDepartments)
		return ErrorCode::NotFound;

	return departments[index].addEmployee(employee);
}

auto Company::removeEmployeeFromDepartment(const char* departmentName, size_t id) -> ErrorCode
{
	auto index = _findByName(departmentName);
	if (index == countOfDepartments)
		return ErrorCode::NotFound;

	return departments[index].removeEmployee(id);
}

Company::operator bool() const
{
	if (countOfDepartments <= 0)
		return false;

	for (auto i = size_t{ 0 }; i < countOfDepartments; i++)
	{
		if (departments[i]) return true;
	}

	return false;
}

auto Company::operator[](const char* name) -> Department*
{
	auto index = _findByName(name);
	if (index == countOfDepartments)
		return nullptr;

	return &departments[index];
}

auto operator<<(std::ostream& os, const Company& company) -> std::ostream&
{
	os << "Departments: \n\r";
	for (auto i = size_t{ 0 }; i < company.countOfDepartments; ++i)
	{
		os << company.departments[i] << "\n\r";
	}
	return os;
}


#include "Department.h"

auto Department::_resize(size_t capacity) -> Employee*
{
	if (capacity == m_capacity)
		return m_employees;

	auto* newEmployees = new Employee[capacity]{ };
	m_countOfEmployees = std::min(capacity, m_countOfEmployees);
	for (auto i = size_t{ 0 }; i < m_countOfEmployees; ++i)
	{
		newEmployees[i] = std::move(m_employees[i]);
	}
	m_capacity = capacity;
	delete[] m_employees;
	m_employees = newEmployees;

	return m_employees;
}

auto Department::_findById(size_t id) const -> size_t
{
	for (auto i = size_t{ 0 }; i < m_countOfEmployees; ++i)
	{
		if (m_employees[i].m_id == id)
		{
			return i;
		}
	}
	return m_countOfEmployees;
}

auto Department::_averageSalary() const -> double
{
	if (!m_countOfEmployees)
		return 0.0;

	auto sum = double{ 0.0 };
	for (auto i = size_t{ 0 }; i < m_countOfEmployees; ++i)
	{
		sum += m_employees[i].getSalary();
	}

	return sum / m_countOfEmployees;
}

auto Department::_free() -> void
{
	if (m_name != nullptr)
	{
		delete[] m_name;
		m_name = nullptr;
	}
	if (m_employees != nullptr)
	{
		delete[] m_employees;
		m_employees = nullptr;
	}
	m_countOfEmployees = 0;
	m_capacity = 0;
}

auto Department::_copy(const Department& from) -> void
{
	auto nameLength = strnlen_s(from.m_name, ULONG_MAX);
	m_name = new char[nameLength + 1];
	strcpy_s(m_name, nameLength + 1, from.m_name);

	m_capacity = from.m_capacity;
	m_countOfEmployees = from.m_countOfEmployees;
	if (!m_capacity)
		return;

	m_employees = new Employee[m_capacity]{ };
	for (auto i = size_t{ 0 }; i < m_countOfEmployees; ++i)
	{
		m_employees[i] = from.m_employees[i];
	}
}

auto Department::_move(Department&& from) -> void
{
	m_name = from.m_name;
	m_capacity = from.m_capacity;
	m_countOfEmployees = from.m_countOfEmployees;
	m_employees = from.m_employees;

	from.m_name = nullptr;
	from.m_capacity = 0;
	from.m_countOfEmployees = 0;
	from.m_employees = nullptr;
}

Department::Department() noexcept
	: m_name(nullptr), m_employees(nullptr), m_countOfEmployees(0), m_capacity(0)
{

}

Department::Department(const char* name, size_t capacity)
	: m_countOfEmployees(0), m_capacity(capacity)
{
	auto nameLength = strnlen_s(name, ULONG_MAX);
	m_name = new char[(nameLength) ? (nameLength + 1) : (1)];
	(nameLength) ? strcpy_s(m_name, nameLength + 1, name) : strcpy_s(m_name, 1, "");

	m_employees = nullptr;
	if (capacity > 0)
		m_employees = new Employee[capacity]{ };
}

Department::~Department()
{
	_free();
}

Department::Department(const Department& other)
{
	_copy(other);
}

auto Department::operator=(const Department& other) -> Department&
{
	_free();
	_copy(other);
	return *this;
}

Department::Department(Department&& other) noexcept
{
	_move(std::move(other));
}

auto Department::operator=(Department&& other) noexcept -> Department&
{
	_free();
	_move(std::move(other));
	return *this;
}

auto Department::addEmployee(const Employee& employee) -> ErrorCode
{
	if (_findById(employee.m_id) != m_countOfEmployees)
		return ErrorCode::Duplicate;

	if (m_countOfEmployees == m_capacity)
	{
		if (m_capacity * 2 < m_capacity)
			return ErrorCode::Full;

		_resize(std::max(1ull, m_capacity * 2));
	}

	m_employees[m_countOfEmployees++] = employee;
	return ErrorCode::OK;
}

auto Department::addEmployee(Employee&& employee) -> ErrorCode
{
	if (_findById(employee.m_id) != m_countOfEmployees)
		return ErrorCode::Duplicate;

	if (m_countOfEmployees == m_capacity)
	{
		if (m_capacity * 2 < m_capacity)
			return ErrorCode::Full;

		_resize(std::max(1ull, m_capacity * 2));
	}

	m_employees[m_countOfEmployees++] = std::move(employee);
	return ErrorCode::OK;
}

auto Department::removeEmployee(size_t id) -> ErrorCode
{
	auto index = _findById(id);
	if (index == m_countOfEmployees)
		return ErrorCode::NotFound;

	for (auto i = index; i < m_countOfEmployees - 1; ++i)
	{
		std::swap(m_employees[i], m_employees[i + 1]);
	}
	--m_countOfEmployees;
	return ErrorCode::OK;
}

auto Department::operator==(const Department& other) const -> bool
{
	return ((*this) <=> other) == std::partial_ordering::equivalent;
}

auto Department::operator[](size_t index) const -> const Employee&
{
	return m_employees[index];
}

auto Department::operator[](size_t index) -> Employee&
{
	return m_employees[index];
}

Department::operator bool() const
{
	return m_countOfEmployees > 0;
}

auto Department::operator()(unsigned int increasePercent) -> Department&
{
	auto p = 1.0 + static_cast<double>(increasePercent) / 100.0;
	for (auto i = size_t{ 0 }; i < m_countOfEmployees; ++i)
	{
		m_employees[i].m_salary *= p;
	}

	return *this;
}

auto Department::operator<=>(const Department& other) const -> std::partial_ordering
{
	return (this->m_countOfEmployees == other.m_countOfEmployees) ? (this->_averageSalary() <=> other._averageSalary()) : (this->m_countOfEmployees <=> other.m_countOfEmployees);
}

auto operator<<(std::ostream& os, const Department& department) -> std::ostream&
{
	os << "Department: " << department.m_name << ", " << department.m_countOfEmployees << ", Employees:\n\r";
	for (auto i = size_t{ 0 }; i < department.m_countOfEmployees; ++i)
	{
		os << department.m_employees[i] << "\n\r";
	}
	return os;
}

#include "Department.h"

Employee Department::dummyEmployee;

void Department::copyFrom(const Department& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    countOfEmployees = other.countOfEmployees;
    capacity = other.capacity;

    employees = new Employee[capacity];
    for (unsigned i = 0; i < countOfEmployees; i++)
    {
        employees[i] = other.employees[i];
    }
}

void Department::moveFrom(Department&& other) noexcept
{
    name = other.name;
    employees = other.employees;
    countOfEmployees = other.countOfEmployees;
    capacity = other.capacity;
    other.name = new char[1];
    other.name[0] = '\0';
    other.employees = new Employee[Department::CAP_SIZE];
    other.capacity = Department::CAP_SIZE;
    other.countOfEmployees = 0;
}

void Department::free()
{
    delete[] name;
    delete[] employees;
}

void Department::resize()
{
    unsigned newCapacity = capacity * 2;
    Employee* newArray = new Employee[newCapacity];
    for (unsigned i = 0; i < countOfEmployees; i++)
    {
        newArray[i] = employees[i];
    }
    delete[] employees;
    employees = newArray;
    capacity = newCapacity;
}

Department::Department() : countOfEmployees(0), capacity(Department::CAP_SIZE)
{
    name = new char[1];
    name[0] = '\0';

    employees = new Employee[capacity];
}

Department::Department(const char* name, unsigned initialCapacity)
{
    if (!name)
    {
        name = "";
    }

    countOfEmployees = 0;

    if (initialCapacity > 0)
    {
        capacity = initialCapacity;
    }
    else
    {
        capacity = 4;
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    employees = new Employee[capacity];
}

Department::Department(const Department& other)
{
    copyFrom(other);
}

Department& Department::operator=(const Department& other) 
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Department::Department(Department&& other) noexcept : name(other.name), employees(other.employees),
countOfEmployees(other.countOfEmployees), capacity(other.capacity)
{
    moveFrom(std::move(other));
}

Department& Department::operator=(Department&& other) noexcept
{
    if(this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Department::~Department() 
{
    free();
}

const char* Department::getName() const 
{
    return name; 
}

unsigned Department::getCount() const 
{
    return countOfEmployees; 
}

double Department::averageSalary() const
{
    if (countOfEmployees == 0)
    {
        return 0.0;
    }
    double total = 0.0;
    for (unsigned i = 0; i < countOfEmployees; i++)
    {
        total += employees[i].getSalary();
    }
    return (total / countOfEmployees);
}

ErrorCode Department::addEmployee(const Employee& employee)
{
    for (unsigned i = 0; i < countOfEmployees; i++)
    {
        if (employees[i].getId() == employee.getId())
        {
            return ErrorCode::Duplicate;
        }
    }
    if (countOfEmployees == capacity)
    {
        resize();
    }
    employees[countOfEmployees++] = employee;
    return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
    for (unsigned i = 0; i < countOfEmployees; i++) 
    {
        if (employees[i].getId() == id) 
        {
            for (unsigned j = i; j < countOfEmployees - 1; j++)
            {
                employees[j] = employees[j + 1];
            }
            countOfEmployees--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

Employee& Department::operator[](unsigned index)
{
    if (index >= countOfEmployees)
    {
        return dummyEmployee;
    }
    return employees[index];
}

const Employee& Department::operator[](unsigned index) const
{
    if (index >= countOfEmployees)
    {
        return dummyEmployee;
    }
    return employees[index];
}
Department& Department::operator()(double percent) 
{
    const int NEGATIVE_PERCENT = -100;
    if (percent <= NEGATIVE_PERCENT)
    {
        return *this;
    }

    for (unsigned i = 0; i < countOfEmployees; i++) 
    {
        employees[i].updateSalary(employees[i].getSalary() * percent / 100.0);
    }
    return *this;
}

std::partial_ordering Department::operator<=>(const Department& other) const
{
    if (countOfEmployees != other.countOfEmployees)
    {
        return countOfEmployees <=> other.countOfEmployees;
    }
    return averageSalary() <=> other.averageSalary();
}

bool Department::operator==(const Department& other) const 
{
    return ((countOfEmployees == other.countOfEmployees) && (averageSalary() == other.averageSalary()));
}

Department::operator bool() const 
{ 
    return (countOfEmployees > 0); 
}

std::ostream& operator<<(std::ostream& os, const Department& d) 
{
    os << "Department: " << d.name << " " << d.countOfEmployees << " employees" << std::endl;
    for (unsigned i = 0; i < d.countOfEmployees; i++)
    {
        os << d.employees[i] << std::endl;
    }
    return os;
}
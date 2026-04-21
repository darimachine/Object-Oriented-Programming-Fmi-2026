#include "Employee.h"
#pragma warning(disable: 4996)
unsigned int Employee::id = 0;


const char Employee::_DEFAULT_NAME[MAX_STRING_LEN]= "DefaultName";
const char Employee::_DEFAULT_POSITION[MAX_STRING_LEN]= "DefaultPosition";
const double Employee::_DEFAULT_SALARY=0;



std::ostream& operator<<(std::ostream& os, const Employee& e)
{
    os << "Employee Id: " << e.id << ";\nEmployee name: " << e.name << ";\nEmployee position: " << e.position << ";\nEmployee salary: " << e.getSalary()<<"\n";
    return os;
}

std::istream& operator>>(std::istream& is, Employee& e)
{
    char buffer[128];
    is >> buffer;
    delete[] e.name;
    e.setName(buffer);
    buffer[0] = '\0';
    is >> buffer;
    delete[] e.position;
    e.setPosition(buffer);
    buffer[0] = '\0';
    double bufferDouble = 0.0;
    is >> bufferDouble;
    e.updateSalary(bufferDouble);
    e.employeeId = e.id++;

    return is;
}

unsigned int Employee::getId()
{
    return employeeId;
}

Employee::Employee()
{
    employeeId = 0;
    strcpy(name, _DEFAULT_NAME);
    strcpy(position, _DEFAULT_POSITION);
    salary = _DEFAULT_SALARY;

}

Employee::Employee(const char _name[MAX_STRING_LEN], const char _position[MAX_STRING_LEN], const double _salary)
{
    employeeId = id++;
    strcpy(name, _name);
    strcpy(position, _position);
    salary = _salary;
}

const char* Employee::getName() const
{
    return name;
}

void Employee::setName(const char* newName)
{
    std::strncpy(this->name, newName, MAX_STRING_LEN - 1);

    this->name[MAX_STRING_LEN - 1] = '\0';

}

const char* Employee::getPosition() const
{
    return position;
}

void Employee::setPosition(const char* newPosition)
{
    std::strncpy(this->position, newPosition, MAX_STRING_LEN - 1);

    this->position[MAX_STRING_LEN - 1] = '\0';
}

double Employee::getSalary() const
{
    return salary;
}

ErrorCode Employee::updateSalary(double amount)
{

    if (amount<0)
    {
        return ErrorCode::InvalidInput;
    }
    salary = amount;
    return ErrorCode::OK;
}

unsigned int Employee::lastEmployeeid()
{
    return id-1;
}

Employee& Employee::operator++()
{
    this->salary *=1.1;
    return *this;

}

Employee Employee::operator++(int)
{
    Employee temp(*this);
    this->salary *= 1.1;
    return temp;
}

bool Employee::operator==(const Employee& other) const
{
    return this->id==other.id;
}


std::strong_ordering Employee::operator<=>(const Employee& other) const {
    if (salary < other.salary) return std::strong_ordering::less;
    if (salary > other.salary) return std::strong_ordering::greater;
    return employeeId <=> other.employeeId;
}

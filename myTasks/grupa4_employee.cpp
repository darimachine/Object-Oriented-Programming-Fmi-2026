#include  <iostream>
#include <print>
#include  <cstring>

#include "grupa4_employee.h"

unsigned int grupa4_employee::Lastid =0;

grupa4_employee::grupa4_employee()
{
  //  std::cout<<"default constructor is called"<<'\n';
    name[0] = '\0';
    position[0] = '\0';
    salary = MIN_SALARY;
    ID = ++Lastid;

}

grupa4_employee::grupa4_employee(const char*inpName, const char*inpPosition, double inpSalary)
{
    setSalary(inpSalary);
    setName(inpName);
    setPosition(inpPosition);
    ID = ++Lastid;

}

void grupa4_employee::setSalary(double inpSalary)
{
    if (inpSalary < MIN_SALARY)
    {
        std::cout<<"The inputed salary is invalid";
        salary = 0;
        return;
    }
    salary = inpSalary;
}

void grupa4_employee::setName(const char* inpName)
{
    if (!inpName)
    {
        return;
    }

    int inpNameLen = strlen(inpName);
    if (inpNameLen >= MAX_LEN_NAME)
    {
        std::cout<<"The inputed name len is too long"<<'\n';
        return;
    }

    strcpy(name, inpName);
    name[inpNameLen] = '\0';
}

void grupa4_employee::setPosition(const char *inpPosition)
{
    if (!inpPosition)
        return;

    int inpPositionLen = strlen(inpPosition);
    if (inpPositionLen >=MAX_LEN_NAME)
    {
        std::cout<<"The inputed position len is too long"<<'\n';
        return;
    }
    strcpy(position, inpPosition);
    position[inpPositionLen] = '\0';
}

unsigned int grupa4_employee::getLastID()
{
    return Lastid;
}

double grupa4_employee::getSalary() const
{
    return  salary;
}

ErrorCode grupa4_employee::updateSalary(double amount)
{
    if (amount <MIN_SALARY)
    {
        return  ErrorCode::InvalidInput;
    }
    salary = amount;
    return  ErrorCode::OK;
}

void grupa4_employee::printInfoEmployee() const
{
    std::cout<<"ID: "<<ID<<" name: "<<name<<" position: "<<position<<"salary: "<<salary<<'\n';
}

const char * grupa4_employee::printExitCode(ErrorCode currErrorCode) const
{
    switch (currErrorCode)
    {
        case ErrorCode::OK:
            return  "OK";
        case ErrorCode::InvalidInput:
            return  "Invalid input";
        case ErrorCode::Duplicate:
            return  "Duplicate";
        case ErrorCode::NotFound:
            return "Not found";
    }

}

const char *grupa4_employee::getEmployeeName() const
{
    return  name ? name: "";
}

Department::Department() : countOfEmployees(0)
{
    std::cout<<"Default constructor is called."<<'\n';
    name[0] = '\0';
}

const char *grupa4_employee::getPosition() const
{
    return position;
}

void Department::setDepName(const char *DepName)
{
    int DepNameLen = strlen(DepName);
    if (DepNameLen >= MAX_LEN_NAME)
        return;
    strcpy(name, DepName);
}

const char *Department::getDepName() const
{
    return name;
}

Department::Department(const char* inpName): countOfEmployees(0)
{
    if (!inpName)
        return;

    setDepName(inpName);
}

ErrorCode Department::addEmployee(const grupa4_employee &EmployeeToJoin)
{
    if(countOfEmployees < MAX_EMPLOYEES)
    {
        const char* employeeJoiningName = EmployeeToJoin.getEmployeeName();
        for (int i =0; i <countOfEmployees; i++)
        {
            const char* currEmployeeName = Employees[i].getEmployeeName();
            if (strcmp(currEmployeeName,employeeJoiningName)==0)
            {
                std::cout<<"The employee is already in the team"<<'\n';
                return ErrorCode::Duplicate;
            }
        }
        Employees[countOfEmployees++] = EmployeeToJoin;
        return ErrorCode::OK;
    }
    else
    {
        std::cout<<"A new employee can not be added to the team. The team is full!"<<'\n';
        return ErrorCode::FullTeam;
    }
}

ErrorCode Department::removeEmployee(unsigned int id)
{
    if (id > countOfEmployees)
    {
        std::println("The team does not have that many members");
        return ErrorCode::InvalidInput;
    }
    else
    {
        unsigned int idx = id -1;
        for (unsigned int i = idx; i<countOfEmployees - 1; i++)
        {
            Employees[i].setName(Employees[i + 1].getEmployeeName());
            //std::println("Employee name: {}", Employees[i].getEmployeeName());
            Employees[i].setPosition(Employees[i+1].getPosition());
            //std::println("Employee position: {}", Employees[i].getPosition());
            Employees[i].setSalary(Employees[i+1].getSalary());
            //std::println("Emplopyee salary: {}", Employees[i].getSalary());

        }
        countOfEmployees --;
    }
    return ErrorCode::OK;
}

unsigned Department::getMaxEmployees()
{
    return MAX_EMPLOYEES;
}

Company::Company(): countOfDepartments(0)
{}

Company &Company::getInstance()
{
    static Company instance;
    return  instance;
}

ErrorCode Company::addDepartment(const char *DepName)
{
    if (!DepName)
        return  ErrorCode::InvalidInput;

    if (countOfDepartments == MAX_DEPARTMENTS)
        return ErrorCode::FullDeparmentCont;

    for (int i = 0; i<countOfDepartments; i++)
    {
        if (strcmp(departments[countOfDepartments].getDepName(), DepName) == 0)
        {
            return  ErrorCode::Duplicate;
        }
    }
    departments[countOfDepartments].setDepName(DepName);
    countOfDepartments++;
    std::println("The department: {} is successfully added to the compay", DepName);
    return  ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char *DepName)
{
    if (!DepName)
        return ErrorCode::InvalidInput;

    for (int i=0; i <countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), DepName) == 0)
        {
            departments[i] = departments[countOfDepartments - 1];
            countOfDepartments--;
            std::println("This department is successfully removed");
            return  ErrorCode::OK;
        }
    }

    std::println("This department is not in the company");
    return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char *departmentName, const grupa4_employee &employee)
{
    if (!departmentName)
        return ErrorCode::InvalidInput;

    for (int i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), departmentName) == 0)
        {
            departments[i].addEmployee(employee);
            std::println("The employee is successfully added to: {} department", departments[i].getDepName());
            return  ErrorCode::OK;
        }
    }
    std::println("The: {} department is not in the company", departmentName);
    return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDeaprtment(const char *departmentName, unsigned int id)
{
    if (!departmentName)
        return ErrorCode::InvalidInput;

    for (int i=0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), departmentName) == 0)
        {
            departments[i].removeEmployee(id);
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

int main()
{
    grupa4_employee first("Ivan Ivanov", "Senior Software Engineer", 5000);
    grupa4_employee second("Mariya Petrova", "Junior Developer", 3200);
    grupa4_employee third("Georgi Dimitrov", "QA Automation", 4800);

    Department IT("IT");
    //std::cout<<int(myCompany.addEmployee(first));
    //std::cout<<int(myCompany.addEmployee(second));
    IT.addEmployee(first);
    IT.addEmployee(second);
    IT.addEmployee(third);
  // std::cout<<int(myCompany.removeEmployee(2));
    std::cout<<IT.getMaxEmployees();

    grupa4_employee fOther("Elena Vasileva", "HR Manager", 5500);
    grupa4_employee sOther("Stefan Todorov", "Tech Recruiter", 3000);
    Department HR("HR");
    HR.addEmployee(fOther);
    HR.addEmployee(sOther);

    grupa4_employee emp("Alex Nikolov", "Sales Director", 6100);
    grupa4_employee emp2("Daniel Kolev", "Marketing Specialist", 3500);
    Department Sales("Sales");
    Sales.addEmployee(emp);
    Sales.addEmployee(emp2);

    Company& myCompany =Company::getInstance();
    myCompany.addDepartment("IT");
    myCompany.addDepartment("HR");
    myCompany.addDepartment("Sales");

    myCompany.addEmployeeToDepartment("IT", first);
    myCompany.addEmployeeToDepartment("IT", second);
    myCompany.addEmployeeToDepartment("IT", third);

    myCompany.addEmployeeToDepartment("HR", fOther);
    myCompany.addEmployeeToDepartment("HR", sOther);
    myCompany.addEmployeeToDepartment("Sales",emp);
    myCompany.addEmployeeToDepartment("Sales", emp2);
    return 0;
}
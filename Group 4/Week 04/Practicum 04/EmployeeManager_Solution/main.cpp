#include <iostream>

#include "Employee.h"
#include "Department.h"
#include "Company.h"


int main() {

    Company::getCompany().addDepartment("Research");
    Company::getCompany().addDepartment("Human Resources");
    Company::getCompany().addDepartment("Shipment");
    Company::getCompany().addDepartment("Marketing");
    Company::getCompany().addDepartment("Production");

    Employee employeeResearch1("Jake", "Head Scientist", 5000);
    Employee employeeResearch2("Elena", "Senior Researcher", 4200);
    Employee employeeResearch3("Mark", "Junior Data Analyst", 3100);
    Employee employeeResearch4("Sofia", "Lab Technician", 2800);

    Employee employeeHR1("Karen", "HR Manager", 4500);
    Employee employeeHR2("David", "Recruiter", 3800);
    Employee employeeHR3("Lisa", "Benefits Coordinator", 3600);

    Employee employeeShipment1("Mike", "Logistics Manager", 4100);
    Employee employeeShipment2("Anna", "Dispatcher", 3400);
    Employee employeeShipment3("Pedro", "Warehouse Supervisor", 3700);
    Employee employeeShipment4("Isabelle", "Packer", 2500);
    Employee employeeShipment5("Boris", "Delivery Driver", 3000);

    Employee employeeMarketing1("Sarah", "Marketing Director", 4800);
    Employee employeeMarketing2("Lucas", "Digital Marketing Specialist", 4000);
    Employee employeeMarketing3("Chloe", "Graphic Designer", 3900);
    Employee employeeMarketing4("Oliver", "Copywriter", 3700);

    Employee employeeProduction1("Hassan", "Production Manager", 4300);
    Employee employeeProduction2("Yumi", "Quality Control Inspector", 3600);
    Employee employeeProduction3("Anton", "Machinist", 3300);
    Employee employeeProduction4("Maria", "Assembly Line Worker", 2900);

    Company::getCompany().addEmployeeToDepartment("Research", employeeResearch1);
    Company::getCompany().addEmployeeToDepartment("Research", employeeResearch2);
    Company::getCompany().addEmployeeToDepartment("Research", employeeResearch3);
    Company::getCompany().addEmployeeToDepartment("Research", employeeResearch4);

    Company::getCompany().addEmployeeToDepartment("Human Resources", employeeHR1);
    Company::getCompany().addEmployeeToDepartment("Human Resources", employeeHR2);
    Company::getCompany().addEmployeeToDepartment("Human Resources", employeeHR3);

    Company::getCompany().addEmployeeToDepartment("Shipment", employeeShipment1);
    Company::getCompany().addEmployeeToDepartment("Shipment", employeeShipment2);
    Company::getCompany().addEmployeeToDepartment("Shipment", employeeShipment3);
    Company::getCompany().addEmployeeToDepartment("Shipment", employeeShipment4);
    Company::getCompany().addEmployeeToDepartment("Shipment", employeeShipment5);

    Company::getCompany().addEmployeeToDepartment("Marketing", employeeMarketing1);
    Company::getCompany().addEmployeeToDepartment("Marketing", employeeMarketing2);
    Company::getCompany().addEmployeeToDepartment("Marketing", employeeMarketing3);
    Company::getCompany().addEmployeeToDepartment("Marketing", employeeMarketing4);

    Company::getCompany().addEmployeeToDepartment("Production", employeeProduction1);
    Company::getCompany().addEmployeeToDepartment("Production", employeeProduction2);
    Company::getCompany().addEmployeeToDepartment("Production", employeeProduction3);
    Company::getCompany().addEmployeeToDepartment("Production", employeeProduction4);

    std::cout << "########################################" << std::endl;
    std::cout << "----- Initial company information: -----" << std::endl;
    std::cout << "########################################" << std::endl << std::endl;

    Company::getCompany().printCompanyInfo();

    Company::getCompany().removeEmployeeFromDepartment("Research", 1);

    Company::getCompany().removeDepartment("Marketing");

    std::cout << "##################################################" << std::endl;
    std::cout << "----- Company information after some changes -----" << std::endl;
    std::cout << "##################################################" << std::endl << std::endl;

    Company::getCompany().printCompanyInfo();


    return 0;
}
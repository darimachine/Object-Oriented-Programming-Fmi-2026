#include <iostream>

#include "Student.h"



int main() {

	Student roberto("Roberto", 85234);

	std::cout << roberto.getFn() << std::endl;
	std::cout << roberto.getName();

	{
		Student temp = roberto;
	} //temp got destroyed, but roberto should live ...

	std::cout << roberto.getName();

	Student* arr = new Student[10]; //ops I want 10 students!!!
	//chose names on your own ...


	return 0;
}
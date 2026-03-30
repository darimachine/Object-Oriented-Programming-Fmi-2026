#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
using namespace std;


int main() {
 
	double* grades = new double[3];
	grades[0] = 2.32;
	grades[1] = 3.50;
	grades[2] = 6.00;

	Student s1("Ivan", 2341, grades, 3);
	Student s2 = s1;

	Student** arr = new Student * [5] {nullptr};
	char name[] = "Test1";
	for (int i = 0; i < 5; i++)
	{
		arr[i] = new Student(name, i + 1000, grades, 3);
		name[4]++;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i]->getName()<<"  "<< arr[i]->getFn()<<endl;

	}
	for (int i = 0; i < 5; i++)
	{
		delete arr[i];
	}

	delete[] grades;
	delete[] arr;
}
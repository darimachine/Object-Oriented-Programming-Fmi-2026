
#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

int main() {
	while (true) {
		int* grades = new int[3];
		grades[0] = 2;
		grades[1] = 3;
		grades[2] = 4;
		Student s("Bob", 1234, grades, 3);
		cout << s.getName() << endl;
		s.setName(s.getName());
		cout << s.getName() << endl;

		Student** students = new Student * [5];
		char name[] = "Test1";
		for (int i = 0; i < 5; i++) {
			students[i] = new Student(name, i + 1, grades, 3);
			name[4]++;
		}
		for (int i = 0; i < 5; i++) {
			cout << students[i]->getName() << endl;
		}
		for (int i = 0; i < 5; i++) {
			delete students[i];
		}
		delete[] students;
		delete[] grades;
	}
	
}


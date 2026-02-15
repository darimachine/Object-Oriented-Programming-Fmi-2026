#include <iostream>
using std::cout;
using std::endl;

struct Person {
	char name[10];
	int age;
};

struct Student {
	char name[10];
	int age;
	int grade;
};

union MyUnion
{
	/*
		MyUnion can store either a Person or a Student, similar to how a base class pointer can point to different derived class objects in classical polymorphism.
	*/
	Person person;
	Student student;
};

int main()
{
	Person person = { "Georgi",12 };
	Student student = { "Ivan", 14,6 };

	/* 
		You first assign uni.person = person;, then overwrite it with uni.student = student;.
		The union allows interpreting the memory differently depending on which struct you're accessing, much like how a virtual function call behaves differently depending on the actual derived object.
	*/
	MyUnion uni;
	uni.person = person;
	uni.student = student;
	cout << uni.student.name<<endl;
	cout << uni.person.name << endl;
}

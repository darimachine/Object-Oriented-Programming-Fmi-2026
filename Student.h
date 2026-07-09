#pragma once
#include<string>
#include<fstream>
using namespace std;

class Student
{
private:
	static unsigned nextId;
	string name;
	unsigned id;
	string course;

public:
	Student() = default;
	Student(const string& name, const string& course);
	unsigned getId()const;
	friend std::ostream& operator<<(std::ostream& os, const Student& s);
};


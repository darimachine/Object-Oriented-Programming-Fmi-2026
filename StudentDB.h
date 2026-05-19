#pragma once
#include"Student.h"
#include<vector>
#include<iostream>

class StudentDB
{
protected:
	vector<Student> students;

public:
	bool add(const Student& student);
	bool remove(unsigned id);
	const Student& find(unsigned id)const;
	void display()const;
};


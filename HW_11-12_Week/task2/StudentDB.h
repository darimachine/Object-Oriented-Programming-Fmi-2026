#pragma once
#include <vector>
#include "Student.h"
class StudentDB
{
protected:
	std::vector<Student> students;
public:
    virtual void add(const Student& s);
    virtual void remove(unsigned fn);
    Student* find(unsigned fn);
    virtual void display() const;
    virtual ~StudentDB() = default;
};


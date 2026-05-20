#include "Student.h"

Student::Student(std::string _name, unsigned _number, unsigned int _course)
{
	if (name != _name) {
		name = _name;
	}
	number = std::make_unique<unsigned>(_number);
	if (_course <= 6) {
		course = _course;
	}

}

Student::Student()
{
}

unsigned Student::getNumber() const
{
	return *number;
}

void const Student::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Faculty number: " << number << std::endl;
	std::cout << "Course: " << course << std::endl;
}

std::string Student::getName() const
{
	return name;
}

unsigned int Student::getCourse() const
{
	return course;
}

StudentBD::StudentBD():Student()
{
}

void StudentBD::add(std::string _name, unsigned _number, unsigned int _course)
{
	auto ptr = std::make_unique<Student>(_name, _number, _course);
	stdtBD.push_back(std::move(ptr));
}

void StudentBD::remove(std::unique_ptr<unsigned> _number)
{
	for (int i = 0;i < stdtBD.size(); i++) {
		if (stdtBD[i]->getNumber() == *_number) {
			stdtBD.erase(stdtBD.begin()+i);
			break;
		}
	}
}

bool StudentBD::find(std::unique_ptr<unsigned> _number)
{
	for (int i = 0;i < stdtBD.size();i++) {
		if (stdtBD[i]->getNumber() == *_number) {
			return 1;
		}
	}
	return 0;
}

void StudentBD::display() const
{
	for (int i = 0;i < stdtBD.size();i++) {
		stdtBD[i]->print();
	}
}

void SortedStudentBD::sortBy(std::string str)
{
	if (str == "Name") {
		bool flag = 1;
		for (int i = 0;i < stdtBD.size();i++) {
			for (int j = i;j < stdtBD.size();j++) {
				if (stdtBD[i]->getName() > stdtBD[j]->getName()) {
					std::swap(stdtBD[i], stdtBD[j]);
				}
			}
		}
	}
	if (str == "Number") {
		bool flag = 1;
		for (int i = 0;i < stdtBD.size();i++) {
			for (int j = i;j < stdtBD.size();j++) {
				if (stdtBD[i]->getNumber() > stdtBD[j]->getNumber()) {
					std::swap(stdtBD[i], stdtBD[j]);
				}
			}
		}
	}if (str == "Course") {
		bool flag = 1;
		for (int i = 0;i < stdtBD.size();i++) {
			for (int j = i;j < stdtBD.size();j++) {
				if (stdtBD[i]->getCourse() > stdtBD[j]->getCourse()) {
					std::swap(stdtBD[i], stdtBD[j]);
				}
			}
		}
	}
}

void FilteredStudentBD::filter(auto c)
{
	stdtBD.erase(stdtBD.begin(), stdtBD.end(), c);
}

void FilteredStudentBD::limit(int N)
{
	if (N < stdtBD.size()) {
		stdtBD.resize(N);
	}
}

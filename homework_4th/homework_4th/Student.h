#pragma once
#include "Discipline.h"
#include <vector>
#include <string>
class Student
{
	private:
		std::string facNumber;
		std::string name;
		std::vector<Discipline> takenDiscpilines;
		unsigned int totalCredits;
		double averagGrade;
		unsigned int choosenDiscCredits;

	public:
		Student(const std::string& inpFacNum, const std::string& inpName,
			 std::vector<Discipline> inpTakenDiscpines, 
			unsigned int inpTotalCredits, double inpAvgGrage, unsigned int inpCDC);

		unsigned int getTotalCredits() const;
		double getAverageGrade() const;
		const std::vector<Discipline>& getTakenDisciplines() const;
		unsigned int getChoosenDiscCredits() const;
		const std::string& getFacNum() const;
		

};


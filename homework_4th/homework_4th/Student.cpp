#include "Student.h"

Student::Student(const std::string& inpFacNum, const std::string& inpName, 
	 std::vector<Discipline> inpTakenDiscpines, 
	unsigned int inpTotalCredits, double inpAvgGrage, unsigned int inpCDC) : facNumber(inpFacNum), name(inpName),
	takenDiscpilines(std::move(inpTakenDiscpines)), totalCredits(inpTotalCredits), averagGrade(inpAvgGrage),
	choosenDiscCredits(inpCDC)
{
}

unsigned int Student::getTotalCredits() const
{
	return totalCredits;
}

double Student::getAverageGrade() const
{
	return averagGrade;
}

const std::vector<Discipline>& Student::getTakenDisciplines() const
{
	return takenDiscpilines;
}

unsigned int Student::getChoosenDiscCredits() const
{
	return choosenDiscCredits;
}

const std::string& Student::getFacNum() const
{
	return facNumber;
}

#include "StudentDB.h"
#include <iostream>
#include <stdexcept>
#include <print>
void StudentDB::add(const Student& joiningStudent)
{
	if (find(joiningStudent.getPersonalID()))
	{
		std::println("The student is already in the list");
		return;
	}
	currentStudents.push_back(joiningStudent);
}

void StudentDB::remove(unsigned inpID)
{
	if (!find(inpID))
	{
		std::println("The student is not in the list, so he can not be removed");
		return;
	}
	
	std::erase_if(currentStudents, 
		[inpID](Student& currentStudent) {return currentStudent.getPersonalID() == inpID; });
}

bool StudentDB::find(unsigned inpID) const
{
	auto findIt = std::find_if(currentStudents.begin(), currentStudents.end(),
		[inpID](const Student& currStudent)
		{return  currStudent.getPersonalID() == inpID; });

	return findIt != currentStudents.end();

}

void StudentDB::display() const
{
	std::println("Current students info: ");

	for (const auto& currS : currentStudents)
	{
		currS.displayStudentInfo();
	}
}

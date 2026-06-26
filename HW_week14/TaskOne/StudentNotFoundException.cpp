#include "StudentNotFoundException.h"
#include <string>

StudentNotFoundException::StudentNotFoundException(const std::string& facultyNumber) 
	: StudentSystemException(std::string("Student with faculty number ") + facultyNumber + " was not found.")
{

}

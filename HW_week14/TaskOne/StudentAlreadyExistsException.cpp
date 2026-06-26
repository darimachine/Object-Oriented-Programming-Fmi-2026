#include "StudentAlreadyExistsException.h"

StudentAlreadyExistsException::StudentAlreadyExistsException(const std::string& facultyNumber)
    : StudentSystemException("Student with faculty number " + facultyNumber + " already exists.")
{

}
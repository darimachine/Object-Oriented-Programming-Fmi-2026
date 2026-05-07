#include <iostream>
#include "FilterStudentDB.h"
#include <vector>
#include <print>
#include <stdexcept>

int main()
{
	FilterStudentDB currDataBase;
	std::vector<std::pair<std::string, int>> inpData = {
		{"Ivan", 5},
		{"Mariya", 2},
		{"Petar", 1},
		{"Georgi", -1},
		{ "Dimitar", 1 },
		{"Aleks", 3},
		{"Krasimir", 1}
	};

	for (const auto& data : inpData)
	{
		try
		{
			Student newStudent(data.first, data.second);
			currDataBase.add(newStudent);
			std::println("Successfully added");
		}

		catch (const std::exception& e)
		{
			std::cerr << "Error!" << e.what() << '\n';
		}
	}

	currDataBase.display();
	//currDataBase.remove(2);
	//currDataBase.display();

	//currDataBase.filter(FilterCriterias::byCourse, 1);
	currDataBase.limit(2);
	currDataBase.display();
	return 0;
}
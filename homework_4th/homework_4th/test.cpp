//#include <iostream>
//#include <vector>
//#include <string>
//#include <stdexcept>
//
//#include "Discipline.h"
//#include "Category.h"
//#include "Student.h"
//#include "RequirementFactory.h"
//#include "AdmissionService.h"
//#include "StudentSystem.h"
//
//int main()
//{
//	try
//	{
//		Discipline math("Maths", 15, true, Category::Maths);
//		Discipline oop("OOP", 15, true, Category::Programming);
//		Discipline math2("Apploed maths", 12, false, Category::ApliedMaths);
//		
//		std::vector<Discipline> first = { math, oop };
//		Student firstStudent("MI20000", "Ivan Ivanov", first, 220, 5.5, 50);
//		std::vector<Discipline> second = {math2};
//		Student secondStudent("MI5000", "Miro georgiev", second, 120, 3.3, 23);
//
//		AdmissionService baseService;
//		baseService.addRequirement(RequirementFactory::createMinimumCredits(200));
//		baseService.addRequirement(RequirementFactory::createMinimumAverageGrade(4.00));
//
//		StudentSystem mySystem(baseService);
//		AdmissionService copiedService = baseService;
//		copiedService.addRequirement(RequirementFactory::createMinimumAverageGrade(5.00));
//		mySystem.addStudent(firstStudent);
//		mySystem.addStudent(secondStudent);
//
//		AdmissionResult result = mySystem.checkAdmission("MI20000");
//		result.printReport();
//		std::cout << '\n';
//
//		AdmissionResult result2 = mySystem.checkAdmission("MI5000");
//		result2.printReport();
//
//		try
//		{
//			mySystem.addStudent(firstStudent);
//		}
//		catch (const std::exception& e)
//		{
//			std::cout << e.what() << '\n';
//		}
//	}
//
//	return 0;
//}
#include"Utils.h"

bool isEqualSalary(double first, double second)
{
	return std::abs(first - second) < 1e-9;
}
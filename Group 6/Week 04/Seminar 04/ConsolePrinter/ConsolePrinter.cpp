#include "ConsolePrinter.h"

ConsolePrinter::ConsolePrinter()
{
	censor = [](char ch) {return false; };
}

ConsolePrinter::ConsolePrinter(Predicate func) : censor(func)
{

}

void ConsolePrinter::print(const char* str) const
{
	while (*str) {
		if (censor(*str)) {
			std::cout << "*";
		}
		else {
			std::cout << *str;
		}
		str++;
	}
}

void ConsolePrinter::println(const char* str) const
{
	print(str);
	cout << endl;
}

Predicate Predicates::combineOr(const Predicate& a, const Predicate& b)
{
	return [=](char ch) { return a(ch) || b(ch); };
}


Predicate Predicates::negate(const Predicate& a)
{
	return [=](char ch) { return !a(ch); };
}

#pragma once
#include <iostream>
#include <functional>
using namespace std;

using Predicate = std::function<bool(char)>;

namespace Predicates {
	Predicate combineOr(const Predicate& a, const Predicate& b);
	Predicate negate(const Predicate& a);
}

class ConsolePrinter
{
	Predicate censor;

public:
	ConsolePrinter();
	explicit ConsolePrinter(Predicate func);

	void print(const char* str) const;
	void println(const char* str) const;
};


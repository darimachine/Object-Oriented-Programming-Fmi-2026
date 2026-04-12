#pragma once
#include "ConsolePrinter.h"
using namespace std;

class NumberWrapper
{
	int n;
	const ConsolePrinter* cp;

public:
	NumberWrapper(int n, const ConsolePrinter& cp);

	void print() const;
	void println() const;

	void setPrinter(const ConsolePrinter& cp);

};


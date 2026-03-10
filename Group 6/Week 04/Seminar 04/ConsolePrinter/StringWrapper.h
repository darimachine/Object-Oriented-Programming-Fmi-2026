#pragma once
#include "ConsolePrinter.h"
class StringWrapper
{
	const char* str; // ne pritejavame pammeta a prosto referirame kum neq
	const ConsolePrinter* cp;

public:
	StringWrapper(const char* data, const ConsolePrinter& cp);

	void print() const;
	void println() const;

	void setConsolePrinter(const ConsolePrinter& cp);
};


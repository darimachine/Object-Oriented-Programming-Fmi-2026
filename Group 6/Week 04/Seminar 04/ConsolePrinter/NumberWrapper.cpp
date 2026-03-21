#define _CRT_SECURE_NO_WARNINGS
#include "NumberWrapper.h"


NumberWrapper::NumberWrapper(int n, const ConsolePrinter& cp) : n(n),cp(&cp)
{
}

void NumberWrapper::print() const
{
	char buffer[1024];
	_itoa(n, buffer, 10);
	cp->print(buffer);
}

void NumberWrapper::println() const
{
	char buffer[1024];
	_itoa(n, buffer, 10);
	cp->println(buffer);
}

void NumberWrapper::setPrinter(const ConsolePrinter& cp)
{
	this->cp = &cp;
}

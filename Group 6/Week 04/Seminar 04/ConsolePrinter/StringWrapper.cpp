#include "StringWrapper.h"

StringWrapper::StringWrapper(const char* data, const ConsolePrinter& cp): str(data), cp(&cp) {

}

void StringWrapper::print() const {

	cp->print(str);
}
void StringWrapper::println() const {

	cp->println(str);
}

void StringWrapper::setConsolePrinter(const ConsolePrinter& cp)
{
	this->cp = &cp;
}

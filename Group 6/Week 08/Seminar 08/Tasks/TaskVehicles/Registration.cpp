#define _CRT_SECURE_NO_WARNINGS
#include "Registration.h"
Registration::Registration(const char* registrationNumber) {
	bool isLongNumber = true;
	unsigned length = strlen(registrationNumber);
	unsigned digitsIndex = 2;
	if (registrationNumber[0] >= '0' && registrationNumber[0] <= '9') throw "Wrong Number";
	for (int i = 0; i < 2; i++) {
		if (registrationNumber[i] >= '0' && registrationNumber[i] <= '9') {
			isLongNumber = false;
			break;
		}
		city[i] = registrationNumber[i];
	}
	if (isLongNumber) {
		city[2] = '\0';
	}
	else {
		city[1] = '\0';
		digitsIndex = 1;
	}
	int d = 0;
	for (int i = digitsIndex; i < digitsIndex + 4; i++) {
		if (registrationNumber[i] < '0' || registrationNumber[i]>'9') throw "Wrong Number";
		digits[d++] = registrationNumber[i];
	}
	digits[4] = '\0';
	d = 0;
	for (int i = digitsIndex + 4; i < length; i++) {
		if (registrationNumber[i] >= '0' && registrationNumber[i] <= '9') throw "Wrong Number";
		symbols[d++] = registrationNumber[i];
	}
	symbols[2] = '\0';
}
std::ostream& operator<<(std::ostream& os, const Registration& r) {
	os << r.city << r.digits << r.symbols;
	return os;
}
const char* Registration::getNumber() const {
	strcpy(number, city);
	strcat(number, digits);
	strcat(number, symbols);

	return number;
}

auto Registration::operator<=>(const Registration& other) const {
	int result = std::strcmp(getNumber(), other.getNumber());

	if (result < 0) return std::strong_ordering::less;
	if (result > 0) return std::strong_ordering::greater;
	return std::strong_ordering::equal;
}
bool Registration::operator==(const Registration& other)const {
	return std::strcmp(getNumber(), other.getNumber()) == 0;
}

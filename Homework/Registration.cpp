#include "Registration.h"

Registration::Registration(char* _number)
{
	if (check() && _number!=nullptr) {
		number = new char[strlen(_number)](*_number);

	}
}

Registration::Registration(const Registration& other)
{
	if (other.number != nullptr) {
		copyFrom(other);
	}
}

void Registration::copyFrom(const Registration& other) {
	if (other.number != nullptr && other.check())
	{
		
	}
}


void Registration::print()
{
	for (int i = 0;i < strlen(number);i++) {
		std::cout << number[i];
	}
}

void Registration::free()
{
	delete[] number;
	number = nullptr;
}

Registration::~Registration()
{
	free();
}

bool Registration::operator==(const Registration& other)
{
	int minNum = std::min(strlen(number), strlen(other.number));
	for (int i = 0;i < minNum;i++) {
		if (number > other.number) {
			return 1;
		}
	}
	if (strlen(number) > strlen(other.number)) {
		return 1;
	}
	return 0;
}

std::strong_ordering Registration::operator<=>(const Registration& other)
{
	std::strong_ordering cmp;
	int minNum = std::min(strlen(number), strlen(other.number));
	for (int i = 0;i < minNum;i++) {
		cmp = number <=> other.number;
	}
	if (cmp == 0) {
		cmp = strlen(number) <=> strlen(other.number);
	}
	return cmp;


}

bool Registration::check() const
{
	if (strlen(number) == 5) {
		for (int i = 0;i < 6;i++) {
			if (i < 1) {
				if (number[i] <= 'A' && number[i] >= 'Z') {
					return false;
				}

			}
			if (i >= 1 && i < 3) {
				if (number[i] <= 0 && number[i] >= 9) {
					return false;
				}

			}
			if (i >= 3 && i < 5) {
				if (number[i] <= 'A' && number[i] >= 'Z') {
					return false;
				}

			}
		}
	if (strlen(number) == 6) {
		for (int i = 0;i < 6;i++) {
			if (i < 2) {
				if (number[i] <= 'A' && number[i] >= 'Z') {
					return false;
				}

			}
			if (i >=2 && i<4) {
				if (number[i] <= 0 && number[i] >= 9) {
					return false;
				}

			}
			if (i >=4 && i<6) {
				if (number[i] <= 'A' && number[i] >= 'Z') {
					return false;
				}

			}
		}
	}
	return false;
}

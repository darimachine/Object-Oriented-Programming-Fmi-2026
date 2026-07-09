#include "Registration.h"

Registration::Registration(const char* reg)
{
    if (reg == nullptr) throw std::invalid_argument("Invalid registration input.");

    int len = std::strlen(reg);
    if (len < 7 || len > 8) throw std::invalid_argument("Invalid registration input.");

    int letters = (len == 7) ? 1 : 2;
    for (int i = 0; i < letters; i++) {
        if (reg[i] < 'A' || reg[i] > 'Z') throw std::invalid_argument("Invalid registration input.");
    }

    for (int i = letters; i < letters + 4; i++) {
        if (reg[i] < '0' || reg[i] > '9') throw std::invalid_argument("Invalid registration input.");
    }

    for (int i = letters + 4; i < len; i++) {
        if (reg[i] < 'A' || reg[i] > 'Z') throw std::invalid_argument("Invalid registration input.");
    }

    std::strncpy(this->cityCode, reg, letters);
    this->cityCode[letters] = '\0';

    std::strcpy(this->full, reg);
}


std::strong_ordering Registration::operator<=>(const Registration& other) const
{
	auto cmp = std::strcmp(full, other.full);

	if (cmp < 0)
		return std::strong_ordering::less;
	if (cmp > 0)
		return std::strong_ordering::greater;

	return std::strong_ordering::equal;
}

bool Registration::operator==(const Registration& other) const
{
	auto cmp = std::strcmp(full, other.full);

	if (cmp == 0)
		return true;

	return false;
}

Registration::operator bool() const
{
	if (full == nullptr)
		return false;

	return true;
}

std::ostream& operator<<(std::ostream& os, const Registration& reg)
{
	os << "Registration: " << reg.full << "\n";
	return os;
}

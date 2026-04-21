#include "Registration.h"

auto operator<<(std::ostream& os, const Registration& registration) -> std::ostream&
{
	os << registration.m_registrationNumber;
	return os;
}

Registration::Registration(const char* registrationNumber)
{
	auto start = size_t{ 0 }, current = size_t{ 0 };

	while (registrationNumber[current] >= 'A' && registrationNumber[current] <= 'Z')
		++current;
	if (current < 1 || current > 2)
		goto INVALID;

	strncpy_s(m_areaCode, 3, registrationNumber, current);

	start = current;
	while (registrationNumber[current] >= '0' && registrationNumber[current] <= '9')
		++current;
	if (current - start != 4)
		goto INVALID;

	start = current;
	while (registrationNumber[current] >= 'A' && registrationNumber[current] <= 'Z')
		++current;
	if (current - start != 2)
		goto INVALID;

	if (registrationNumber[current] != '\0')
		goto INVALID;

	strcpy_s(m_registrationNumber, 9, registrationNumber);
	return;

INVALID:
	{
		strcpy_s(m_registrationNumber, 9, "INVALID");
		strcpy_s(m_areaCode, 3, "--");

		return;
	}
}

auto Registration::operator==(const Registration& other) const -> bool
{
	return ((*this) <=> other) == std::partial_ordering::equivalent;
}

auto Registration::c_str() const -> const char*
{
	return m_registrationNumber;
}

auto Registration::operator<=>(const Registration& other) const -> std::partial_ordering
{
	auto cmp = strcmp(this->m_registrationNumber, other.m_registrationNumber);

	if (cmp < 0)
		return std::partial_ordering::less;
	else if (cmp > 0)
		return std::partial_ordering::greater;
	else
		return std::partial_ordering::equivalent;
}

#ifndef REGISTRATION_H

#define REGISTRATION_H

#include<cstring>
#include<ostream>
#include<compare>

class Registration
{
private:
	char m_registrationNumber[9];
	char m_areaCode[3];

	friend auto operator<<(std::ostream& os, const Registration& registration) -> std::ostream&;
	friend class Vehicle;
	friend class VehicleList;
protected:
public:
	explicit Registration(const char* registrationNumber);

	auto operator<=>(const Registration& other) const->std::partial_ordering;
	auto operator==(const Registration& other) const->bool;
	auto c_str() const -> const char*;

};

#endif // !REGISTRATION_H




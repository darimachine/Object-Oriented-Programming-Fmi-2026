#pragma once
#include <iostream>

class Registration
{
private:
	static constexpr unsigned REG_NUMBER_LEN = 8;
	char* regNumber = nullptr;

	bool validateNumber(const char* regNumber) const;

	void free();
	void copyFrom(const Registration& other);
	void moveFrom(Registration&& other) noexcept;
public:
	Registration() = delete;
	Registration(const char* regNumber);
	Registration(const Registration& other);
	Registration& operator=(const Registration& other);
	Registration(Registration&& other) noexcept;
	Registration& operator=(Registration&& other) noexcept;
	~Registration();

	friend std::ostream& operator<<(std::ostream& os, const Registration& reg);
	friend bool operator<(const Registration& reg1, const Registration& reg2);
	friend bool operator==(const Registration& reg1, const Registration& reg2);
	friend bool operator>(const Registration& reg1, const Registration& reg2);

	const char* c_str() const;
};


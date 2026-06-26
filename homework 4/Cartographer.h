#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "MyException.h"
#include <iostream>
class Cartographer
{
protected:
	std::string name;
	int years;
public:
	virtual std::string getRole() const = 0;
	virtual void print() const = 0;
	std::string getName() const;
	Cartographer(const std::string& name, int years) : name(name), years(years) {}
	virtual ~Cartographer() = default;
};

class FieldSurveyor : public Cartographer {
protected:
	std::string region;
public:
	FieldSurveyor(const std::string& name, int years, const std::string& region)
		: Cartographer(name, years), region(region) {}
	std::string getRole() const override;
	void print() const override;
};

class Archivist : public Cartographer {
protected:
	std::string institution;
public:
	Archivist(const std::string& name, int years, const std::string& institution)
		: Cartographer(name, years), institution(institution) {}
	std::string getRole() const override;
	void print() const override;
};

class ExpeditionLeader : public Cartographer {
protected:
	int expeditionLed;
public:
	ExpeditionLeader(const std::string& name, int years, int expeditionLed)
		: Cartographer(name, years), expeditionLed(expeditionLed) {}
	std::string getRole() const override;
	void print() const override;
};


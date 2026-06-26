#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "MyException.h"
class Landmark;
class CommandFactory;
class Territory
{
	std::string name;
	std::vector<std::unique_ptr<Landmark>> landmarks;
public:
	void addLandmark(std::unique_ptr<Landmark> l);
	std::unique_ptr<Landmark> removeLandmark(const std::string& name);// -връща извадената забележителност; хвърля std::invalid_argument, ако не е намерена
	void setDangerLevel(int);// -ниво 1–10; хвърля std::invalid_argument, ако е невалидно
	bool hasLandmark(const std::string& name) const;
	void print() const;
	std::unique_ptr<Territory> clone() const;
	std::string getName() const;
	Territory& operator=(std::unique_ptr<Territory>);
};


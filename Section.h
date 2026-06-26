#pragma once
#include <string>
#include <vector>
#include "Exhibit.h"
#include <memory>
#include "ZooKeeper.h"
#include <iostream>

class Section {
	std::string name;
	int minExperience;
	std::vector<Exhibit> exhibits;
	std::shared_ptr<ZooKeeper> guard;

	public:
	Section(std::string name, int minExperience);

	virtual ~Section() = default;

	bool assignGuard(std::shared_ptr<ZooKeeper> g);

	void addExhibit(const Exhibit& e);

	bool hasActivteGuard() const;

	void removeGuard();

	void print() const;

	std::vector<Exhibit>& getExhibit();
};

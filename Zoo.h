#pragma once
#include"Section.h"
#include"Guard.h"
#include<memory>
#include<iostream>

class Zoo
{
private:
	vector<unique_ptr<Section>> sections;
	vector<shared_ptr<Guard>> guards;

public:
	shared_ptr<Guard> addGuard(const Guard& g);
	bool removeGuard(unsigned employeeId);

	void printAll()const;
	const Exhibit* search(const string& animalName)const;

	Section& addSection(const unique_ptr<Section>& section);
};


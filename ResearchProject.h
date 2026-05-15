#pragma once
#include"Researcher.h"
#include<vector>
#include<algorithm>

class ResearchProject
{
private:
	static constexpr double STABLE_BUDGET = 10000;
	std::string name;
	double budget;
	std::vector<std::shared_ptr<Researcher>> researchers;

	bool idExists(unsigned id)const;

public:
	ResearchProject() = delete;
	ResearchProject(const std::string& name, double budget);

	bool addResearcher(const std::shared_ptr<Researcher>& r);
	bool removeResearcher(unsigned id);

	Researcher* findResearcher(unsigned id);
	Researcher* leadResearcher()const;
	
	void publishAll();
	double totalBudgetPerResearcher()const;

	friend std::ostream& operator<<(std::ostream& os, const ResearchProject& rp);

	explicit operator bool()const;
	ResearchProject& operator()(unsigned id, const std::string& sprecialization);

	Researcher* operator[](unsigned id);
	const Researcher* operator[](unsigned id)const;
};


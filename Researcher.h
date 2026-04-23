#pragma once
#include<string>
#include<fstream>

class Researcher
{
private:
	unsigned publications;
	std::string specialization;
	static unsigned nextId;
	std::string name;
	unsigned id;

public:
	Researcher() = delete;
	Researcher(const std::string& name, const std::string& specialization,unsigned publications);

	friend std::ostream& operator<<(std::ostream& os, const Researcher& r);
	auto operator<=>(const Researcher& other)const = default;

	unsigned getId()const;
	unsigned getPublications()const;

	void addPublications();
	void setSpecialization(const std::string& specialization);
};


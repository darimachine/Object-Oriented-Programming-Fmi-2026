#pragma once
#include"Cartographer.h"

class ExpeditionLeader:public Cartographer
{
private:
	int expeditionsLed;

public:
	ExpeditionLeader() = default;
	ExpeditionLeader(const string& name, unsigned yearsExperience, int expeditionsLed);

	string getRole() const override;
	void print() const override;
	int getExpeditionsLed()const;
};


#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "MyException.h"
#include <iostream>
class Territory;

enum FeatureKind {
	Volcano, Forest, Lake, Bog, Mountain, Desert
};
class Landmark
{
protected:
	std::string name;
	std::pair<double,double> Coords;
	int threat;
public:
	virtual std::string getType() const = 0;
	virtual void print() const = 0;
	Landmark(const std::string& name, const std::pair<double, double>& Coords, int threat);
	virtual~Landmark() = default;
	virtual std::unique_ptr<Landmark> clone() const = 0;
	virtual const std::string getName() const = 0;
	virtual void setThreat(int t) = 0;
	int getThreat() const;
};

class Settlement : public Landmark {
	int population;

	// Inherited via Landmark
	std::string getType() const override;
	void print() const override;
public:
	Settlement(const std::string& name, const std::pair<double, double>& Coords, int threat, int population);

	// Inherited via Landmark
	std::unique_ptr<Landmark> clone() const override;
	const std::string getName() const override;
	void setThreat(int t) override;
};
class Dungeon :public Landmark {
	int depth;

	// Inherited via Landmark
	std::string getType() const override;
	void print() const override;
public:
	Dungeon(const std::string& name, const std::pair<double, double>& Coords, int threat, int depth);

	// Inherited via Landmark
	std::unique_ptr<Landmark> clone() const override;
	const std::string getName() const override;
	void setThreat(int t) override;
};
class NaturalFeature : public Landmark {
	FeatureKind kind;

	// Inherited via Landmark
	std::string getType() const override;
	void print() const override;
public:
	NaturalFeature(const std::string& name, const std::pair<double, double>& Coords, int threat, FeatureKind kind);

	// Inherited via Landmark
	std::unique_ptr<Landmark> clone() const override;
	const std::string getName() const override;
	void setThreat(int t) override;
};

class Ruin : public Landmark
{
	std::string civilization;

	// Inherited via Landmark
	std::string getType() const override;
	void print() const override;
public:
	Ruin(const std::string& name, const std::pair<double, double>& Coords, int threat, const std::string& civilization);

	// Inherited via Landmark
	std::unique_ptr<Landmark> clone() const override;
	const std::string getName() const override;
	void setThreat(int t) override;
};

class LandmarkFactory {
public: 
	static std::unique_ptr<Landmark> createLandmark(const std::string& _type,   // "settlement" | "dungeon" | "ruin" | "natural"
		const std::string& _name,
		std::pair<double, double> _coords,
		int _threat,
		const std::string& _extra = "");
};


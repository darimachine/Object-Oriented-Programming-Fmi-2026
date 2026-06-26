#include "Landmark.h"
#include "Territory.h"
std::string Settlement::getType() const
{
    return "Settlement";
}

void Settlement::print() const
{
    std::cout << "[Settlement] " << name << " | Coords: (" << Coords.first << ", " << Coords.second
              << ") | Threat: " << threat << " | Population: " << population << "\n";
}

const std::string Settlement::getName() const { return name; }
void Settlement::setThreat(int t) { threat = t; }

std::string Dungeon::getType() const
{
    return "Dungeon";
}

void Dungeon::print() const
{
    std::cout << "[Dungeon] " << name << " | Coords: (" << Coords.first << ", " << Coords.second
              << ") | Threat: " << threat << " | Depth: " << depth << "\n";
}

const std::string Dungeon::getName() const { return name; }
void Dungeon::setThreat(int t) { threat = t; }

std::string NaturalFeature::getType() const
{
    return "NaturalFeature";
}

void NaturalFeature::print() const
{
    std::cout << "[NaturalFeature] " << name << " | Coords: (" << Coords.first << ", " << Coords.second
              << ") | Threat: " << threat << "\n";
}

const std::string NaturalFeature::getName() const { return name; }
void NaturalFeature::setThreat(int t) { threat = t; }

std::string Ruin::getType() const
{
    return "Ruin";
}

void Ruin::print() const
{
    std::cout << "[Ruin] " << name << " | Coords: (" << Coords.first << ", " << Coords.second
              << ") | Threat: " << threat << " | Civilization: " << civilization << "\n";
}

const std::string Ruin::getName() const { return name; }
void Ruin::setThreat(int t) { threat = t; }

Settlement::Settlement(const std::string& name, const std::pair<double, double>& Coords, int threat, int population)
    : Landmark(name, Coords, threat), population(population)
{
}


Dungeon::Dungeon (const std::string& name, const std::pair<double, double>& Coords, int threat, int depth)
    : Landmark(name, Coords, threat), depth(depth)
{
}


Landmark::Landmark(const std::string& name, const std::pair<double, double>& Coords, int threat)
    :name(name), Coords(Coords), threat(threat)
{
}

int Landmark::getThreat() const
{
	return threat;
}

NaturalFeature::NaturalFeature(const std::string& name, const std::pair<double, double>& Coords, int threat, FeatureKind kind)
    : Landmark(name, Coords, threat), kind(kind)
{
}


Ruin::Ruin(const std::string& name, const std::pair<double, double>& Coords, int threat, const std::string& civilization)
    : Landmark(name, Coords, threat), civilization(civilization)
{
}



std::unique_ptr<Landmark> LandmarkFactory::createLandmark(const std::string& _type, const std::string& _name,
	std::pair<double, double> _coords, int _threat, const std::string& _extra)
{
	if (_type != "settlement" && _type != "dungeon" && _type != "ruin" && _type != "natural") {
		throw MyException("NotRightType");
	}
	if (_threat <= 0 || _threat > 10) {
		throw MyException("ThreatInvalid");
	}
	if (_type == "settlement") {
		return std::make_unique<Settlement>(_name, _coords, _threat, std::stoi(_extra));
	}
	if (_type == "dungeon") {
		auto lf = std::make_unique<Dungeon>(_name, _coords, _threat, std::stoi(_extra));
		return lf;
	}
	if (_type == "ruin") {
		auto lf = std::make_unique<Ruin>(_name, _coords, _threat, _extra);
		return lf;
	}
	if (_type == "natural") {
		auto lf = std::make_unique<NaturalFeature>(_name, _coords, _threat, static_cast<FeatureKind>(std::stoi(_extra)));
		return lf;
	}
	throw MyException("InvalidTypeData");
}
std::unique_ptr<Landmark> Settlement::clone() const
{
	return std::make_unique<Settlement>(name, Coords, threat, population);
}

std::unique_ptr<Landmark> Dungeon::clone() const
{
	return std::make_unique<Dungeon>(name, Coords, threat, depth);
}

std::unique_ptr<Landmark> NaturalFeature::clone() const
{
	return std::make_unique<NaturalFeature>(name, Coords, threat, kind);
}

std::unique_ptr<Landmark> Ruin::clone() const
{
	return std::make_unique<Ruin>(name, Coords, threat, civilization);
}


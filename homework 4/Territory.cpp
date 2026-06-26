#include "Territory.h"
#include "Landmark.h"
#include "Command.h"
void Territory::addLandmark(std::unique_ptr<Landmark> l)
{
	CommandFactory::createCommand("add", l->clone());
	landmarks.push_back(std::move(l));
}

std::unique_ptr<Landmark> Territory::removeLandmark(const std::string& name)
{
	for (auto it = landmarks.begin(); it != landmarks.end(); ++it) {
		if ((*it)->getName() == name) {
			auto copy = (*it)->clone();
			landmarks.erase(it);
			CommandFactory::createCommand("remove", copy->clone());
			return copy;
		}
	}
	throw MyException("RemoveLMNotPossible");
}

void Territory::setDangerLevel(int d)
{
	if (d < 0 || d>10) {
		throw MyException("ThreatInvalid");
	}
	for (const auto& i : landmarks) {
		int t = i->getThreat();
		CommandFactory::createCommand("set", {}, t);
		i->setThreat(d);
	}
}

bool Territory::hasLandmark(const std::string& name) const
{
	if (std::find_if(landmarks.begin(), landmarks.end(), [&name](const std::unique_ptr<Landmark>& LMPointer) {
		return LMPointer->getName() == name;
		}) != landmarks.end())
		return 1;
	return 0;
}

void Territory::print() const
{
	for (const auto& i : landmarks) {
		i->print();
	}
}

std::unique_ptr<Territory> Territory::clone() const
{
	auto t = std::make_unique<Territory>();
	for (const auto& i : landmarks) {
		t->landmarks.push_back(i->clone());
	}
	return t;
}

Territory& Territory::operator=(std::unique_ptr<Territory> t)
{
	int count = 0;
	for (const auto& i : t->landmarks) {
		this->landmarks[count] = i->clone();
		count++;
	}
	return (*this);
}

std::string Territory::getName() const
{
	return name;
}


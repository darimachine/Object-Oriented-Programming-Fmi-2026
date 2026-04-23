#include "Package.h"

Package::Package(const std::string& number, const std::string& receiver, double weight, Priority priority) :
	number(number), receiver(receiver), weight(weight), priority(priority) {
}

std::ostream& operator<<(std::ostream& os, const Package& package)
{
	return os << package.number << " " << package.receiver << " " << package.weight << " "
		<< Utils::convertToString(package.priority) << '\n';
}

const std::string& Package::getTrackingNumber()const
{
	return number;
}

Priority Package::getPriority()const
{
	return priority;
}

double Package::getWeight()const
{
	return weight;
}

const std::string& Package::getReceiver()const
{
	return receiver;
}

void Package::setPriority(Priority priority)
{
	this->priority = priority;
}
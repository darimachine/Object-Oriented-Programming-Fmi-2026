#include "Package.h"

Package::Package(const std::string trackingNumber, const std::string receiver, double weight, Priority priority)
    : trackingNumber(trackingNumber), receiver(receiver), weight(weight), priority(priority)
{
}

std::string Package::getTrackingNumber() const
{
    return trackingNumber;
}

std::string Package::getReceiver() const
{
    return receiver;
}

double Package::getWeight() const
{
    return weight;
}

Priority Package::getPriority() const
{
    return priority;
}

bool operator<(const Package &left, const Package &right)
{
    if (left.priority != right.priority) {
        return left.priority < right.priority;
    }
    return left.weight < right.weight;
}

bool operator>(const Package &left, const Package &right)
{
    return right < left;
}

bool operator==(const Package &left, const Package &right)
{
    return left.priority == right.priority;
}

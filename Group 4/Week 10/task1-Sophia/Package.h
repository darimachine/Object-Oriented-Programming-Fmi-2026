#pragma once
#include <iostream>
#include <string>

enum class Priority : int{
    NORMAL = 1,
    EXPRESS = 2,
    URGENT = 3
};

class Package {
    private:
        std::string trackingNumber;
        std::string receiver;
        double weight;
        Priority priority;

        Package& operator=(const Package&);
    public:
        Package() = delete;
        Package(const std::string trackingNumber, const std::string receiver, double weight, Priority priority);
        friend bool operator<(const Package& left, const Package& right);
        friend bool operator>(const Package& left, const Package& right);
        friend bool operator==(const Package& left, const Package& right);
        std::string getTrackingNumber() const;
        std::string getReceiver() const;
        double getWeight() const;
        Priority getPriority() const;
};

std::ostream& operator<<(std::ostream& os, const Package& package);

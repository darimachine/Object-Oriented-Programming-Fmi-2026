#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Landmark.h"

class Territory
{
	std::string name;
    int dangerLevel;
    std::vector<std::unique_ptr<Landmark>> landmarks;
public:
    explicit Territory(const std::string& name, int dangerLevel = 1);
    Territory(const Territory& other);
    Territory& operator=(const Territory& other);
    Territory(Territory&&) = default;
    Territory& operator=(Territory&&) = default;
    void addLandmark(std::unique_ptr<Landmark> landmark);
    std::unique_ptr<Landmark> removeLandmark(const std::string& name);
    void setDangerLevel(int level);
    bool hasLandmark(const std::string& name) const;
    void print() const;
    const std::string& getName() const;
    int getDangerLevel() const;
    const std::vector<std::unique_ptr<Landmark>>& getLandmarks() const;
};


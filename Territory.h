#pragma once
#include <iostream>
#include <vector>
#include "Landmark.h"
class Territory {
private:
    std::vector<std::unique_ptr<Landmark>> landmarks;
    int dangerLevel;

public:
    Territory(int level);
    Territory(const Territory& other);

    void addLandmark(std::unique_ptr<Landmark> l);
    std::unique_ptr<Landmark> removeLandmark(const std::string& name);
    void setDangerLevel(int level);
    int getDangerLevel() const;
    bool hasLandmark(const std::string& name) const;
    void print() const;
};
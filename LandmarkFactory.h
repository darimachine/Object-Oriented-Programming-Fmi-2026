#pragma once
#include <iostream>
#include "Landmark.h"

class LandmarkFactory{
public:
static std::unique_ptr<Landmark> create(
    const std::string& type,   // "settlement" | "dungeon" | "ruin" | "natural"
    const std::string& name,
    Coords coords,
    int threat,
    const std::string& extra = "" // population (int str) / depth (int str) / civilization / FeatureKind name
);
};
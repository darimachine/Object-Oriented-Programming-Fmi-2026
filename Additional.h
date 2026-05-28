#pragma once
#include <string>

struct Coords {
    double x;
    double y;
};

enum class FeatureKind {
    Volcano,
    Forest,
    Lake,
    Bog,
    Mountain,
    Desert
};

std::string featureKindToString(FeatureKind kind);
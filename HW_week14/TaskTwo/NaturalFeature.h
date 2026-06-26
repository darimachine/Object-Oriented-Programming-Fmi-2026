#pragma once
#include "FeatureKind.h"
#include <memory>
#include "Landmark.h"
class NaturalFeature : public Landmark
{
private:
    FeatureKind kind;
public:
    NaturalFeature(const std::string& name, Coords coords, int threat, FeatureKind kind);
    std::string getType() const override;
    void print() const override;
    std::unique_ptr<Landmark> clone() const override;
};


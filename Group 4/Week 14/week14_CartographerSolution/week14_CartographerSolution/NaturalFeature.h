#pragma once
#include "Landmark.h"

class NaturalFeature : public Landmark
{
public:

	enum class FeatureKind
	{
		Volcano,
		Forest,
		Lake,
		Bog,
		Mountain,
		Desert,
		Unknown
	};

	static std::string kindToString(FeatureKind kind);
	static FeatureKind stringToKind(const std::string& kindString);

	NaturalFeature() = default;
	NaturalFeature(std::string name, const double x, const double y,
		const short threatLevel, FeatureKind kind);

	virtual std::string getType() const override;
	virtual void print() const override;
	virtual std::unique_ptr<Landmark> clone() override;

private:
	FeatureKind kind = FeatureKind::Unknown;

};
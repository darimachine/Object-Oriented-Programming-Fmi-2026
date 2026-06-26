#pragma once
#include "Landmark.h"
#include "FeatureKind.h"
class NaturalFeature : public Landmark
{
	private:
		FeatureKind kind;

	public:
		NaturalFeature(const std::string& inpName, const Coordinates& inpCoords, unsigned int inpThreat,
			FeatureKind inpKind);

		std::string getType() const override;
		void print() const override;

		std::string getFeatureKindAsString() const;
};


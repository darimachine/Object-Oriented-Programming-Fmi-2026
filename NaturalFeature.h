#pragma once
#include "Landmark.h"


class NaturalFeature : public Landmark {
	FeatureKind kind;

	public:
		NaturalFeature(const std::string& name, const Coords& coords, int threat, FeatureKind kind);

		virtual std::string getType() const override;
		virtual void print() const;
		
		std::unique_ptr<Landmark> clone() const override {
			return std::make_unique<NaturalFeature>(*this);
		}
};

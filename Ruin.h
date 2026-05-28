#pragma once
#include "Landmark.h"

class Ruin : public Landmark {
	std::string civilization;

	public:
		Ruin(const std::string& name, const Coords& coords, int threat, const std::string& civilization);

		virtual std::string getType() const override;
		virtual void print() const;

		std::unique_ptr<Landmark> clone() const override {
			return std::make_unique<Ruin>(*this);
		}
};


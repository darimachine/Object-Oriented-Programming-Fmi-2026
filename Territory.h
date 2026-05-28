#pragma once
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "Landmark.h"

class Territory { 
	std::vector<std::unique_ptr<Landmark>> landmarks;
	int dangerLevel;

	public:
		Territory();
		Territory(const Territory& other);
		Territory& operator=(const Territory& other);

		~Territory() = default;
		Territory(Territory&& other) noexcept = default;
		Territory& operator=(Territory&& other) noexcept = default;

		void addLandmark(std::unique_ptr<Landmark> landmark);
		std::unique_ptr<Landmark> removeLandmark(const std::string& name);

		void setDangerLevel(int level);
		int getDangerLevel() const;
		bool hasLandmark(const std::string& name) const;
		void print() const;
};

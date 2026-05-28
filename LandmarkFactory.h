#pragma once
#include <memory>
#include <string>
#include "Landmark.h"

class LandmarkFactory {
	public:
        static std::unique_ptr<Landmark> create(
            const std::string& type,
            const std::string& name,
            Coords coords,
            int threat,
            const std::string& extra = ""
        );
};

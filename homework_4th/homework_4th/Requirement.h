#pragma once

#include <optional>
#include <string>
#include "Student.h"
#include <memory>
class Requirement
{
	public:
		virtual std::optional<std::string> check(const Student& s) const = 0;
		virtual std::unique_ptr<Requirement> clone() const = 0;
		virtual ~Requirement() = default;
};
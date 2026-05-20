#pragma once
#include <cmath>

enum class ErrorCode {
	OK,
	NotFound,
	Duplicate,
	InvalidInput,
	Full
};

inline bool salaryEqual(double a, double b) {
    return std::abs(a - b) < 1e-9;
}



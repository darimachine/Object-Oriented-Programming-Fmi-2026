#pragma once

enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    Full
};

static constexpr int MAX_NAME_LENGTH = 128;
static constexpr int MAX_POSITION_LENGTH = 128;
static constexpr double EPSILON = 0.000000001;
static constexpr int MAX_DEPARTMENTS = 10;
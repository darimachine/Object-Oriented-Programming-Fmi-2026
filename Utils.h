#pragma once
#include<iostream>
#include<cmath>

enum class ErrorCode
{
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    Full
};

bool isEqualSalary(double first, double second);
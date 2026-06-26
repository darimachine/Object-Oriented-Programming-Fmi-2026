#include "Utils.h"

std::string formatDouble(double value)
{
    bool negative = value < 0;

    if (negative)
    {
        value = -value;
    }

    int intPart = (int)value;
    int fracPart = (int)((value - intPart) * 100 + 0.5);

    std::string result;

    if (negative)
    {
        result += "-";
    }

    result += std::to_string(intPart);
    result += ".";

    if (fracPart < 10)
    {
        result += "0";
    }

    result += std::to_string(fracPart);

    return result;
}
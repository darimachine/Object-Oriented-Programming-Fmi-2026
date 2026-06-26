#pragma once
#include <stdexcept>
class InvalidTicketException : public std::invalid_argument
{
public:
    explicit InvalidTicketException(const std::string& message) : std::invalid_argument(message) {}
};
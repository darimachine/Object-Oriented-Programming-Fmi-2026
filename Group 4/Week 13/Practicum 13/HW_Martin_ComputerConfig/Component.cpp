#include "Component.h"

Component::Component(const std::string& ticket) : ticket(ticket) {}

const std::string Component::getTicket() const
{
    return ticket;
}


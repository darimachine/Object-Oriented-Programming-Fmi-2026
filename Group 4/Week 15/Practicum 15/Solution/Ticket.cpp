//
// Created by Boris Bozhilov on 5/30/2026.
//

#include "Ticket.h"

#include <stdexcept>
#include <iostream>

Ticket::Ticket(std::string vehicleRegistration, const double cost, std::string date) :
    vehicleRegistration(std::move(vehicleRegistration)), cost(cost), date(std::move(date)){
}

void Ticket::payTicket() {

    if (isPaid) throw std::logic_error("Ticket is already paid");

    isPaid = true;
}

bool Ticket::checkIfTicketIsPaid() const {

    return isPaid;
}

const std::string &Ticket::getRegistration() const {

    return vehicleRegistration;
}

void Ticket::print() const {

    std::cout << vehicleRegistration << ", " << cost << ", paid: " << isPaid << std::endl;
}

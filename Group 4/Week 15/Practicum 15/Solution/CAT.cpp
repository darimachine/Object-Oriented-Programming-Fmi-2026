//
// Created by Boris Bozhilov on 5/30/2026.
//

#include "CAT.h"

void CAT::addVehicle(const std::unique_ptr<Vehicle> &vehicle) {

    if (vehicle == nullptr) throw std::invalid_argument("Cannot add an empty vehicle to the list");

    vehicles.push_back(vehicle->clone());
}

void CAT::removeVehicle(const std::unique_ptr<Vehicle> &vehicle) {

    const unsigned int vehiclesSize = vehicles.size();

    for (unsigned int i = 0; i < vehiclesSize; i++) {

        if (vehicles.at(i)->getRegistration() == vehicle->getRegistration()) {

            vehicles.erase(vehicles.begin() + i);
            break;
        }
    }
}

std::optional<std::unique_ptr<Vehicle> > CAT::findVehicle(const std::string &registration) const {

    const unsigned int vehiclesSize = vehicles.size();

    for (unsigned int i = 0; i < vehiclesSize; i++) {

        if (vehicles.at(i)->getRegistration() == registration) {

            return vehicles.at(i)->clone();
        }
    }

    return std::nullopt;
}

std::optional<std::vector<std::unique_ptr<Vehicle>>> CAT::findAllVehiclesBasedOnCriteria
(const std::function<bool(const std::unique_ptr<Vehicle> &vehicle)> &criteria) const {

    const unsigned int vehiclesSize = vehicles.size();

    std::vector<std::unique_ptr<Vehicle>> vehiclesFound;

    for (unsigned int i = 0; i < vehiclesSize; i++) {

        if (criteria(vehicles.at(i))) {

            vehiclesFound.push_back(vehicles.at(i)->clone());
        }
    }

    if (vehiclesFound.empty()) return std::nullopt;
    return vehiclesFound;
}

void CAT::addTicket(const Ticket& ticket) {

    tickets.push_back(ticket);
}

void CAT::removeTicket(const unsigned int index) {

    if (index >= tickets.size()) throw std::invalid_argument("Given ticket index is out of bounds");

    tickets.erase(tickets.begin() + index);
}

std::optional<std::vector<Ticket>> CAT::getVehicleTickets(const std::string &registration) const {

    const unsigned int ticketsSize = tickets.size();

    std::vector<Ticket> vehicleTickets;

    for (unsigned int i = 0; i < ticketsSize; i++) {

        if (tickets.at(i).getRegistration() == registration) vehicleTickets.push_back(tickets.at(i));
    }

    if (vehicleTickets.empty()) return std::nullopt;
    return vehicleTickets;
}

std::optional<std::vector<Ticket>> CAT::findAllTicketsBasedOnCriteria(std::function<bool(const Ticket &ticket)> criteria) const {

    const unsigned int ticketsSize = tickets.size();

    std::vector<Ticket> vehicleTickets;

    for (unsigned int i = 0; i < ticketsSize; i++) {

        if (criteria(tickets.at(i))) vehicleTickets.push_back(tickets.at(i));
    }

    if (vehicleTickets.empty()) return std::nullopt;
    return vehicleTickets;
}

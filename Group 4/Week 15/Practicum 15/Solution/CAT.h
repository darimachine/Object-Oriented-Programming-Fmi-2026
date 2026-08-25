//
// Created by Boris Bozhilov on 5/30/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CAT_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CAT_H
#include <vector>
#include <memory>
#include <functional>
#include <optional>

#include "Ticket.h"
#include "Vehicle.h"


class CAT {

private:

    std::vector<std::unique_ptr<Vehicle>> vehicles;
    std::vector<Ticket> tickets;

public:

    CAT() = default;

    void addVehicle(const std::unique_ptr<Vehicle>& vehicle);
    void removeVehicle(const std::unique_ptr<Vehicle>& vehicle);
    std::optional<std::unique_ptr<Vehicle>> findVehicle(const std::string& registration) const;
    std::optional<std::vector<std::unique_ptr<Vehicle>>> findAllVehiclesBasedOnCriteria
        (const std::function<bool(const std::unique_ptr<Vehicle>& vehicle)> &criteria) const;

    void addTicket(const Ticket& ticket);
    void removeTicket(const unsigned int index);
    std::optional<std::vector<Ticket>> getVehicleTickets(const std::string& registration) const;
    std::optional<std::vector<Ticket>> findAllTicketsBasedOnCriteria
        (std::function<bool(const Ticket& ticket)> criteria) const;

};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CAT_H

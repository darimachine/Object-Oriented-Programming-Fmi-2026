//
// Created by Boris Bozhilov on 5/30/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_TICKET_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_TICKET_H
#include <string>


class Ticket {

private:
    std::string vehicleRegistration;
    double cost = 0;
    std::string date;
    bool isPaid = false;

public:

    Ticket() = default;
    Ticket(std::string vehicleRegistration, const double cost, std::string date);

    void payTicket();
    [[nodiscard]] bool checkIfTicketIsPaid() const;

    const std::string& getRegistration() const;

    void print() const;

};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_TICKET_H

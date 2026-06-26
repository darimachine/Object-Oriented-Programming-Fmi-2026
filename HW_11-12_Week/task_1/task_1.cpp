#include <iostream>
#include "Ticket.h"
#include <vector>
#include "StudentTicket.h"
#include "GroupTicket.h"

int main()
{
    try 
    {
        std::vector<std::unique_ptr<Ticket>> tickets;

        tickets.push_back(std::make_unique<Ticket>("Hamlet", 30.0));
        tickets.push_back(std::make_unique<StudentTicket>("Hamlet", 30.0));
        tickets.push_back(std::make_unique<GroupTicket>("Hamlet", 30.0));

        for (const auto& ticket : tickets) 
        {
            std::cout << *ticket << std::endl;
        }
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
    }
    return 0;
}

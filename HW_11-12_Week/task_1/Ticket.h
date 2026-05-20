#pragma once
#include <string>
class Ticket
{
private:
    std::string name;
    double price;
    static const double MIN_PRICE;
    static void validateName(const std::string& name);
    static void validatePrice(double price);
public:
    Ticket(const std::string& name, double price);
    Ticket(const Ticket&) = default;
    Ticket& operator=(const Ticket&) = default;
    virtual ~Ticket() = default;
    virtual std::string getType() const;
    const std::string& getName() const;
    virtual double getPrice() const;
    friend std::ostream& operator<<(std::ostream& os, const Ticket& t);
};


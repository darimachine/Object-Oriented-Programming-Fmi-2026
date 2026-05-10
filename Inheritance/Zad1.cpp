#include <iostream>
#include <string>

class Ticket {
protected:
    std::string show;
    double price{};

public:
    Ticket(const std::string& show, double price) : show(show), price(price) {
    }

    void print() const {
        std::cout << "Билет: \"" << show << "\", Цена: " << price << " лв.\n";
    }
};

class StudentTicket : public Ticket {
public:
    StudentTicket(const std::string& show, double originalPrice) : Ticket(show, originalPrice / 2) {
    }

    void print() const {
        std::cout << "Студентски билет: \"" << show << "\", Цена: " << price << " лв.\n";
    }

};

class GroupTicket : public Ticket {
public:
    GroupTicket(const std::string& show, double originalPrice) : Ticket(show, originalPrice * 0.8) {
    }

    void print() const {
        std::cout << "Групов билет: \"" << show << "\", Цена: " << price << " лв.\n";
    }

};

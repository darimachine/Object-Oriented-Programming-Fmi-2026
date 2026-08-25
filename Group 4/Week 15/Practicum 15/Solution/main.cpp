#include <iostream>

#include "Car.h"
#include "CAT.h"
#include "VehicleFactory.h"

int main() {
    VehicleFactory factory;

    VehicleConfig c1Config;
    c1Config.registration = "CT 0001 AP";
    c1Config.ownerName_CAR = "Stoyan";
    c1Config.brand_CAR = "Toyota";
    c1Config.model_CAR = "Prius";
    c1Config.year_CAR = 2013;

    VehicleConfig c2Config;
    c2Config.registration = "CT 0002 AP";
    c2Config.ownerName_CAR = "Ivan";
    c2Config.brand_CAR = "Audi";
    c2Config.model_CAR = "A3";
    c2Config.year_CAR = 2001;

    VehicleConfig m1Config;
    m1Config.registration = "M 0001 TC";
    m1Config.ownerName_MOTORCYCLE = "Petya";
    m1Config.maxSpeed_MOTORCYCLE = 140;

    VehicleConfig t1Config;
    t1Config.registration = "TM 0001";
    t1Config.mechanicsCount_TRAIN = 5;
    t1Config.wagonCount_TRAIN = 3;
    t1Config.seatsCount_TRAIN = 330;
    t1Config.standingCount_TRAIN = 45;

    std::unique_ptr<Vehicle> car1 = factory.createVehicle(Vehicle::Type::Car, c1Config);
    std::unique_ptr<Vehicle> car2 = factory.createVehicle(Vehicle::Type::Car, c2Config);
    std::unique_ptr<Vehicle> motorcycle1 = factory.createVehicle(Vehicle::Type::Motorcycle, m1Config);
    std::unique_ptr<Vehicle> train1 = factory.createVehicle(Vehicle::Type::Train, t1Config);

    CAT cat;

    cat.addVehicle(car1);
    cat.addVehicle(car2);
    cat.addVehicle(motorcycle1);
    cat.addVehicle(train1);

    cat.addTicket(Ticket("CT 0001 AP", 50, "20.02.2025"));
    cat.addTicket(Ticket("CT 0001 AP", 150, "21.02.2025"));
    cat.addTicket(Ticket("M 0001 TC", 15, "28.05.2026"));
    cat.addTicket(Ticket("TM 0001", 5000, "12.09.2018"));
    cat.addTicket(Ticket("CB 1296 XC", 25, "07.11.2024"));

    std::optional<std::unique_ptr<Vehicle>> found1 = cat.findVehicle("TM 0001");
    std::optional<std::unique_ptr<Vehicle>> found2 = cat.findVehicle("CB 1296 XC");

    if (found1.has_value()) found1.value()->print(std::cout);
    if (found2.has_value()) found2.value()->print(std::cout);

    std::optional<std::vector<Ticket>> car1Tickets = cat.getVehicleTickets("CT 0001 AP");

    if (car1Tickets.has_value()) {

        for (auto& ticket : car1Tickets.value()) {
            ticket.payTicket();
            ticket.print();
        }
    }

    std::optional<std::vector<std::unique_ptr<Vehicle>>> cars =
        cat.findAllVehiclesBasedOnCriteria([](const std::unique_ptr<Vehicle>& vehicle) {

            return dynamic_cast<Car*>(vehicle->clone().get());
        });

    if (cars) {
        for (auto& car : cars.value()) car->print(std::cout);
    }

    std::optional<std::vector<Ticket>> tickets =
        cat.findAllTicketsBasedOnCriteria([](const Ticket& ticket) {

            return !ticket.checkIfTicketIsPaid();
        });

    if (tickets) {
        for (auto& ticket : tickets.value()) ticket.print();
    }

    cat.removeVehicle(car1);
    cat.removeTicket(0);
    cat.removeTicket(1);

    std::optional<std::unique_ptr<Vehicle>> car1Found = cat.findVehicle(car1->getRegistration());
    if (!car1Found) std::cout << "car1 isn't in the list" << std::endl;


    return 0;
}

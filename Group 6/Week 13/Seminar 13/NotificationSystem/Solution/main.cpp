// NotificationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Eventy.h"
#include "Recipient.h"
#include "UserSubscriber.h"
#include "FileLogSubscriber.h"
int main()
{
    Eventy eventy;

    // Иван иска да знае за нови събития и за разпродажби на билети
    auto ivan = std::make_shared<UserSubscriber>(
        Recipient("Иван", "+359888123456"),
        std::vector<std::string>{"event_announced", "ticket_sale"}, "Eventy");

    // Мария се интересува само от отменени събития
    auto maria = std::make_shared<UserSubscriber>(
        Recipient("Мария", "maria@example.com"),
        std::vector<std::string>{"event_cancelled"}, "Eventy");

    // Петър следи само разпродажби
    auto petar = std::make_shared<UserSubscriber>(
        Recipient("Петър","@petar"),
        std::vector<std::string>{"ticket_sale"}, "Eventy");

    // Audit log — записва всичко за администраторите
    auto auditLog = std::make_shared<FileLogSubscriber>("eventy.txt");

    eventy.subscribe(ivan);
    eventy.subscribe(maria);
    eventy.subscribe(petar);
    eventy.subscribe(auditLog);

    eventy.publish("event_announced", "Концерт на Madonna в София!");
    eventy.publish("ticket_sale", "Билетите за Madonna са в продажба!");

    eventy.unsubscribe(maria);
    eventy.publish("event_cancelled", "Концертът на Coldplay е отменен.");
}



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Nightclub.h"

static void createBillFile(const char* filename, const char* content)
{
    std::ofstream f(filename);
    f << content;
}

int main()
{
    createBillFile("ivan_bill.txt",
        "Alchohols:\n"
        "black_label-2\n"
        "jameson-3\n"
        "Baloons:\n"
        "green-10\n"
        "Nargas:\n"
        "OS-queen-2\n");
    createBillFile("maria_bill.txt",
        "Alchohols:\n"
        "jameson-1\n"
        "Baloons:\n"
        "red-5\n"
        "Nargas:\n"
        "Alfa-mango-1\n");
    Nightclub club;
    club.addBaloonFromLine("green-25.6");
    club.addBaloonFromLine("red-15.0");
    club.addBaloonFromLine("white-10.0");
    club.addNargaFromLine("OS-queen-30");
    club.addNargaFromLine("Alfa-mango-35");
    club.addAlchoholFromLine("black_label-60");
    club.addAlchoholFromLine("jameson-50");
    std::cout << "Green baloon: " << (club.hasBaloon(BalloonColor::GREEN) ? "yes" : "no") << "\n";
    std::cout << "White baloon: " << (club.hasBaloon(BalloonColor::WHITE) ? "yes" : "no") << "\n";
    std::cout << "jameson: " << (club.hasAlchohol("jameson") ? "yes" : "no") << "\n";
    std::cout << "Mango narga: " << (club.hasNarga(Taste::MANGO) ? "yes" : "no") << "\n";
    club.removeBaloon(BalloonColor::WHITE);
    std::cout << "White baloon: " << (club.hasBaloon(BalloonColor::WHITE) ? "yes" : "no") << "\n";
    std::cout << "\nBills for Ivan:  " << club.getBill("ivan_bill.txt") << " lv.\n";
    std::cout << "Bills for Maria: " << club.getBill("maria_bill.txt") << " lv.\n";
    Client clients[2] = 
    {
        Client("Ivan",  "ivan_bill.txt"),
        Client("Maria", "maria_bill.txt")
    };
    club.dailyProfit(clients, 2);
}
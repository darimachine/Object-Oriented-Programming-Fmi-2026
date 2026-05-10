
#include <iostream>
#include "MarketPlace.h"
using namespace std;

int main()
{
    Merchant m1("Иван", 1000, 200); // (име, id, приходи, дневна ставка)
    Merchant m2("Мария", 1500, 300);
    Merchant m3("Петър", 800, 150);
    ++m1; // приключва ден → приходи: 1200
    m2++; // postfix — стойността преди увеличението
    std::cout << m1 << "\n";
    MarketPlace market("Централен пазар", 3, 400);
    market += m1;
    market += m2;
    market += m3;
    std::cout << market << "\n";
    // Централен пазар (наем: 400)
    // [1] [2] [3]
    std::cout << market.takenSlots() << "\n"; // 3
    std::cout << market.getProfit() << "\n"; // 2300
    std::cout << market.averageProfit() << "\n"; // ~766.67
    if (market) std::cout << "Пазарът е жизнеспособен\n";
    market(5); // симулира 5 дни за всички търговци
    market(3)(2); // верижно — 3 дни, после още 2
    MarketPlace market2("Южен пазар", 3, 350);
    market2 += m2;
    std::cout << (market > market2 ? "Централен е по-добър" : "Южен е по-добър");
}



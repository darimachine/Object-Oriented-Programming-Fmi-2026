#include <iostream>
#include "Player.h"
#include "Guest.h"
#include "LoggedPlayer.h"
#include "PremiumPlayer.h"

int main()
{
    Player p;

    p.addPoints(300);
    std::cout << "Player levelUp: " << p.levelUp() << "\n";
    std::cout << "Player stars: " << (int)p.getStars() << "\n";
    std::cout << "Player points: " << p.getPoints() << "\n\n";

    Guest g;

    g.addPoints(1000);
    std::cout << "Guest levelUp: " << g.levelUp() << "\n";
    std::cout << "Guest stars: " << (int)g.getStars() << "\n\n";

    LoggedPlayer lp("pass123");

    try
    {
        LoggedPlayer tmp("verylongpassword");
        std::cout << "LoggedPlayer created successfully\n";
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Error creating LoggedPlayer: " << e.what() << "\n";
    }

    lp.addPoints(600);
    std::cout << "\nLoggedPlayer levelUp: " << lp.levelUp() << "\n";
    std::cout << "LoggedPlayer stars: " << (int)lp.getStars() << "\n\n";

    PremiumPlayer pp("Ivan");

    pp.addPoints(800);

    std::cout << "PremiumPlayer levelUp: " << pp.levelUp() << "\n";
    std::cout << "PremiumPlayer stars: " << (int)pp.getStars() << "\n";
    std::cout << "PremiumPlayer points: " << pp.getPoints() << "\n";

    return 0;
}
#include<iostream>

#include "Player.h"
#include "Guest.h"
#include "LoggedPlayer.h"
#include "PremiumPlayer.h"

int main() {
        Player p(300);
        p.print();
        p.levelUp();
        p.print();

        std::cout << "-----------------\n";

        Guest g(1000, 60);
        g.print();
        g.levelUp();
        g.print();

        std::cout << "-----------------\n";

        LoggedPlayer lp(600, "1234");
        lp.print();
        lp.levelUp();
        lp.print();

        std::cout << "Login: " << lp.login(3, "1234") << std::endl;

        std::cout << "-----------------\n";

        PremiumPlayer pp(300, "Ivan", "pass");
        pp.print();
        pp.levelUp();
        pp.print();
        pp.levelUp();
        pp.print();

        pp.sendMessage("Hello world!");

        return 0;
}
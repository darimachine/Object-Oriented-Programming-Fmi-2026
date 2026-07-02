#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Jedi.h"
#include "JediUtils.h"
#include <istream>
#include <ostream>
#include <fstream>

int main()
{
    Jedi yoda("Yoda", 900, 1000, SaberColor::GREEN, SaberType::SINGLE_BLADED);
    Jedi anakin("Anakin Skywalker", 22, 850, SaberColor::BLUE, SaberType::SINGLE_BLADED);
    Jedi maul("Darth Maul", 32, 700, SaberColor::RED, SaberType::DOUBLE_BLADED);
    Jedi rey("Rey", 24, 800, SaberColor::YELLOW, SaberType::SINGLE_BLADED);
    Jedi kylo("Kylo Ren", 29, 750, LightSaber(SaberColor::RED, SaberType::CROSSGUARD));
    JediCollection council;
    council.addJedi(yoda);
    council.addJedi(anakin);
    council.addJedi(maul);
    council.addJedi(rey);
    council.addJedi(kylo);
    council.print();
    council.removeJedi("Darth Maul");
    council.print();

    JediData::sortByAge(council);
    council.print();

    JediData::sortByPower(council);
    council.print();

    SaberColor popColor = JediData::mostPopularSaberColor(council);
    SaberType  popType = JediData::mostPopularSaberType(council);
   
    switch (popColor)
    {
    case SaberColor::BLUE:   std::cout << "BLUE"<< std::endl;   break;
    case SaberColor::RED:    std::cout << "RED" << std::endl;    break;
    case SaberColor::GREEN:  std::cout << "GREEN" << std::endl;  break;
    case SaberColor::YELLOW: std::cout << "YELLOW" << std::endl; break;
    case SaberColor::PURPLE: std::cout << "PURPLE" << std::endl; break;
    default: break;
    }

    switch (popType) 
    {
    case SaberType::SINGLE_BLADED: std::cout << "SINGLE_BLADED"<< std::endl; break;
    case SaberType::DOUBLE_BLADED: std::cout << "DOUBLE_BLADED" << std::endl; break;
    case SaberType::CROSSGUARD:    std::cout << "CROSSGUARD" << std::endl;    break;
    default: break;
    }

    JediIO::saveToTxt(council, "jedis.txt");
    JediCollection fromTxt = JediIO::readFromTxt("jedis.txt");

    fromTxt.print();

    JediIO::saveToBinary(council, "jedis.bin");
    JediCollection fromBin = JediIO::readFromBinary("jedis.bin");
    fromBin.print();

    for (int i = 0; i < council.size(); ++i) {
        const Jedi& jedi = council.getJedi(i);
        std::cout << "Name: " << jedi.name
            << ", Age: " << jedi.age
            << ", Power: " << jedi.power
            << ", Saber: " << colorToString(jedi.saber.color)
            << " " << typeToString(jedi.saber.type)
            << std::endl;
    }
}

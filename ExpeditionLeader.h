#pragma once
#include <iostream>
#include "cartographer.h"

class ExpeditionLeader : public Cartographer {
    int expeditionsLed = 0;

public:
    ExpeditionLeader(const std::string& n, unsigned y, int led) : Cartographer(n, y), expeditionsLed(led) {
    }

    std::string getRole() const override { return "Expedition Leader"; }

    void print() const override {
        std::cout << "Expedition Leader: " << name << ", Exp: " << yearsExperience << " years, Expeditions Led: " << expeditionsLed << "\n";
    }
};
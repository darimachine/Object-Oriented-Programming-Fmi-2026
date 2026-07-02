#pragma once
#include "Baloon.h"
#include "Alchohol.h"
#include "Narga.h"

static const int MAX_BALOONS = 1024;
static const int MAX_ALCHOHOL = 512;
static const int MAX_NARGA = 256;

struct Client 
{
    char* name;
    char* billFile;

    Client();
    Client(const char* name, const char* billFile);
    Client(const Client& other);
    Client& operator=(const Client& other);
    ~Client();
};

class Nightclub
{
private:
    Baloon baloons[MAX_BALOONS]; 
    Narga nargas[MAX_NARGA];
    Alchohol alchohols[MAX_ALCHOHOL];
    int baloonCounts[MAX_BALOONS];
    int alchoholCounts[MAX_ALCHOHOL];
    int nargaCounts[MAX_NARGA];
    int baloonSize;
    int alchoholSize;  
    int nargaSize;
    int findBaloon(BalloonColor color) const;
    int findAlchohol(const char* name) const;
    int findNarga(const char* brand, Taste taste) const;
    static int  splitLine(const char* line, char tokens[][1025], int maxToken);
    static void trimInPlace(char* string);

public:
    Nightclub();
    void addBaloonFromLine(const char* line);
    void addNargaFromLine(const char* line);
    void addAlchoholFromLine(const char* line);
    void removeBaloon(BalloonColor color);
    void removeAlchohol(const char* name);
    void removeNarga(const char* brand, Taste taste);
    bool hasBaloon(BalloonColor color) const;
    bool hasAlchohol(const char* name) const;
    bool hasNarga(Taste taste) const;
    double getBill(const char* billFileName);
    void dailyProfit(Client* clients, int count);
};


#ifndef PLAYERSYSTEM_PLAYER_H
#define PLAYERSYSTEM_PLAYER_H


enum class Stars {
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,

};

class Player {
protected:
    static int nextId;
    int id;
    double points;
    Stars stars;

    static constexpr int MIN_TWO_STARS_POINTS = 256;
    static constexpr int MIN_THREE_STARS_POINTS = 512;
    static constexpr int MIN_FOUR_STARS_POINTS = 1024;
    static constexpr int MIN_FIVE_STARS_POINTS = 2048;

public:
    explicit Player(double points);

    virtual int minTwoStarsPoints() const;
    virtual int minThreeStarsPoints() const;
    virtual int minFourStarsPoints() const;
    virtual int minFiveStarsPoints() const;

    void addPoints(double points);
    virtual bool levelUp();

    virtual void print() const;

    virtual ~Player() = default;

};


#endif //PLAYERSYSTEM_PLAYER_H
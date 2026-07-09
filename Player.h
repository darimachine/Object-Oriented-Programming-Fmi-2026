#pragma once
#include"Utils.h"

class Player
{
private:
	static constexpr int POINTS_FOR_TWO_STARS = 256;
	static constexpr int POINTS_FOR_THREE_STARS = 512;
	static constexpr int POINTS_FOR_FOUR_STARS = 1024;
	static constexpr int POINTS_FOR_FIVE_STARS = 2048;

	static int nextId;
	int id;
	int points;
	Stars stars;

public:
	Player();

	int getId()const;
	int getPoints()const;
	Stars getStars()const;

	void addPoints(int points);

	virtual bool levelUp();

	virtual ~Player() = default;

protected:
	void setStars(Stars stars);
	void takePoints(int takenPoints);

};


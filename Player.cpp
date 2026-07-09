#include "Player.h"

int Player::nextId = 0;

Player::Player() :id(++nextId), points(0) , stars(Stars::ONE) {}

int Player::getId()const
{
	return id;
}

int Player::getPoints()const
{
	return points;
}

Stars Player::getStars()const
{
	return stars;
}

void Player::setStars(Stars stars)
{
	this->stars = stars;
}

bool Player::levelUp()
{
	if (stars == Stars::FIVE)
	{
		return false;
	}

	if (stars == Stars::ONE && points >= POINTS_FOR_TWO_STARS)
	{
		takePoints(POINTS_FOR_TWO_STARS);
		stars = Stars::TWO;
		return true;
	}
	else if (stars == Stars::TWO && points >= POINTS_FOR_THREE_STARS)
	{
		takePoints(POINTS_FOR_THREE_STARS);
		stars = Stars::THREE;
		return true;
	}
	else if (stars == Stars::THREE && points >= POINTS_FOR_FOUR_STARS)
	{
		takePoints(POINTS_FOR_FOUR_STARS);
		stars = Stars::FOUR;
		return true;
	}
	else if (stars == Stars::FOUR && points >= POINTS_FOR_FIVE_STARS)
	{
		takePoints(POINTS_FOR_FIVE_STARS);
		stars = Stars::FIVE;
		return true;
	}

	return false;
}

void Player::takePoints(int takenPoints)
{
	if (takenPoints > points)
	{
		return;
	}
	points -= takenPoints;
}

void Player::addPoints(int points)
{
	if (points < 0)
	{
		return;
	}
	this->points += points;
}
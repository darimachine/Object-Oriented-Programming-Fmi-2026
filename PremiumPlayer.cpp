#include "PremiumPlayer.h"

PremiumPlayer::PremiumPlayer():Player(),name(""){}

PremiumPlayer::PremiumPlayer(const std::string& name):
	Player(),name(name){ }

bool PremiumPlayer::levelUp()
{
    if (getStars() == Stars::FIVE)
    {
        return false;
    }

    if (getPoints() >= POINTS_FOR_STAR)
    {
        takePoints(POINTS_FOR_STAR);
        setStars((Stars)((int)getStars() + 1));
        return true;
    }
    return false;
}
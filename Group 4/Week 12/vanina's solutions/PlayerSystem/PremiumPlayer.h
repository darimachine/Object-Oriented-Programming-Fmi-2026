#ifndef PLAYERSYSTEM_PREMIUMPLAYER_H
#define PLAYERSYSTEM_PREMIUMPLAYER_H

#include <string>

#include "LoggedPlayer.h"

class PremiumPlayer : public LoggedPlayer {
    std::string name;

    static constexpr int MIN_STARS_POINTS = 256;

public:
    PremiumPlayer(double points, const std::string& name, const std::string& password);

    int minTwoStarsPoints() const override;
    int minThreeStarsPoints() const override;
    int minFourStarsPoints() const override;
    int minFiveStarsPoints() const override;

    void sendMessage(const std::string& message) const;

    void print() const override;
};


#endif //PLAYERSYSTEM_PREMIUMPLAYER_H
#pragma once
#include "CarPart.h"
#include "TyresLimits.h"

class Tyres : public CarPart
{
	private:
		unsigned width;
		unsigned profile;
		unsigned diametar;

		void setWidth(unsigned inpW);
		void setProfile(unsigned inpProfile);
		void setDiametar(unsigned inpDiametar);

	public:
		Tyres(const std::string& inpMname, const std::string& inpDesc,
			unsigned inpWidth, unsigned inpProfile, unsigned inpDiametar);

		void print(std::ostream& os) const override;
};


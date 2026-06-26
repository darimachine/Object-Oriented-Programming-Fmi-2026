#include "Tyres.h"
#include <stdexcept>
#include <iostream>
Tyres::Tyres(const std::string& inpMname, const std::string& inpDesc,
	unsigned inpWidth, unsigned inpProfile, unsigned inpDiametar) : CarPart(inpMname, inpDesc)
{
	setWidth(inpWidth);
	setProfile(inpProfile);
	setDiametar(inpDiametar);

}

void Tyres::print(std::ostream& os) const
{
	CarPart::print(os);
	os << width << '/' << profile << 'R' << diametar << '\n';
}

void Tyres::setWidth(unsigned inpW)
{
	if (inpW < TyresLimits::MIN_WIDTH || inpW > TyresLimits::MAX_WIDTH)
	{
		throw std::invalid_argument("The inputed tyres width is invalid");
	}
	width = inpW;
}

void Tyres::setProfile(unsigned inpProfile)
{
	if (inpProfile < TyresLimits::MIN_PROFILE || inpProfile > TyresLimits::MAX_PROFILE)
	{
		throw std::invalid_argument("The inputed tyres profile is invalid");
	}
	profile = inpProfile;
}

void Tyres::setDiametar(unsigned inpDiametar)
{
	if (inpDiametar < TyresLimits::MIN_DIAMETAR || inpDiametar > TyresLimits::MAX_DIAMETAR)
	{
		throw std::invalid_argument("The inputed tyres diametar is invalid");
	}
	diametar = inpDiametar;
}

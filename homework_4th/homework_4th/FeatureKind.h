#pragma once
#include <algorithm>
#include <cctype>
#include <stdexcept>

enum class FeatureKind
{
	VOLCANO,
	FOREST,
	LAKE,
	BOG,
	MOUNTAIN,
	DESERT
};

inline FeatureKind parseFeatureKind(std::string str)
{

	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return std::tolower(c); });

	if (str == "volcano")
	{
		return FeatureKind::VOLCANO;
	}

	else if (str == "forest")
	{
		return FeatureKind::FOREST;
	}

	else if (str == "lake")
	{
		return FeatureKind::LAKE;
	}
	
	else if (str == "bog")
	{
		return FeatureKind::BOG;
	}
	else if (str == "mountain")
	{
		return FeatureKind::MOUNTAIN;
	}
	else if (str == "desert")
	{
		return FeatureKind::DESERT;
	}
	else
	{
		throw std::invalid_argument("Unknown FeatureKind string");
	}
}
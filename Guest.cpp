#include "Guest.h"

Guest::Guest():Player(),timeForPlaying({0,0}) {}

Guest::Guest(const Time& timeForPlaying):Player(),timeForPlaying(timeForPlaying){}

bool Guest::levelUp()
{
	return false;
}
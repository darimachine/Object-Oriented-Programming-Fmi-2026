#include"Utils.h"

const std::string Utils::convertToString(Priority p)
{
	switch (p)
	{
	case Priority::NORMAL:return "normal";
	case Priority::EXPRESS:return "express";
	case Priority::URGENT:return "urgent";
	default:return"other";
	}
}
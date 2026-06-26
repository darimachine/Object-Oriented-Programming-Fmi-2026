#include "CommandFactory.h"
#include "LandmarkFactory.h"
#include "AddLandmarkCommand.h"
#include "RemoveLandmarkCommand.h"
#include "SetDangerLevelCommand.h"
#include <stdexcept>

std::unique_ptr<Command> CommandFactory::create(const std::string& type, const std::string& args, Territory& target)
{
	if (type == "add")
	{
		size_t currentPosition = 0;

		std::string landmarkType = extractNextArgumentToken(args, currentPosition);
		std::string landmarkName = extractNextArgumentToken(args, currentPosition);
		std::string xCoordinateStr = extractNextArgumentToken(args, currentPosition);
		std::string yCoordinateStr = extractNextArgumentToken(args, currentPosition);
		std::string threatLevelStr = extractNextArgumentToken(args, currentPosition);
		std::string extraArgument = extractNextArgumentToken(args, currentPosition);

		double xCoordinate = parseDoubleFromString(xCoordinateStr);
		double yCoordinate = parseDoubleFromString(yCoordinateStr);
		int threatLevel = parseIntegerFromString(threatLevelStr);

		auto landmark = LandmarkFactory::create(landmarkType, landmarkName, { xCoordinate, yCoordinate }, threatLevel, extraArgument);

		return std::make_unique<AddLandmarkCommand>(target, std::move(landmark));
	}

	if (type == "remove")
	{
		return std::make_unique<RemoveLandmarkCommand>(target, args);
	}

	if (type == "danger")
	{
		int dangerLevel = parseIntegerFromString(args);
		return std::make_unique<SetDangerLevelCommand>(target, dangerLevel);
	}

	throw std::invalid_argument("Unknown command type: " + type);
}

std::string CommandFactory::extractNextArgumentToken(const std::string& input, size_t& currentPosition)
{
	size_t nextSpacePosition = 0;
	while (currentPosition < input.size() && input[currentPosition] == ' ')
	{
		currentPosition++;
	}
	if (currentPosition >= input.size())
	{
		return "";
	}
	if (input[currentPosition] == '"')
	{
		currentPosition++;
		nextSpacePosition = input.find('"', currentPosition);

		std::string token = input.substr(currentPosition, nextSpacePosition - currentPosition);
		currentPosition = nextSpacePosition + 1;

		return token;
	}
	nextSpacePosition = input.find(' ', currentPosition);
	std::string token = input.substr(currentPosition, nextSpacePosition - currentPosition);
	if (nextSpacePosition == std::string::npos)
	{
		currentPosition = input.size();
	}
	else
	{
		currentPosition = nextSpacePosition + 1;
	}
	return token;
}

double CommandFactory::parseDoubleFromString(const std::string& numericString)
{
	double parsedValue = 0.0;
	bool isNegative = false;
	int index = 0;
	if (numericString[index] == '-')
	{
		isNegative = true;
		index++;
	}
	for (; index < (int)numericString.size() && numericString[index] != '.'; index++)
	{
		parsedValue = parsedValue * 10 + (numericString[index] - '0');
	}
	if (index < (int)numericString.size() && numericString[index] == '.')
	{
		index++;
		double fractionalMultiplier = 0.1;
		for (; index < (int)numericString.size(); index++)
		{
			parsedValue += (numericString[index] - '0') * fractionalMultiplier;
			fractionalMultiplier *= 0.1;
		}
	}
	if (isNegative)
	{
		parsedValue = -parsedValue;
	}
	return parsedValue;
}

int CommandFactory::parseIntegerFromString(const std::string& numericString)
{
	int parsedValue = 0;
	for (char digit : numericString)
	{
		if (digit < '0' || digit > '9')
		{
			break;
		}
		parsedValue = parsedValue * 10 + (digit - '0');
	}
	return parsedValue;
}

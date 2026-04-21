#pragma once
class Util
{
public:

	static bool charIsNumber(char ch);
	static bool charIsLetter(char ch);
	static bool checkNCharsIfTheyAreNumbers(const char* _chars, int n, int startIndex=0);
};


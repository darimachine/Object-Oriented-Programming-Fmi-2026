#pragma once
#include "Image.h"

class Greyscale
{
private:
	static constexpr int maxval = 255;
public:
	static void convertToGrey(const Image&);
};


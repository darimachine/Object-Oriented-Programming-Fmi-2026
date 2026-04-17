#pragma once
#include "Image.h"

class Inverted
{
private:
	static constexpr int maxval = 255;

public:
	static void Invert(const Image&);
};

